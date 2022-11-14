/*----------------------------------------------------------------
 * direction_hold
  - Use the geomagnetic sensor and PID control to keep the car head in a fixed direction (field center control)
  - Turn the trolley, the front of the car will return to its place
  - (lift the car, change the direction) press the remote control IR_KEY_PLAY_PAUSE key to reset the direction of the car
  
  a. car_control.h adds a pid-controlled head-holding movement function carMoveFieldCentric()
  b. CarBegin() contains compassBegin() and executes carResetHeading()
  c. The function carResetHeading() to reset the head angle is added to car_control.h
----------------------------------------------------------------*/

#include <Arduino.h>
#include "compass.h"
#include "car_control.h"
#include "ir_remote.h"
#include "rgb.h"

#define CAR_CALIBRATION_POWER 80

void setup() {
  Serial.begin(115200);
  SoftPWMBegin(); //init softpwm, before the motors initialization and the rgb LEDs initialization
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
    Serial.println("Reset Heading");
    carResetHeading();
  } else if (key == IR_KEY_POWER) {
    Serial.println("Stop");
    carStop();
  }

  carMoveFieldCentric(0, 0, 0);
  // delay(2);  // If the delay is too long, the PID adjustment of the car will be deteriorated, and it needs < 5ms
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
