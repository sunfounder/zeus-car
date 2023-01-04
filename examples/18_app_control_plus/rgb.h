#ifndef __RGB_H__
#define __RGB_H__

#include <Arduino.h>

/** Indicate whether RGB leds are common-anodes or not 
 * - 0 common cathode
 * - 1 common anode
*/
#define COMMON_ANODE 0

/** Set the pins of RGB leds, the order is R,G,B */
#define RGB_PINS (uint8_t[3]){12, 13, 11}

/** Initialize RGB leds */
void rgbBegin();

/** Set LED color in HEX */
void rgbWrite(uint32_t color);

/** Set LED color in 8bit R,G,B (0 ~ 255)*/
void rgbWrite(uint8_t r, uint8_t g, uint8_t b);

/** Turn odd RGB LEDs*/
void rgbOff();

#endif // __RGB_H__
