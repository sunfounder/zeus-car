#include "hc165.h"

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
