#ifndef __GRAYSCALE_H__
#define __GRAYSCALE_H__
#include <Arduino.h>

/**
 * @name Define the returned value of angle status detected by the 8-way grayscale module 
 */
#define ANGLE_N45     0
#define ANGLE_0       1
#define ANGLE_45      2
#define ANGLE_90      3
#define ANGLE_ERROR 255

/**
 * @name Define the returned value of angle offset status detected by the 8-way grayscale module 
 */
#define OFFSET_N1       0
#define OFFSET_0        1
#define OFFSET_1        2
#define OFFSET_ERROR  255

/**
 * @brief init grayscale module
 */
void gsBegin();

/**
 * @brief Read the value of 8-way grayscale module
 * 
 * @return byte eg:0b01001001
 */
byte gsRead();

/**
 * @brief Get the angle value and offset value of 8-way grayscale module
 * 
 * @return uint16_t 
 * 
 * @code {.cpp}
 * uint16_t result = gsGetAngleOffset();
 * uint8_t angleType = result >> 8 & 0xFF;
 * uint8_t offsetType = result & 0xFF;
 * @endcode
 * 
 */
uint16_t gsGetAngleOffset();

#endif // __GRAYSCALE_H__
