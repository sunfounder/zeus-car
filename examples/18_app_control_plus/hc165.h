#ifndef __HC165_H__
#define __HC165_H__
#include <Arduino.h>

/**
 * @name Define pins of the HC165 IO expansion chip
 */
#define PIN_74HC165_CP 8
#define PIN_74HC165_PL 9
#define PIN_74HC165_Q7 7

/** HC165 init */
void hc165Begin();

/**
 * @brief return IO status of HC165
 * 
 * @return uint16_t 
 */
uint16_t hc165Read();

#endif // __HC165_H__
