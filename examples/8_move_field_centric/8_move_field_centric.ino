/*******************************************************************
   move_field_centric

  Use the IR remote control to control the car
  to move or rotate in different directions.

  - Change the carMove of 5_remote_control to carMoveFieldCentric
  - Note that carMoveFieldCentric needs to run continuously in the loop to
  adjust the head direction
******************************************************************/
#include <Arduino.h>
#include <SoftPWM.h>

#include "compass.h"
#include "car_control.h"
#include "ir_remote.h"
#include "rgb.h"

#define CAR_CALIBRATION_POWER 80
#define IR_REMOTE_POWER  50

#define MODE_NONE 0
#define MODE_REMOTE_CONTROL 1
#define MODE_COMPASS_CALIBRATION 2

uint8_t currentMode = MODE_NONE;

//int16_t currentAngle = 0;
int16_t remoteAngle = 0;
int8_t remotePower = 0;
//int8_t lastRemotePower = 0;
int16_t remoteHeading = 0;
bool remoteDriftEnable = false;

extern int16_t originHeading;

void setup() {
  Serial.begin(115200);
  SoftPWMBegin(); // init softpwm, before the motors initialization and the rgb LEDs initialization
  rgbBegin();
  irBegin();
  carBegin();
}

void loop() {
  /* read IR key */
  uint8_t key = irRead();

  /* IR key handle */
  if (key == IR_KEY_POWER) {
    remoteAngle = 0;
    remotePower = 0;
    remoteHeading = 0;
    remoteDriftEnable = false;
    currentMode = MODE_NONE;
  } else if (key ==  IR_KEY_MUTE) { // compass calibration
    Serial.println("Start compass calibration ...");
    currentMode = MODE_COMPASS_CALIBRATION;
    compassCalibrateStart();
  }
  else if (key !=  IR_KEY_ERROR) {
    currentMode = MODE_REMOTE_CONTROL;
    carResetHeading();
    switch (key) {
      case IR_KEY_5:  // pause
        remoteAngle = 0;
        remotePower = 0;
        remoteHeading = 0;
        remoteDriftEnable = false;
        break;
      case IR_KEY_2:  // move towards 0 degrees
        remoteAngle = 0;
        remotePower = IR_REMOTE_POWER;
        remoteHeading = 0;
        remoteDriftEnable = false;
        break;
      case IR_KEY_3:  // move towards 45 degrees
        remoteAngle = 45;
        remotePower = IR_REMOTE_POWER;
        remoteHeading = 0;
        remoteDriftEnable = false;
        break;
      case IR_KEY_6:  // move towards 90 degrees
        remoteAngle = 90;
        remotePower = IR_REMOTE_POWER;
        remoteHeading = 0;
        remoteDriftEnable = false;
        break;
      case IR_KEY_9: // move towards 135 degrees
        remoteAngle = 135;
        remotePower = IR_REMOTE_POWER;
        remoteHeading = 0;
        remoteDriftEnable = false;
        break;
      case IR_KEY_8:  // move towards 180 degrees
        remoteAngle = 180;
        remotePower = IR_REMOTE_POWER;
        remoteHeading = 0;
        remoteDriftEnable = false;
        break;
      case IR_KEY_7:  // move towards 225 degrees
        remoteAngle = 225;
        remotePower = IR_REMOTE_POWER;
        remoteHeading = 0;
        remoteDriftEnable = false;
        break;
      case IR_KEY_4:  // move towards 270 degrees
        remoteAngle = 270;
        remotePower = IR_REMOTE_POWER;
        remoteHeading = 0;
        remoteDriftEnable = false;
        break;
      case IR_KEY_1:  // move towards 315 degrees
        remoteAngle = 315;
        remotePower = IR_REMOTE_POWER;
        remoteHeading = 0;
        remoteDriftEnable = false;
        break;
      case IR_KEY_CYCLE:  // turn left
        remoteHeading = -45;
        remoteDriftEnable = false;
        break;
      case IR_KEY_U_SD:  // turn right
        remoteHeading = 45;
        remoteDriftEnable = false;
        break;
      case IR_KEY_MINUS:  // drift left
        remoteHeading = -90;
        remoteDriftEnable = true;
        break;
      case IR_KEY_PLUS: // drift right
        remoteHeading = 90;
        remoteDriftEnable = true;
        break;
      default:
        break;
    }
  }

  /* motors move */
  switch (currentMode) {
    case MODE_REMOTE_CONTROL:
      carMoveFieldCentric(remoteAngle, remotePower, remoteHeading, remoteDriftEnable);
      break;
    case MODE_COMPASS_CALIBRATION:
      carMove(0, 0, CAR_CALIBRATION_POWER);
      compass_calibrating();
      break;
    case MODE_NONE:
      carStop();
      break;
  }
}

/* compasee calibrate */
void compass_calibrating() {
  bool changed = compassCalibrateLoop();
  if (changed) {
    rgbWrite(0, 255, 0);
    delay(20);
    rgbOff();
    Serial.println("Compass calibrating...");
  }
  if (compassCalibrateDone()) {
    currentMode = MODE_NONE;
    rgbWrite(0, 0, 255);
    delay(50);
    rgbOff();
    Serial.println("Compass calibration done!");
  }
}
