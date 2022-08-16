#ifndef __RGB_H__
#define __RGB_H__

#include <Arduino.h>

// #define COMMON_ANODE

#define RGB_PINS (uint8_t[3]){12, 13, 11}

void rgbBegin();
void rgbWrite(uint32_t color);
void rgbWrite(uint8_t r, uint8_t g, uint8_t b);
void rgbOff();

#endif // __RGB_H__

