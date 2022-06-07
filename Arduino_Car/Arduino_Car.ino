
#include "Arduino.h"
#include "Arduino_Car.h"
#include "car_control.h"
#include "ir_remote.h"
#include "ai_camera.h"
#include <SoftPWM.h>
#include "hc165.h"
#include "ir_obstacle.h"
#include "grayscale.h"
#include "ultrasonic.h"

#define LIGHT_ON true
#include "rgb.h"
#include "cmd_code_config.h"

#define LINE_FOLLOW_OFFSET_ANGLE 30

#define WIFI_MODE WIFI_MODE_AP
#define SSID "AIC_Test"
#define PASSWORD "12345678"
#define CAMERA_MODE CAMERA_MODE_STREAM
#define PORT "8765"

AiCamera aiCam = AiCamera("aiCam", "aiCam");

// Current mode of the car
uint8_t currentMode = MODE_NONE;


void setup() {
  int m = millis();
  Serial.begin(115200);
  Serial.println(F("Initialzing!"));
  SoftPWMBegin();
  rgbBegin();
  rgbWrite(GREEN);
  carBegin();
  hc165Begin();
  irBegin();
  aiCam.begin(SSID, PASSWORD, WIFI_MODE, PORT, CAMERA_MODE);
  aiCam.setOnReceived(onReceive);
  while (millis() - m < 500) {
    delay(1);
  }
  Serial.println(F("GO!"));
  rgbOff();
}

int16_t currentAngle = 0;

void loop() {
  aiCam.loop();
  remoteHandler();
  modeHandler();
}

void modeHandler() {
  switch (currentMode) {
    case MODE_NONE:
      rgbWrite(MODE_NONE_COLOR);    
      break;
    case MODE_LINE_FOLLOWING:
      rgbWrite(MODE_LINE_FOLLOWING_COLOR);
      carResetHeading();
      lineFollowing();
      break;
    case MODE_ROTATE_LINE_FOLLOWING:
      rgbWrite(MODE_LINE_FOLLOWING_COLOR);
      carResetHeading();
      rotateLineFollowing();
      break;
    case MODE_OBSTACLE_FOLLOWING:
      rgbWrite(MODE_OBSTACLE_FOLLOWING_COLOR);
      obstacleFollowing();
      break;
    case MODE_OBSTACLE_AVOIDANCE:
      rgbWrite(MODE_OBSTACLE_AVOIDANCE_COLOR);
      obstacleAvoidance();
      break;
    case MODE_REMOTE_CONTROL:
      rgbWrite(MODE_REMOTE_CONTROL_COLOR);
      carMoveFieldCentric(remoteAngle, remotePower, remoteHeading, true);
      break;
    case MODE_APP_CONTROL:
      rgbWrite(MODE_APP_CONTROL_COLOR);
      carMoveFieldCentric(remoteAngle, remotePower, remoteHeading, remoteDriftEnable);
      break;
    case MODE_COMPASS_CALIBRATION:
      bool changed = compassCalibrateLoop();
      if (changed) {
        rgbWrite(GREEN);
        delay(20);
        rgbOff();
      }
      if (compassCalibrateDone()) {
        currentMode = MODE_NONE;
        carStop();
      }
    default:
      break;
  }
}

void lineFollowing() {
  uint16_t result = gsGetAngleOffset();
  uint8_t angleType = result >> 8 & 0xFF;
  uint8_t offsetType = result & 0xFF;
  int16_t angle = 0;
  int8_t offset = 0;
  switch (angleType) {
    case ANGLE_N45:   angle = -45;break;
    case ANGLE_0:     angle =   0;break;
    case ANGLE_45:    angle =  45;break;
    case ANGLE_90:    angle =  90;break;
    case ANGLE_ERROR: angle = currentAngle;break;
  }
  switch (offsetType) {
    case OFFSET_N1:    offset = -1;break;
    case OFFSET_0:     offset =  0;break;
    case OFFSET_1:     offset =  1;break;
    case OFFSET_ERROR: offset =  0;break;
  }

  int16_t deltaAngle = currentAngle - angle;
  if (deltaAngle > 90) {
    angle += 180;
    offset *= -1;
  } else if (deltaAngle < -90) {
    angle -= 180;
    offset *= -1;
  }

  currentAngle = angle;
  int16_t moveAngle = currentAngle + (offset*LINE_FOLLOW_OFFSET_ANGLE);

  carMoveFieldCentric(moveAngle, CAR_DEFAULT_POWER, 0, false);
}

// Field centric angle
int16_t fcAngle = 0;
// Robot centric angle
int16_t rcAngle = 0;
int16_t currentHeading = 0;
void rotateLineFollowing() {
  currentHeading += 1;
  if (currentHeading > 360) {
    currentHeading -= 360;
  }
  uint16_t result=gsGetAngleOffset();
  uint8_t angleType = result >> 8 & 0xFF;
  uint8_t offsetType = result & 0xFF;
  int16_t angle = 0;
  int8_t offset = 0;
  switch (angleType) {
    case ANGLE_N45:   angle = -45;break;
    case ANGLE_0:     angle =   0;break;
    case ANGLE_45:    angle =  45;break;
    case ANGLE_90:    angle =  90;break;
    case ANGLE_ERROR: angle = rcAngle;break;
  }
  switch (offsetType) {
    case OFFSET_N1:    offset = -1;break;
    case OFFSET_0:     offset =  0;break;
    case OFFSET_1:     offset =  1;break;
    case OFFSET_ERROR: offset =  0;break;
  }

  int16_t deltaAngle = rcAngle - angle;
  if (deltaAngle > 90) {
    angle += 180;
    offset *= -1;
  } else if (deltaAngle < -90) {
    angle -= 180;
    offset *= -1;
  }

  rcAngle = angle;
  fcAngle = rcAngle + currentHeading;
  int16_t moveAngle = fcAngle + (offset*LINE_FOLLOW_OFFSET_ANGLE);

  carMoveFieldCentric(moveAngle, CAR_DEFAULT_POWER, currentHeading);
}

void obstacleFollowing() {
  byte result = irObstacleRead();
  bool leftIsClear = result & 0b00000010;
  bool rightIsClear = result & 0b00000001;
  float usDistance = ultrasonicRead();

  if (usDistance < 10) {
    carStop();
  } else if (usDistance < 20) {
    carForward();
  } else {
    if (!leftIsClear) {
      carTurnLeft();
    } else if (!rightIsClear) {
      carTurnRight();
    } else {
      carStop();
    }
  }
}

void obstacleAvoidance() {
  byte result = irObstacleRead();
  bool leftIsClear = result & 0b00000010;
  bool rightIsClear = result & 0b00000001;
  bool middleIsClear = ultrasonicIsClear();

  if (middleIsClear && leftIsClear && rightIsClear) {
    carForward();
  } else {
    if (!leftIsClear) {
      carTurnRight();
    } else if (!rightIsClear) {
      carTurnLeft();
    }
  }
}

void remoteHandler() {
  uint8_t key = irRead();
  if (key != IR_KEY_ERROR) {
    currentState = 0;
  }
  // Serial.print("Key: 0x");
  // Serial.println(key, BIN);
  int8_t cmd_code = ir_key_2_cmd_code(key);
  if (cmd_code != -1) {
    currentMode = MODE_REMOTE_CONTROL;
    cmd_fuc_table[cmd_code]();
  }
  else{
    switch (key) {
      case IR_KEY_POWER:
        currentMode = MODE_NONE;
        carStop();
        break;
      case IR_KEY_MODE:
        break;
      case IR_KEY_MUTE:
        currentMode = MODE_COMPASS_CALIBRATION;
        carMove(0, 0, CAR_CALIBRATION_POWER);
        compassCalibrateStart();
        break;
      case IR_KEY_PLAY_PAUSE:
        currentMode = MODE_LINE_FOLLOWING;
        break;
      case IR_KEY_BACKWARD:
        currentMode = MODE_OBSTACLE_FOLLOWING;
        break;
      case IR_KEY_FORWARD:
        currentMode = MODE_OBSTACLE_AVOIDANCE;
        break;
      case IR_KEY_EQ:
        break;
      case IR_KEY_MINUS:
        // currentMode = MODE_PARALLEL_OBSTACLE_FOLLOWING;
        break;
      case IR_KEY_PLUS:
        // currentMode = MODE_PARALLEL_OBSTACLE_AVOIDANCE;
        break;
      case IR_KEY_0: // Reset origin direction
        currentMode = MODE_REMOTE_CONTROL;
        remoteAngle = 0;
        remotePower = 0;
        remoteHeading = 0;
        remoteDriftEnable = false;
        carStop();
        carResetHeading();
        break;
    }
  }
}


void onReceive(char* recvBuf, char* sendBuf) {
  // Serial.println(recvBuf);
  if (aiCam.getButton(recvBuf, REGION_I)) {
    currentMode = MODE_APP_CONTROL;
    carStop();
    carResetHeading();
    remoteHeading = 0;
    return;
  }
  uint16_t angle = aiCam.getJoystick(recvBuf, REGION_K, JOYSTICK_ANGLE);
  uint8_t power = aiCam.getJoystick(recvBuf, REGION_K, JOYSTICK_RADIUS);
  power = map(power, 0, 100, 0, CAR_DEFAULT_POWER);
  if (remoteAngle != angle) {
    currentMode = MODE_APP_CONTROL;
    remoteAngle = angle;
  }
  if (remotePower != power) {
    currentMode = MODE_APP_CONTROL;
    remotePower = power;
  }
  if (remoteDriftEnable != aiCam.getSwitch(recvBuf, REGION_J)) {
    currentMode = MODE_APP_CONTROL;
    remoteDriftEnable = !remoteDriftEnable;
    if (remoteDriftEnable) { // Drift mode
      int16_t moveHeadingR = aiCam.getJoystick(recvBuf, REGION_Q, JOYSTICK_RADIUS);
      if (moveHeadingR == 0) {
        carResetHeading();
        remoteHeading = 0;
      } else {
        remoteHeading = aiCam.getJoystick(recvBuf, REGION_Q, JOYSTICK_ANGLE);
      }
    } else {
      int16_t moveHeadingR = aiCam.getJoystick(recvBuf, REGION_Q, JOYSTICK_RADIUS);
      if (moveHeadingR != 0)
        remoteHeading = aiCam.getJoystick(recvBuf, REGION_Q, JOYSTICK_ANGLE);
    }
  }

  // speech control
  char speech_buf[20];
  aiCam.getSpeech(recvBuf, REGION_Z, speech_buf);
  if (strlen(speech_buf) > 0) {
    int8_t cmd_code = text_2_cmd_code(speech_buf);
    // Serial.print(F("Cmd code: "));
    // Serial.println(cmd_code);
    if (cmd_code != -1) {
      currentMode = MODE_APP_CONTROL;
      cmd_fuc_table[cmd_code]();
    }
  }

}

