#ifndef _TEST_H_
#define _TEST_H_

#include "Arduino.h"
#include "car_control.h"
#include "ir_remote.h"
#include <SoftPWM.h>
#include "hc165.h"
#include "ir_obstacle.h"
#include "grayscale.h"
#include "ultrasonic.h"
#include "rgb.h"

void rgb_test() {
  rgbWrite(RED);
  delay(1000);
  rgbWrite(GREEN);
  delay(1000);
  rgbWrite(BLUE);
  delay(1000); 
}

void grayscale_test() {
  int angle = 0;
  uint16_t result = gsGetAngleOffset();
  uint8_t angleType = result >> 8 & 0xFF;
  uint8_t offsetType = result & 0xFF;
  // Serial.print("angleType: ");
  // Serial.print(angleType);
  // Serial.print(", offsetType: ");
  // Serial.println(offsetType);
  // delay(200);

  byte data = gsRead();
  Serial.print("data: ");Serial.print(data, BIN);

  switch (angleType) {
    case ANGLE_N45:   angle = -45;break;
    case ANGLE_0:     angle =   0;break;
    case ANGLE_45:    angle =  45;break;
    case ANGLE_90:    angle =  90;break;
    // case ANGLE_ERROR: angle = currentAngle;break;
  }
  Serial.print(", angle: ");Serial.println(angle);

  delay(200);

}

void ultrasonic_test() {
  rgbWrite(BLUE);
  float distance = ultrasonicRead();
  Serial.print("distance: ");
  Serial.println(distance);
  delay(100);
  rgbOff(); 
  delay(500);
}

void ir_obstacle_test() {
  // uint16_t result = hc165Read();
  // Serial.println(result, BIN);
  byte result = irObstacleRead();
  bool leftIsClear = result & 0b00000001;
  bool rightIsClear = result & 0b00000010;
  Serial.print(leftIsClear);
  Serial.print(", ");
  Serial.println(rightIsClear);
  delay(100);
}

void compass_test(){

  int16_t result = compassGetAzimuth();
  Serial.println(result);
  delay(200);
}

void ir_remote_test() {
  uint8_t result = irRead();
  if (result != IR_KEY_ERROR) {
    Serial.print("result: ");
    Serial.println(result, HEX);
  }
  delay(100);
}

#endif // TEST_H_INCLUDED
