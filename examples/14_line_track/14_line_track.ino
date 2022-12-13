/*******************************************************************
 * line_track_v2 (turn the head of the car)
 
  Use the eight-way grayscale module to trace the line
  
  - Before use, you need to adjust the potentiometer on the expansion board 
  to calibrate the grayscale module

******************************************************************/
#include <Arduino.h>
#include "car_control.h"
#include "grayscale.h"

#define LINE_TRACK_POWER 30
#define LINE_TRACK_OFFSET_ANGLE 20

int16_t currentAngle = 0;
extern int16_t originHeading;

void setup() {
  Serial.begin(115200);
  carBegin();
  gsBegin();
}

void loop() {
  line_track();
  // delay(2);
}

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

  currentAngle = angle + (offset*LINE_TRACK_OFFSET_ANGLE);
  // originHeading = currentAngle;
  // carMoveFieldCentric(0, LINE_TRACK_POWER, 0, false);

  if (currentAngle > 10) {
    carMove(0, LINE_TRACK_POWER, -45, false);
  } else if (currentAngle < -10) {
    carMove(0, LINE_TRACK_POWER, 45, false);
  } else {
    carForward(LINE_TRACK_POWER);
  }
}
