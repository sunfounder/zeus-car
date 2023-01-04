/*******************************************************************
 * APP control Plus
 
  Use esp32-cam to communicate with the app via wifi to control the car
  
* 1. Based on APP control
  * - Added compass calibration, reset head, drift switch, stop,
  * - Added function switches for line track, obstacle avoidance, and follow
  * - Added indicator light to indicate the status in different modes

******************************************************************/
#include <Arduino.h>
#include "rgb.h"
#include "compass.h"
#include "car_control.h"
#include "ai_camera.h"
#include "common_definition.h"
#include "ir_obstacle.h"
#include "grayscale.h"
#include "ultrasonic.h"


/** Configure Wifi AP mode，SSID, password*/
#define WIFI_MODE WIFI_MODE_AP
#define SSID "Zeus_Car"
#define PASSWORD "12345678"

/** Configure Wifi STA mode，SSID, password*/
// #define WIFI_MODE WIFI_MODE_STA
// #define SSID "xxxxxxxxxx"
// #define PASSWORD "xxxxxxxxxx"

/** Configure product name and type*/
#define NAME "Zeus_Car"
#define TYPE "Zeus_Car"

/* Configure websockets port
 * - Sunfounder Controller APP fixed using port 8765
*/
#define PORT "8765"

/** Configure the motor power in differernt modes */
#define CAR_DEFAULT_POWER 80
#define LINE_TRACK_POWER 50
#define OBSTACLE_AVOID_POWER 80
#define OBSTACLE_FOLLOW_POWER 50
#define CAR_CALIBRATION_POWER 80

/**Configure the unit angle of line track adjustment */
#define LINE_FOLLOW_OFFSET_ANGLE 30

/** Configure the follow distance of obstacle follow */
#define FOLLOW_DISTANCE 30

/** Instantiate aicamera, a class for serial communication with ESP32-CAM */
AiCamera aiCam = AiCamera(NAME, TYPE);

/*********************** Global variables ****************************/
uint8_t currentMode = MODE_NONE;
int16_t remoteAngle;
int16_t remotePower;
int16_t remoteHeading;
int16_t remoteHeadingR;
bool remoteDriftEnable;
int16_t app_remoteAngle;
int8_t app_remotePower;
int16_t currentAngle;

/*********************** setup() & loop() ************************/
void setup() {
  int m = millis();
  Serial.begin(115200);
  Serial.println(F("Initialzing..."));

  rgbBegin();
  rgbWrite(ORANGE);
  carBegin();
  irObstacleBegin();
  gsBegin();
  
  aiCam.begin(SSID, PASSWORD, WIFI_MODE, PORT);
  aiCam.setOnReceived(onReceive);

  while (millis() - m < 500) { // Wait for peripherals to be ready
    delay(1);
  }

  Serial.println(F("Okie!"));
  rgbWrite(GREEN);
 
}


void loop() {
  aiCam.loop();
  modeHandler();
}

/***************************** Functions ******************************/
/**
 * modeHandler(), Execute the corresponding program according to the set mode
 * 
 * - inclued
 *  - MODE_NONE
 *  - MODE_LINE_TRACK
 *  - MODE_OBSTACLE_FOLLOWING
 *  - MODE_OBSTACLE_AVOIDANCE
 *  - MODE_APP_CONTROL
 *  - MODE_COMPASS_CALIBRATION
 */
void modeHandler() {
  switch (currentMode) {
    case MODE_NONE: 
      rgbWrite(MODE_NONE_COLOR);    
      break;
    case MODE_LINE_TRACK:
      rgbWrite(MODE_LINE_TRACK_COLOR);
      remotePower = LINE_TRACK_POWER;
      carResetHeading();
      line_track();
      break;
    case MODE_OBSTACLE_FOLLOWING:
      rgbWrite(MODE_OBSTACLE_FOLLOWING_COLOR);
      remotePower = OBSTACLE_FOLLOW_POWER;
      obstacleFollowing();
      break;
    case MODE_OBSTACLE_AVOIDANCE:
      rgbWrite(MODE_OBSTACLE_AVOIDANCE_COLOR);
      remotePower = OBSTACLE_AVOID_POWER;
      obstacleAvoidance();
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
      break;
    default:
      break;
  }
}

/**
 * Line track program
 */
void line_track() {
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
  if (deltaAngle > 180) {
    deltaAngle -= 360;
  } else if (deltaAngle < -180) {
    deltaAngle += 360;
  } 

  if (deltaAngle > 90) {
    angle -= 180;
    offset *= -1;
  } else if (deltaAngle < -90) {
    angle += 180;
    offset *= -1;
  }

  currentAngle = angle + (offset*LINE_FOLLOW_OFFSET_ANGLE);
  carMoveFieldCentric(currentAngle, LINE_TRACK_POWER, 0, false);

}

/**
 * Obstacle follow program
 */
void obstacleFollowing() {
  byte result = irObstacleRead();
  bool leftIsClear = result & 0b00000001;
  bool rightIsClear = result & 0b00000010;
  float usDistance = ultrasonicRead();

  if (usDistance < 10) {
    carStop();
  } else if (usDistance < 20) {
    carForward(30);
  } else if (usDistance < FOLLOW_DISTANCE) {
    carForward(OBSTACLE_FOLLOW_POWER);
  } else {
    if (!leftIsClear) {
      carTurnLeft(OBSTACLE_FOLLOW_POWER);
    } else if (!rightIsClear) {
      carTurnRight(OBSTACLE_FOLLOW_POWER);
    } else {
      carStop();
    }
  }
}

/**
 * Obstacle avoidance program
 */
void obstacleAvoidance() {
  byte result = irObstacleRead();
  bool leftIsClear = result & 0b00000001;
  bool rightIsClear = result & 0b00000010;
  bool middleIsClear = ultrasonicIsClear();

  if (middleIsClear && leftIsClear && rightIsClear) {
    carForward(OBSTACLE_AVOID_POWER);
  } else {
    if (leftIsClear) {
      carTurnLeft(OBSTACLE_AVOID_POWER);
    } else if (rightIsClear) {
      carTurnRight(OBSTACLE_AVOID_POWER);
    } else {
      carMove(0, 0, 20);
      delay(400);
      carStop();
    }
  }
}

/**
 * websocket received data processing
 */
void onReceive(char* recvBuf, char* sendBuf) {
  // Serial.print("recv:");Serial.println(recvBuf);

  // Mode select: line track, obstacle following, obstacle avoidance
  if (aiCam.getSwitch(recvBuf, REGION_N)) {
    currentMode = MODE_LINE_TRACK;
  } else if (aiCam.getSwitch(recvBuf, REGION_O)) {
    currentMode = MODE_OBSTACLE_FOLLOWING;
  } else if (aiCam.getSwitch(recvBuf, REGION_P)) {
    currentMode = MODE_OBSTACLE_AVOIDANCE;
  } else {
    if (currentMode == MODE_LINE_TRACK 
      || currentMode == MODE_OBSTACLE_FOLLOWING 
      || currentMode == MODE_OBSTACLE_AVOIDANCE){
      currentMode = MODE_NONE;
      carStop();
      carResetHeading();
      remoteHeading = 0;
      return;    
    }
  }

  // Stop
  if (aiCam.getButton(recvBuf, REGION_F)) {
    currentMode = MODE_NONE;
    carStop();
    return;
  }

  // Compass Calibrate
  if (aiCam.getButton(recvBuf, REGION_E)) {
    currentMode = MODE_COMPASS_CALIBRATION;
    carMove(0, 0, CAR_CALIBRATION_POWER); // rote to calibrate
    compassCalibrateStart();
    return;
  }

  // Reset Origin
  if (aiCam.getButton(recvBuf, REGION_I)) {
    currentMode = MODE_APP_CONTROL;
    carStop();
    carResetHeading();
    remoteHeading = 0;
    return;
  }

  //Joystick
  uint16_t angle = aiCam.getJoystick(recvBuf, REGION_K, JOYSTICK_ANGLE);
  uint8_t power = aiCam.getJoystick(recvBuf, REGION_K, JOYSTICK_RADIUS);
  power = map(power, 0, 100, 0, CAR_DEFAULT_POWER);
  if (app_remoteAngle != angle) {
    currentMode = MODE_APP_CONTROL;
    app_remoteAngle = angle;
    remoteAngle = app_remoteAngle;
  }
  if (app_remotePower != power) {
    currentMode = MODE_APP_CONTROL;
    app_remotePower = power;
    remotePower = app_remotePower;
  }

  // Drift 
  // Serial.print("Drift:");Serial.println(remoteDriftEnable);
  if (remoteDriftEnable != aiCam.getSwitch(recvBuf, REGION_J)) {
    currentMode = MODE_APP_CONTROL;
    remoteDriftEnable = !remoteDriftEnable;
  }

  // MoveHead
  int moveHeadingA = aiCam.getJoystick(recvBuf, REGION_Q, JOYSTICK_ANGLE);
  int16_t moveHeadingR = aiCam.getJoystick(recvBuf, REGION_Q, JOYSTICK_RADIUS);
  if (remoteHeading !=  moveHeadingA || remoteHeadingR !=  moveHeadingR){
    currentMode = MODE_APP_CONTROL;
    remoteHeading = moveHeadingA;
    remoteHeadingR = moveHeadingR;
    if (remoteDriftEnable && moveHeadingR == 0) { // Drift mode
      carResetHeading();
      remoteHeading = 0;
    } 
  }

}
