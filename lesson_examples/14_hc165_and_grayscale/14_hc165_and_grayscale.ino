/*******************************************************************
 * hc165_and_grayscale

  Read the value of 8-channel grayscale module

  - Due to the lack of IO, the car uses two 3-to-8 io expansion chips HC165 to connect 
  two IR obstacle avoidance modules and one 8-channel grayscale module
  - Two IR obstacle avoidance modules use the lower two io
  The 8-channel grayscale module uses the high 8-bit io

******************************************************************/
#include <Arduino.h>
#include "hc165.h"

void setup() {
  Serial.begin(115200);
  gsBegin();
}

void loop() {
  byte data = gsRead();
  /* A certain light of the module is on, the corresponding io becomes low level, and the bit value is 0 */
  Serial.print("data: ");
  if (data < 2) {
    Serial.print("0000000");Serial.println(data, BIN);
  } else if (data < 4) {
    Serial.print("000000");Serial.println(data, BIN);
  } else if (data < 8) {
    Serial.print("00000");Serial.println(data, BIN);
  } else if (data < 16) {
    Serial.print("0000");Serial.println(data, BIN);
  } else if (data < 32) {
    Serial.print("000");Serial.println(data, BIN);
  } else if (data < 64) {
    Serial.print("00");Serial.println(data, BIN);
  } else if (data < 128) {
    Serial.print("0");Serial.println(data, BIN);
  } else {
    Serial.println(data, BIN);
  }

  delay(200);
}

/**
 * @brief init grayscale module
 */
void gsBegin() {
  hc165Begin();
}

/**
 * @brief Read the value of 8-way grayscale module
 * 
 * @return byte eg:0b01001001
 */
byte gsRead() {
  uint16_t data = hc165Read();
  return data >> 8 & 0xFF;
}


