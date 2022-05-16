
#include "Arduino.h"
#include "Arduino_Car.h"
#include "car_control.h"
#include "ir_remote.h"
#include "ai_camera.h"
#include <Adafruit_NeoPixel.h>
#include "hc165.h"
#include "ir_obstacle.h"
#include "grayscale.h"
#include "ultrasonic.h"

// #define LIGHT_ON true
#define LIGHT_ON false

#define RGB_PIN 5
#define RGB_NUMS 8
#define RGB_FORMAT NEO_GRB + NEO_KHZ800

#define NORMAL_LINE_FOLLOW_POWER 30
#define NORMAL_LINE_FOLLOW_ANGLE 45

#define LINE_FOLLOW_OFFSET_ANGLE 30

// #define REMOTE_MODE_FIELD_CENTRIC
#define REMOTE_MODE_DRIFT

// Current mode of the car
uint8_t currentMode = MODE_NONE;
// State machine for almost all mode. State define see every function
uint8_t currentState = 0;
int16_t remoteAngle = 0;
int8_t remotePower = 0;
int16_t remoteHeading = 0;
bool remoteDriftEnable = false;

#define WIFI_MODE WIFI_MODE_AP
#define SSID "AIC_Test"
#define PASSWORD "12345678"
#define CAMERA_MODE CAMERA_MODE_STREAM
#define PORT "8765"

AiCamera aiCam = AiCamera("aiCam", "aiCam");
Adafruit_NeoPixel pixels(RGB_NUMS, RGB_PIN, RGB_FORMAT);

void setup() {
  int m = millis();
  Serial.begin(115200);
  pixels.begin();
  pixels.fill(GREEN);
  pixels.show();
  carBegin();
  hc165Begin();
  irBegin();
  aiCam.begin(SSID, PASSWORD, WIFI_MODE, PORT, CAMERA_MODE);
  aiCam.setOnReceived(onReceive);
  while (millis() - m < 500) {
    delay(1);
  }
  Serial.println("Start!");
  pixels.clear();
  pixels.show();
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
      #if (LIGHT_ON)
      pixels.fill(MODE_NONE_COLOR);
      pixels.show();
      #endif
      break;
    case MODE_LINE_FOLLOWING:
      #if (LIGHT_ON)
      pixels.fill(MODE_LINE_FOLLOWING_COLOR);
      pixels.show();
      #endif
      carResetHeading();
      lineFollowing();
      break;
    // case MODE_ROTATE_LINE_FOLLOWING:
    //   pixels.fill(MODE_LINE_FOLLOWING_COLOR);
    //   pixels.show();
    //   carResetHeading();
    //   rotateLineFollowing();
    //   break;
    case MODE_OBSTACLE_FOLLOWING:
      #if (LIGHT_ON)
      pixels.fill(MODE_OBSTACLE_FOLLOWING_COLOR);
      pixels.show();
      #endif
      obstacleFollowing();
      break;
    case MODE_OBSTACLE_AVOIDANCE:
      #if (LIGHT_ON)
      pixels.fill(MODE_OBSTACLE_AVOIDANCE_COLOR);
      pixels.show();
      #endif
      obstacleAvoidance();
      break;
    case MODE_REMOTE_CONTROL:
      #if (LIGHT_ON)
      pixels.fill(MODE_REMOTE_CONTROL_COLOR);
      pixels.show();
      #endif
      carMoveFieldCentric(remoteAngle, remotePower, remoteHeading, true);
      break;
    case MODE_APP_CONTROL:
      #if (LIGHT_ON)
      pixels.fill(MODE_APP_CONTROL_COLOR);
      pixels.show();
      #endif
      carMoveFieldCentric(remoteAngle, remotePower, remoteHeading, remoteDriftEnable);
      break;
    case MODE_COMPASS_CALIBRATION:
      bool changed = compassCalibrateLoop();
      #if (LIGHT_ON)
      if (changed) {
        pixels.fill(GREEN);
        pixels.show();
        delay(20);
        pixels.clear();
        pixels.show();
      }
      #endif
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

// // Field centric angle
// int16_t fcAngle = 0;
// // Robot centric angle
// int16_t rcAngle = 0;
// int16_t currentHeading = 0;
// void rotateLineFollowing() {
//   currentHeading += 1;
//   if (currentHeading > 360) {
//     currentHeading -= 360;
//   }
//   uint16_t result=gsGetAngleOffset();
//   uint8_t angleType = result >> 8 & 0xFF;
//   uint8_t offsetType = result & 0xFF;
//   int16_t angle = 0;
//   int8_t offset = 0;
//   switch (angleType) {
//     case ANGLE_N45:   angle = -45;break;
//     case ANGLE_0:     angle =   0;break;
//     case ANGLE_45:    angle =  45;break;
//     case ANGLE_90:    angle =  90;break;
//     case ANGLE_ERROR: angle = rcAngle;break;
//   }
//   switch (offsetType) {
//     case OFFSET_N1:    offset = -1;break;
//     case OFFSET_0:     offset =  0;break;
//     case OFFSET_1:     offset =  1;break;
//     case OFFSET_ERROR: offset =  0;break;
//   }

//   int16_t deltaAngle = rcAngle - angle;
//   if (deltaAngle > 90) {
//     angle += 180;
//     offset *= -1;
//   } else if (deltaAngle < -90) {
//     angle -= 180;
//     offset *= -1;
//   }

//   rcAngle = angle;
//   fcAngle = rcAngle + currentHeading;
//   int16_t moveAngle = fcAngle + (offset*LINE_FOLLOW_OFFSET_ANGLE);

//   carMoveFieldCentric(moveAngle, CAR_DEFAULT_POWER, currentHeading);
// }

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
    case IR_KEY_0:
    case IR_KEY_CYCLE:
    case IR_KEY_U_SD:
    case IR_KEY_1:
    case IR_KEY_2:
    case IR_KEY_3:
    case IR_KEY_4:
    case IR_KEY_5:
    case IR_KEY_6:
    case IR_KEY_7:
    case IR_KEY_8:
    case IR_KEY_9:
      currentMode = MODE_REMOTE_CONTROL;
      remoteControl(key);
      break;
    default:
      break;
  }
}

void remoteControl(uint8_t key) {
  switch (key) {
    case IR_KEY_0: // Reset origin direction
      currentMode = MODE_REMOTE_CONTROL;
      remoteAngle = 0;
      remotePower = 0;
      remoteHeading = 0;
      remoteDriftEnable = false;
      carStop();
      carResetHeading();
      break;
    case IR_KEY_CYCLE: // Turn Left
      #ifdef REMOTE_MODE_FIELD_CENTRIC
      remoteAngle = 0;
      remotePower = 0;
      remoteHeading -= 45;
      if (remoteHeading < -180) {
        remoteHeading += 360;
      }
      #endif
      #ifdef REMOTE_MODE_DRIFT
      remoteHeading = -90;
      remoteDriftEnable = true;
      #endif
      break;
    case IR_KEY_U_SD:  // Turn Right
      #ifdef REMOTE_MODE_FIELD_CENTRIC
      remoteAngle = 0;
      remotePower = 0;
      remoteHeading += 45;
      if (remoteHeading > 180) {
        remoteHeading -= 360;
      }
      #endif
      #ifdef REMOTE_MODE_DRIFT
      remoteHeading = 90;
      remoteDriftEnable = true;
      #endif
      break;
    case IR_KEY_1:  // Left Forward
      remoteAngle = 315;
      #ifdef REMOTE_MODE_DRIFT
      remoteHeading = 0;
      remoteDriftEnable = false;
      #endif
      remotePower = CAR_DEFAULT_POWER;
      break;
    case IR_KEY_2:  // Forward
      remoteAngle = 0;
      #ifdef REMOTE_MODE_DRIFT
      remoteHeading = 0;
      carResetHeading();
      remoteDriftEnable = false;
      #endif
      remotePower = CAR_DEFAULT_POWER;
      break;
    case IR_KEY_3:  // Right Forward
      remoteAngle = 45;
      #ifdef REMOTE_MODE_DRIFT
      remoteHeading = 0;
      remoteDriftEnable = false;
      #endif
      remotePower = CAR_DEFAULT_POWER;
      break;
    case IR_KEY_4:  // Left
      remoteAngle = 270;
      #ifdef REMOTE_MODE_DRIFT
      remoteHeading = 0;
      remoteDriftEnable = false;
      #endif
      remotePower = CAR_DEFAULT_POWER;
      break;
    case IR_KEY_5:  // Stop
      remoteAngle = 0;
      remotePower = 0;
      #ifdef REMOTE_MODE_DRIFT
      remoteHeading = 0;
      remoteDriftEnable = false;
      #endif
      carStop();
      break;
    case IR_KEY_6:  // Right
      remoteAngle = 90;
      #ifdef REMOTE_MODE_DRIFT
      remoteHeading = 0;
      remoteDriftEnable = false;
      #endif
      remotePower = CAR_DEFAULT_POWER;
      break;
    case IR_KEY_7:  // Left Backward
      remoteAngle = 225;
      #ifdef REMOTE_MODE_DRIFT
      remoteHeading = 0;
      remoteDriftEnable = false;
      #endif
      remotePower = CAR_DEFAULT_POWER;
      break;
    case IR_KEY_8:  // Backward
      remoteAngle = 180;
      #ifdef REMOTE_MODE_DRIFT
      remoteHeading = 0;
      remoteDriftEnable = false;
      carResetHeading();
      #endif
      remotePower = CAR_DEFAULT_POWER;
      break;
    case IR_KEY_9:  // Right Backward
      remoteAngle = 135;
      #ifdef REMOTE_MODE_DRIFT
      remoteHeading = 0;
      remoteDriftEnable = false;
      #endif
      remotePower = CAR_DEFAULT_POWER;
      break;
    default:
      remoteAngle = 0;
      remotePower = 0;
      remoteHeading = 0;
      remoteDriftEnable = false;
      break;
  }
}


void onReceive(char* recvBuf, char* sendBuf) {
  Serial.print("Received: ");
  Serial.println(recvBuf);
  bool power = aiCam.getSwitch(recvBuf, REGION_E);
  if (!power) {
    return;
  }
  currentMode = MODE_APP_CONTROL;
  if (aiCam.getButton(recvBuf, REGION_I)) {
    carStop();
    carResetHeading();
    remoteHeading = 0;
    return;
  }

  // Serial.print("driftEnable: ");
  bool driftEnable = aiCam.getSwitch(recvBuf, REGION_J);
  if (driftEnable) { // Drift mode
    remoteDriftEnable = true;
    remoteAngle = aiCam.getJoystick(recvBuf, REGION_K, JOYSTICK_ANGLE);
    remotePower = aiCam.getJoystick(recvBuf, REGION_K, JOYSTICK_RADIUS);
    remotePower = map(remotePower, 0, 100, 0, CAR_DEFAULT_POWER);
    int16_t moveHeadingR = aiCam.getJoystick(recvBuf, REGION_Q, JOYSTICK_RADIUS);
    if (moveHeadingR == 0) {
      carResetHeading();
      remoteHeading = 0;
    } else {
      remoteHeading = aiCam.getJoystick(recvBuf, REGION_Q, JOYSTICK_ANGLE);
    }
  } else {
    remoteDriftEnable = false;
    remoteAngle = aiCam.getJoystick(recvBuf, REGION_K, JOYSTICK_ANGLE);
    remotePower = aiCam.getJoystick(recvBuf, REGION_K, JOYSTICK_RADIUS);
    // Serial.print("Angle: ");
    // Serial.print(remoteAngle);
    // Serial.print(" Power: ");
    // Serial.println(remotePower);
    int16_t moveHeadingR = aiCam.getJoystick(recvBuf, REGION_Q, JOYSTICK_RADIUS);
    if (moveHeadingR != 0)
      remoteHeading = aiCam.getJoystick(recvBuf, REGION_Q, JOYSTICK_ANGLE);
  }
}
