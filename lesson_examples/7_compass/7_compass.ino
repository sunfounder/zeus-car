/*******************************************************************
 * compass

  Read the data of the geomagnetic sensor QMC6310
  using the i2c communication protocol

  1. Basic data reading of qmc6310 geomagnetic sensor
  2. Automatic calibration
    - Different environmental magnetic fields have different conditions, and need to be calibrated before use
    - Press the KEY_MUTE of the infrared remote control, the car will automatically calibrate and rotate continuously to obtain the range of data
    - Save the calibration value, (convenient in the same environment, no need to calibrate each time)
  3. Perform mean filtering on multiple data to reduce reading errors

******************************************************************/
#include <Arduino.h>
#include "compass.h"
#include "car_control.h"
#include "ir_remote.h"
#include "rgb.h"

#define CAR_CALIBRATION_POWER 80

void setup() {
  Serial.begin(115200);
  rgbBegin();
  irBegin();
  compassBegin();
  carBegin();
}

void loop() {
  uint8_t key = irRead();
  if (key == IR_KEY_MUTE) {
    Serial.println("Start compass calibration ...");
    delay(1000);
    compassCalibrate();
  }

  int16_t azimuth = compassReadAngle();
  Serial.print("azimuth:"); Serial.println(azimuth);

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
