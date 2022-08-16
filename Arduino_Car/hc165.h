#ifndef __HC165_H__
#define __HC165_H__
#include <Arduino.h>

#define PIN_74HC165_CP 8
#define PIN_74HC165_PL 9
#define PIN_74HC165_Q7 7

void hc165Begin();
uint16_t hc165Read();

#endif // __HC165_H__

