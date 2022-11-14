/*******************************************************************
 * move_field_centric
  
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

int16_t currentAngle = 0;
int16_t remoteAngle = 0;
int8_t remotePower = 0;
int8_t lastRemotePower = 0;
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
  switch (key) { 
    case IR_KEY_ERROR:  // no key pressed
      break;
    case IR_KEY_POWER:
      currentMode = MODE_NONE;
      remoteAngle = 0;
      remotePower = 0;
      lastRemotePower = remotePower;
      remoteHeading = 0;
      remoteDriftEnable = false;
      carStop();
      carResetHeading();
      break;
    case IR_KEY_5:  // pause
      currentMode = MODE_REMOTE_CONTROL;
      remoteAngle = 0;
      remotePower = 0;
      remoteHeading = 0;
      remoteDriftEnable = false;
      carStop();
      break;
    case IR_KEY_2:  // move towards 0 degrees
      currentMode = MODE_REMOTE_CONTROL;
      remoteAngle = 0;
      remotePower = IR_REMOTE_POWER;
      remoteHeading = 0;
      remoteDriftEnable = false;
      carResetHeading();
      break;
    case IR_KEY_3:  // move towards 45 degrees
      currentMode = MODE_REMOTE_CONTROL;
      remoteAngle = 45;
      remotePower = IR_REMOTE_POWER;
      remoteHeading = 0;
      remoteDriftEnable = false;
      carResetHeading();
      break;
    case IR_KEY_6:  // move towards 90 degrees
      currentMode = MODE_REMOTE_CONTROL;
      remoteAngle = 90;
      remotePower = IR_REMOTE_POWER;
      remoteHeading = 0;
      remoteDriftEnable = false;
      carResetHeading();
      break;
    case IR_KEY_9: // move towards 135 degrees
      currentMode = MODE_REMOTE_CONTROL;
      remoteAngle = 135;
      remotePower = IR_REMOTE_POWER;
      remoteHeading = 0;
      remoteDriftEnable = false;
      carResetHeading();
      break;
    case IR_KEY_8:  // move towards 180 degrees
      currentMode = MODE_REMOTE_CONTROL;
      remoteAngle = 180;
      remotePower = IR_REMOTE_POWER;
      remoteHeading = 0;
      remoteDriftEnable = false;
      carResetHeading();
      break;
    case IR_KEY_7:  // move towards 225 degrees
      currentMode = MODE_REMOTE_CONTROL;
      remoteAngle = 225;
      remotePower = IR_REMOTE_POWER;
      remoteHeading = 0;
      remoteDriftEnable = false;
      carResetHeading();
      break;
    case IR_KEY_4:  // move towards 270 degrees
      currentMode = MODE_REMOTE_CONTROL;
      remoteAngle = 270;
      remotePower = IR_REMOTE_POWER;
      remoteHeading = 0;
      remoteDriftEnable = false;
      carResetHeading();
      break;
    case IR_KEY_1:  // move towards 315 degrees
      currentMode = MODE_REMOTE_CONTROL;
      remoteAngle = 315;
      remotePower = IR_REMOTE_POWER;
      remoteHeading = 0;
      remoteDriftEnable = false;
      carResetHeading();
      break;
    case IR_KEY_CYCLE:  // turn left
      currentMode = MODE_REMOTE_CONTROL;
      remoteAngle = 0;
      remotePower = lastRemotePower;
      remoteHeading = -45;
      remoteDriftEnable = false;
      carResetHeading();
      break;
    case IR_KEY_U_SD:  // turn right
      currentMode = MODE_REMOTE_CONTROL;
      remoteAngle = 0;
      remotePower = lastRemotePower;
      remoteHeading = 45;
      remoteDriftEnable = false;
      carResetHeading();
      break;
    case IR_KEY_MINUS:  // drift left
      currentMode = MODE_REMOTE_CONTROL;
      remoteAngle = 0;
      remotePower = lastRemotePower;
      remoteHeading = -90;
      remoteDriftEnable = true;
      carResetHeading();
      break;
    case IR_KEY_PLUS: // drift right
      currentMode = MODE_REMOTE_CONTROL;
      remoteAngle = 0;
      remotePower = lastRemotePower;
      remoteHeading = 90;
      remoteDriftEnable = true;
      carResetHeading();
      break;
    case IR_KEY_0:  // reset heading
      currentMode = MODE_REMOTE_CONTROL;
      remoteAngle = 0;
      remotePower = 0;
      remoteHeading = 0;
      remoteDriftEnable = false;
      carStop();
      carResetHeading();
      break;
    case IR_KEY_MUTE: // compass calibration 
      Serial.println("Start compass calibration ...");
      currentMode = MODE_COMPASS_CALIBRATION;
      carMove(0, 0, CAR_CALIBRATION_POWER);
      compassCalibrateStart();
    default:
      break;
  }

  /* motors move */
  if (currentMode == MODE_REMOTE_CONTROL) {
    carMoveFieldCentric(remoteAngle, remotePower, remoteHeading, remoteDriftEnable);
    lastRemotePower = remotePower;
  } else if (currentMode == MODE_COMPASS_CALIBRATION) {
    bool changed = compassCalibrateLoop();
    if (changed) {
      rgbWrite(0, 255, 0);
      delay(20);
      rgbOff(); 
    }
    if (compassCalibrateDone()) {
      currentMode = MODE_NONE;
      carStop();
    }
    Serial.println("Compass calibration done");
  }
}
