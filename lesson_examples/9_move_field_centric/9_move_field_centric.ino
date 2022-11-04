/*******************************************************************
 * move_field_centric
  
  Use the IR remote control to control the car 
  to move or rotate in different directions.

  - Change the carMove of 5_remote_control to carMoveFieldCentric
  - Note that carMoveFieldCentric needs to run continuously in the loop to
  adjust the head direction
******************************************************************/
#include <Arduino.h>
#include "compass.h"
#include "car_control.h"
#include "ir_remote.h"
#include "rgb.h"

#define CAR_CALIBRATION_POWER 80
#define CAR_DEFAULT_POWER 80

int16_t angle = 0;
int8_t power = 0;
int16_t head_angle = 0;
bool drift = false;

extern int16_t originHeading;

void setup() {
  Serial.begin(115200);
  rgbBegin();
  irBegin();
  carBegin();
}

void loop() {
  uint8_t key = irRead();
  if (key == IR_KEY_MUTE) {
    Serial.println("Start compass calibration ...");
    compassCalibrate();
  } else if (key == IR_KEY_PLAY_PAUSE) {
    Serial.println("Reset head_angle");
    carResetHeading();
  } else if (key == IR_KEY_POWER) {
    Serial.println("Stop");
    carStop();
  }

  switch (key) {
    case IR_KEY_ERROR: 
      break;
    case IR_KEY_POWER:
    case IR_KEY_5:
      angle = 0;
      power = 0;    // power off
      head_angle = 0;
      drift = false;
      break;
    case IR_KEY_2:
      angle = 0;
      power = CAR_DEFAULT_POWER;
      head_angle = 0;
      drift = false;
      break;
    case IR_KEY_3:
      angle = 45;
      power = CAR_DEFAULT_POWER;
      head_angle = 0;
      drift = false;
      break;
    case IR_KEY_6:
      angle = 90;
      power = CAR_DEFAULT_POWER;
      head_angle = 0;
      drift = false;
      break;
    case IR_KEY_9:
      angle = 135;
      power = CAR_DEFAULT_POWER;
      head_angle = 0;
      drift = false;
      break;
    case IR_KEY_8:
      angle = 180;
      power = CAR_DEFAULT_POWER;
      head_angle = 0;
      drift = false;
      break;
    case IR_KEY_7:
      angle = 225;
      power = CAR_DEFAULT_POWER;
      head_angle = 0;
      drift = false;
      break;
    case IR_KEY_4:
      angle = 270;
      power = CAR_DEFAULT_POWER;
      head_angle = 0;
      drift = false;
      break;
    case IR_KEY_1:
      angle = 315;
      power = CAR_DEFAULT_POWER;
      head_angle = 0;
      drift = false;
      break;
    case IR_KEY_PLUS:  // turn right
      angle = 0;
      power = CAR_DEFAULT_POWER;
      head_angle = 0;
      if (originHeading > 360) originHeading = 0;
      else originHeading += 45;
      drift = false;     
      break;
    case IR_KEY_MINUS:  // turn left
      angle = 0;
      power = CAR_DEFAULT_POWER;
      head_angle = 0;
      if (originHeading < 0) originHeading = 360;
      else originHeading -= 45;
      drift = false;
      break;
    case IR_KEY_FORWARD: // drift right
      angle = 0;
      // power = CAR_DEFAULT_POWER;
      power = 0;

      head_angle = 0;
      if (originHeading > 360) originHeading = 0;
      else originHeading += 90;
      drift = true;
      break;
    case IR_KEY_BACKWARD:  // drift left
      angle = 0;
      // power = CAR_DEFAULT_POWER;
      power = 0;
      head_angle = 0;
      if (originHeading < 0) originHeading = 360;
      else originHeading -= 90;
      drift = true;
      break;
    default:
      break;
  }
  
  // originHeading

  carMoveFieldCentric(angle, power, head_angle, drift);

}

void compassCalibrate() {
  carMove(0, 0, CAR_CALIBRATION_POWER);
  compassCalibrateStart();
  while (! compassCalibrateDone()) {
    uint8_t key = irRead();
    if (key == IR_KEY_POWER) {
      break;
    }

    bool changed = compassCalibrateLoop();
    if (changed) {
        rgbWrite(0, 255, 0);
        delay(20);
        rgbOff(); 
    }
  }
  Serial.println("Compass calibration done");
  carStop();
  delay(1000);
}
