#ifndef __IR_REMOTE_H__
#define __IR_REMOTE_H__

#include <Arduino.h>

/** @name set pin of IR RECEIVER sensor*/
#define IR_RECEIVER_PIN 2

/** @name Define the code sent by the IR remote control keys
*/
//@{
#define IR_KEY_POWER 0x45
#define IR_KEY_MODE  0x46
#define IR_KEY_MUTE  0x47

#define IR_KEY_PLAY_PAUSE 0x44
#define IR_KEY_BACKWARD   0x40
#define IR_KEY_FORWARD    0x43

#define IR_KEY_EQ    0x07
#define IR_KEY_MINUS 0x15
#define IR_KEY_PLUS  0x09

#define IR_KEY_0     0x16
#define IR_KEY_CYCLE 0x19
#define IR_KEY_U_SD  0x0D

#define IR_KEY_1 0x0C
#define IR_KEY_2 0x18
#define IR_KEY_3 0x5E

#define IR_KEY_4 0x08
#define IR_KEY_5 0x1C
#define IR_KEY_6 0x5A

#define IR_KEY_7 0x42
#define IR_KEY_8 0x52
#define IR_KEY_9 0x4A

#define IR_KEY_ERROR 0x00
//@}

/**
 * @brief IRremote init
 */
void irBegin();

/**
 * @brief Read the code received by IR
 * 
 * @code {.cpp}
 * uint8_t key = irRead();
 * Serial.print('IR recv code:');
 * Serial.print(key);
 * if (key == IR_KEY_POWER) {
 *  Serial.println("IR_KEY_POWER");
 * }
 * @endcode
 * 
 * @return uint8_t 
 * 
 */
uint8_t irRead();

#endif // __IR_REMOTE_H__

