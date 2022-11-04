/*******************************************************************
 * hc165_and_ir_obstacle
  
  Read the value of two ir_obstacle

  - Due to the lack of IO, the car uses two 3-to-8 io expansion chips HC165 to connect 
  two IR obstacle avoidance modules and one 8-channel grayscale module
  - Two IR obstacle avoidance modules use the lower two io
  The 8-channel grayscale module uses the high 8-bit io

******************************************************************/
#include <Arduino.h>

/**
 * @name Define pins of the HC165 IO expansion chip
 */
#define PIN_74HC165_CP 8
#define PIN_74HC165_PL 9
#define PIN_74HC165_Q7 7

void setup() {
  Serial.begin(115200);
  irObstacleBegin();
}

void loop() {
  byte result = irObstacleRead();
  bool leftIsClear = result & 0b00000001;
  bool rightIsClear = result & 0b00000010;
  Serial.print(leftIsClear);
  Serial.print(", ");
  Serial.println(rightIsClear);
  delay(100);
}

void hc165Begin() {
  pinMode(PIN_74HC165_CP, OUTPUT);
  pinMode(PIN_74HC165_PL, OUTPUT);
  pinMode(PIN_74HC165_Q7, INPUT);
}

uint16_t hc165Read() {
  // Write pulse to load pin
  digitalWrite(PIN_74HC165_PL, LOW);
  delayMicroseconds(5);
  digitalWrite(PIN_74HC165_CP, HIGH);
  delayMicroseconds(5);
  digitalWrite(PIN_74HC165_PL, HIGH);
  delayMicroseconds(5);

  // Get data from 74HC165
  uint16_t first8 = shiftIn(PIN_74HC165_Q7, PIN_74HC165_CP, MSBFIRST);
  uint16_t last8 = shiftIn(PIN_74HC165_Q7, PIN_74HC165_CP, MSBFIRST);

  return last8 << 8 | first8;
}

void irObstacleBegin() {
  hc165Begin();
}

byte irObstacleRead() {
  return hc165Read();
}
