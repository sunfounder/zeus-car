#include "grayscale.h"
#include "hc165.h"

#define LEARNING_COUNT 64

//     ⑦ →  ⓪
//   ↗         ↘
// ⑥            ①
// ↑             ↓
// ⑤            ②
//   ↖         ↙
//     ④  ← ③

int grayscaleReference = 200;

void gsBegin() {
  hc165Begin();
}

byte gsRead() {
  uint16_t data = hc165Read();
  return data >> 8 & 0xFF;
}

// Generate by test/grayscale_pattern_classifier.py
const byte ANGLE_N45_SIZE = 33;
const byte ANGLE_N45_LIST[] = {
  0b00000001, 0b00000010, 0b00000011, 0b00000101, 0b00000111, 0b00010000, 0b00100000, 0b00101000, 
  0b00110000, 0b00111000, 0b01000100, 0b01001000, 0b01001100, 0b01010000, 0b01011000, 0b01101000, 
  0b01101100, 0b01110000, 0b01111000, 0b10000010, 0b10000011, 0b10000100, 0b10000101, 0b10000110, 
  0b10000111, 0b10001000, 0b10001100, 0b10001101, 0b11000100, 0b11000110, 0b11001000, 0b11001100, 
  0b11011000, };
const byte ANGLE_0_SIZE = 15;
const byte ANGLE_0_LIST[] = {
  0b00000110, 0b00001001, 0b00001011, 0b00001101, 0b00001111, 0b00011001, 0b01100000, 0b10001001, 
  0b10010000, 0b10010001, 0b10011000, 0b10011001, 0b10110000, 0b11010000, 0b11110000, };
const byte ANGLE_45_SIZE = 33;
const byte ANGLE_45_LIST[] = {
  0b00000100, 0b00001000, 0b00001010, 0b00001100, 0b00001110, 0b00010001, 0b00010010, 0b00010011, 
  0b00010100, 0b00010110, 0b00011010, 0b00011011, 0b00011100, 0b00011110, 0b00100001, 0b00100010, 
  0b00100011, 0b00110001, 0b00110010, 0b00110011, 0b00110110, 0b01000000, 0b01000001, 0b01100001, 
  0b01100011, 0b10000000, 0b10100000, 0b10100001, 0b10110001, 0b11000000, 0b11000001, 0b11100000, 
  0b11100001, };
const byte ANGLE_90_SIZE = 15;
const byte ANGLE_90_LIST[] = {
  0b00011000, 0b00100100, 0b00100110, 0b00101100, 0b00110100, 0b00111100, 0b01000010, 0b01000011, 
  0b01000110, 0b01100010, 0b01100100, 0b01100110, 0b10000001, 0b11000010, 0b11000011, };

const byte OFFSET_N1_SIZE = 36;
const byte OFFSET_N1_LIST[] = {
  0b00010000, 0b00100000, 0b00100001, 0b00101000, 0b00110000, 0b00111000, 0b01000000, 0b01000001, 
  0b01001000, 0b01010000, 0b01011000, 0b01100000, 0b01100001, 0b01100011, 0b01101000, 0b01101100, 
  0b01110000, 0b01111000, 0b10000000, 0b10010000, 0b10100000, 0b10100001, 0b10110000, 0b10110001, 
  0b11000000, 0b11000001, 0b11010000, 0b11011000, 0b11100000, 0b11100001, 0b11110000, 0b01000010, 
  0b01000011, 0b10000001, 0b11000010, 0b11000011, };
const byte OFFSET_0_SIZE = 24;
const byte OFFSET_0_LIST[] = {
  0b00010001, 0b00011001, 0b00100010, 0b00100110, 0b00110001, 0b00110010, 0b00110011, 0b01000100, 
  0b01000110, 0b01001100, 0b01100010, 0b01100100, 0b01100110, 0b10001000, 0b10001001, 0b10001100, 
  0b10010001, 0b10011000, 0b10011001, 0b11001000, 0b11001100, 0b00010011, 0b11000100, 0b00100011, 
};
const byte OFFSET_1_SIZE = 36;
const byte OFFSET_1_LIST[] = {
  0b00000001, 0b00000010, 0b00000011, 0b00000100, 0b00000101, 0b00000110, 0b00000111, 0b00001000, 
  0b00001001, 0b00001010, 0b00001011, 0b00001100, 0b00001101, 0b00001110, 0b00001111, 0b00010010, 
  0b00010100, 0b00010110, 0b00011010, 0b00011011, 0b00011100, 0b00011110, 0b00110110, 0b10000010, 
  0b10000011, 0b10000100, 0b10000101, 0b10000110, 0b10000111, 0b10001101, 0b11000110, 0b00011000, 
  0b00101100, 0b00110100, 0b00111100, 0b00100100, };


bool indexOf(byte* arr, byte size, byte value) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == value) return true;
  }
  return false;
}

byte gsValueRotate(byte value, int16_t angle) {
  if (angle < 0) {
    angle += 360;
  }
  if (angle > 22.5 && angle <= 67.5) {
    return (value << 1 & 0b11111110) | (value >> 7 & 0b00000001);
  } else if (angle > 67.5 && angle <= 112.5) {
    return (value << 2 & 0b11111100) | (value >> 6 & 0b00000011);
  } else if (angle > 112.5 && angle <= 157.5) {
    return (value << 3 & 0b11111000) | (value >> 5 & 0b00000111);
  } else if (angle > 157.5 && angle <= 202.5) {
    return (value << 4 & 0b11110000) | (value >> 4 & 0b00001111);
  } else if (angle > 202.5 && angle <= 247.5) {
    return (value << 5 & 0b11100000) | (value >> 3 & 0b00011111);
  } else if (angle > 247.5 && angle <= 292.5) {
    return (value << 6 & 0b11000000) | (value >> 2 & 0b00111111);
  } else if (angle > 292.5 && angle <= 337.5) {
    return (value << 7 & 0b10000000) | (value >> 1 & 0b01111111);
  } else {
    return value;
  }
}

uint16_t _gsGetAngleOffset(byte gsValues) {
  uint16_t result[2];
  if (indexOf(ANGLE_0_LIST, ANGLE_0_SIZE, gsValues)){
    result[0] = ANGLE_0;
  } else if (indexOf(ANGLE_45_LIST, ANGLE_45_SIZE, gsValues)){
    result[0] = ANGLE_45;
  } else if (indexOf(ANGLE_90_LIST, ANGLE_90_SIZE, gsValues)){
    result[0] = ANGLE_90;
  } else if (indexOf(ANGLE_N45_LIST, ANGLE_N45_SIZE, gsValues)){
    result[0] = ANGLE_N45;
  } else {
    // Serial.print("Unknown angle of pattern: "); Serial.println(gsValues, BIN);
    result[0] = ANGLE_ERROR;
  }
  
  if (indexOf(OFFSET_0_LIST, OFFSET_0_SIZE, gsValues)){
    result[1] = OFFSET_0;
  } else if (indexOf(OFFSET_1_LIST, OFFSET_1_SIZE, gsValues)){
    result[1] = OFFSET_1;
  } else if (indexOf(OFFSET_N1_LIST, OFFSET_N1_SIZE, gsValues)){
    result[1] = OFFSET_N1;
  } else {
    // Serial.print("Unknown offset of pattern: "); Serial.println(gsValues, BIN);
    result[1] = OFFSET_ERROR;
  }
  return result[0] << 8 | result[1];
}

uint16_t gsGetAngleOffset() {
  byte gsValues = gsRead();
  // Serial.print("gsValues: ");Serial.print(gsValues, BIN);
  return _gsGetAngleOffset(gsValues);
}
