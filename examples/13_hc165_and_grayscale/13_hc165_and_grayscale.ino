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
  for(int i = 7;i>=0;i--){
    if(data & (1<<i)){Serial.print("1");}
    else{Serial.print("0");}
  }
  Serial.println("");
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
