#ifndef __HC165_H__
#define __HC165_H__
#include <Arduino.h>

#define PIN_74HC165_CP A0
#define PIN_74HC165_PL A1
#define PIN_74HC165_Q7 A2
#define PIN_74HC165_CE A3

void hc165Begin();
uint16_t hc165Read();

#endif // __HC165_H__