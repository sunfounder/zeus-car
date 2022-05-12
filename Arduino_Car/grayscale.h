#ifndef __GRAYSCALE_H__
#define __GRAYSCALE_H__
#include <Arduino.h>

#define PIN_74HC165_CP A0
#define PIN_74HC165_PL A1
#define PIN_74HC165_Q7 A2
#define PIN_74HC165_CE A3

#define ANGLE_N45     0
#define ANGLE_0       1
#define ANGLE_45      2
#define ANGLE_90      3
#define ANGLE_ERROR 255

#define OFFSET_N1       0
#define OFFSET_0        1
#define OFFSET_1        2
#define OFFSET_ERROR  255

byte gsRead();
uint16_t gsGetAngleOffset();

#endif // __GRAYSCALE_H__