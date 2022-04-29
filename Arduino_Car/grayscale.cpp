#include "grayscale.h"
#include <LinearRegression.h>

LinearRegression lr = LinearRegression();

#define PIN_74HC165_CE A0
#define PIN_74HC165_CP A1
#define PIN_74HC165_PL A2
#define PIN_74HC165_Q7 A3

#define LEARNING_COUNT 64

//     3--4
//    /    \
//   2      5
//   |      |
//   1      6
//    \    /
//     0--7
// 边长为2的正8边形
// #define SENSOR_X (float[8]){-1, -1-sqrt(2), -1-sqrt(2), -1, 1, 1+sqrt(2), 1+sqrt(2), 1}
// #define SENSOR_Y (float[8]){-1-sqrt(2), -1, 1, 1+sqrt(2), 1+sqrt(2), 1, -1, -1-sqrt(2)}
#define SENSOR_ANGLES (float[8]){-157.5, -112.5, -67.5, -22.5, 22.5, 67.5, 112.5, 157.5}
#define ANGLE_AT_CIRCLE (float[8]){-67.5, -22.5, 22.5, 67.5, -22.5, -67.5, 22.5, 67.5}
#define OFFSET_AT_CIRCLE (uint8_t[8]){-1, -1, -1, -1, 1, 1, 1, 1}

int grayscaleReference = 200;

void gsBegin() {
  pinMode(PIN_74HC165_CE, OUTPUT);
  pinMode(PIN_74HC165_CP, OUTPUT);
  pinMode(PIN_74HC165_PL, OUTPUT);
  pinMode(PIN_74HC165_Q7, INPUT);
}

byte gsRead() {
  // Write pulse to load pin
  digitalWrite(PIN_74HC165_PL, LOW);
  delayMicroseconds(5);
  digitalWrite(PIN_74HC165_PL, HIGH);
  delayMicroseconds(5);

  // Get data from 74HC165
  digitalWrite(PIN_74HC165_CP, HIGH);
  digitalWrite(PIN_74HC165_CE, LOW);
  byte incoming = shiftIn(PIN_74HC165_Q7, PIN_74HC165_CP, LSBFIRST);
  digitalWrite(PIN_74HC165_CE, HIGH);

  return incoming;
}

// // Calculate Angle and Offset from sensor data base on linear regression
// void gsGetAngleOffset(int16_t currentAngle, int8_t* result) {
//   uint8_t count = 0;
//   uint8_t lastIndex = 0;
//   uint8_t lastOffset = 0;
//   lr.reset();
//   byte gsValues = gsRead();
//   // Calculate linear regression
//   for (int i = 0; i < 8; i++) {
//     byte value = gsValues >> i & 1;
//     if (value == 1) {
//       count += 1;
//       // Record last index
//       lastIndex = i;
//       // Sensors are placed around evenly in a circle, and SENSOR_ANGLES are there polar angles.
//       // We assume radius is 3. and calculate the coordinates of the sensor
//       double x = 3*sin((SENSOR_ANGLES[i] + currentAngle) * PI / 180.0);
//       double y = 3*cos((SENSOR_ANGLES[i] + currentAngle) * PI / 180.0);
//       // double x = SENSOR_X[i];
//       // double y = SENSOR_Y[i];
//       Serial.print("x: "); Serial.println(x);
//       Serial.print("y: "); Serial.println(y);
//       // Record last offset
//       if (x == 0) lastOffset = 0;
//       else if (x < 0) lastOffset = -1;
//       else lastOffset = 1;
//       // Feed data to linear regression
//       for (uint8_t i=0; i<LEARNING_COUNT; i++) {
//         lr.learn(x, y);
//       }
//     }
//   }
//   // y = ax + b
//   double values[3];
//   lr.getValues(values);
//   double a = values[0];
//   double b = values[1];
//   Serial.print("a: ");
//   Serial.println(a);
//   Serial.print("b: ");
//   Serial.println(b);

//   // if "a" is calculated error
//   if (isnan(a)) {
//     if (count == 1) {
//       // if only one sensor is detected, "a" will be error
//       result[0] = ANGLE_AT_CIRCLE[lastIndex];
//       result[1] = lastOffset;
//       return;
//     } else if (count == 2) {
//       // if two sensor is detected, and "a" is nan, than most likely, the line is vertical, as "a" will be infinity
//       result[0] = 0;
//       result[1] = lastOffset;
//       return;
//     }
//   }

//   // Calculate angle with x = 0 and x = 1
//   // x = 0:
//   //   y = a * 0 + b = b
//   // x = 1:
//   //   y = a * 1 + b = a + b
//   // deltaX = 1
//   // deltaY = a
//   // angle = atan2(deltaX / deltaY)
//   double deltaX = 1;
//   double deltaY = a;
//   double angle = atan2(deltaX, deltaY) * 180.0 / PI;
//   if (angle > 90) angle -= 180;
//   if (angle < -90) angle += 180;

//   // Calculate offset with x = 0 and y = 0
//   // x = 0:
//   //   y = a * 0 + b = b
//   // y = 0:
//   //   0 = ax + b     x = -b / a
//   // deltaX = b / a
//   // deltaY = b
//   // angle = atan2(deltaY / deltaX)
//   // Offset is the height of the triangle when slope is the base
//   // So base on triangle area formula:
//   //   area = 1/2 * base * height = 1/2 * deltaX * deltaY
//   // base is the slope
//   // height is the offset 
//   // So:
//   //   1/2 * sqrt(deltaX * deltaX + deltaY * deltaY) * offset = 1/2 * deltaX * deltaY
//   //   offset = (deltaX * deltaY) / sqrt(deltaX * deltaX + deltaY * deltaY)
//   // deltaX = b / a;
//   // deltaY = b;
//   // double offset = (deltaX * deltaY) / sqrt(deltaX * deltaX + deltaY * deltaY);

//   result[0] = round(angle);
//   if (abs(b) < 0.1) {
//     lastOffset = 0;
//   } else if (b > 0) {
//     if (a < 0){
//       lastOffset = 1;
//     } else {
//       lastOffset = -1;
//     }
//   } else {
//     if (a < 0){
//       lastOffset = -1;
//     } else {
//       lastOffset = 1;
//     }
//   }
//   result[1] = lastOffset;
// }

// Generate by test/grayscale_pattern_classifier.py
const byte ANGLE_N45_SIZE = 33;
const byte ANGLE_N45_LIST[] = {
  0b00000100, 0b00001000, 0b00001010, 0b00001100, 0b00001110, 0b00010001, 0b00010010, 0b00010011, 
  0b00010100, 0b00010110, 0b00011010, 0b00011011, 0b00011100, 0b00011110, 0b00100001, 0b00100010, 
  0b00100011, 0b00110001, 0b00110010, 0b00110011, 0b00110110, 0b01000000, 0b01000001, 0b01100001, 
  0b01100011, 0b10000000, 0b10100000, 0b10100001, 0b10110001, 0b11000000, 0b11000001, 0b11100000, 
  0b11100001, };
const byte ANGLE_0_SIZE = 15;
const byte ANGLE_0_LIST[] = {
  0b00000110, 0b00001001, 0b00001011, 0b00001101, 0b00001111, 0b00011001, 0b01100000, 0b10001001, 
  0b10010000, 0b10010001, 0b10011000, 0b10011001, 0b10110000, 0b11010000, 0b11110000, };
const byte ANGLE_45_SIZE = 34;
const byte ANGLE_45_LIST[] = {
  0b00000001, 0b00000010, 0b00000011, 0b00000101, 0b00000111, 0b00010000, 0b00100000, 0b00101000, 
  0b00101100, 0b00110000, 0b00111000, 0b01000100, 0b01001000, 0b01001100, 0b01010000, 0b01011000, 
  0b01101000, 0b01101100, 0b01110000, 0b01111000, 0b10000010, 0b10000011, 0b10000100, 0b10000101, 
  0b10000110, 0b10000111, 0b10001000, 0b10001100, 0b10001101, 0b11000100, 0b11000110, 0b11001000, 
  0b11001100, 0b11011000, };
const byte ANGLE_90_SIZE = 14;
const byte ANGLE_90_LIST[] = {
  0b00011000, 0b00100100, 0b00100110, 0b00110100, 0b00111100, 0b01000010, 0b01000011, 0b01000110, 
  0b01100010, 0b01100100, 0b01100110, 0b10000001, 0b11000010, 0b11000011, };
const byte ANGLE_IGNORE_SIZE = 160;
const byte ANGLE_IGNORE_LIST[] = {
  0b00000000, 0b00010101, 0b00010111, 0b00011101, 0b00011111, 0b00100101, 0b00100111, 0b00101001, 
  0b00101010, 0b00101011, 0b00101101, 0b00101110, 0b00101111, 0b00110111, 0b00111001, 0b00111010, 
  0b00111011, 0b00111101, 0b00111110, 0b00111111, 0b01000101, 0b01000111, 0b01001001, 0b01001010, 
  0b01001011, 0b01001101, 0b01001110, 0b01001111, 0b01010010, 0b01010011, 0b01010100, 0b01010101, 
  0b01010110, 0b01010111, 0b01011001, 0b01011010, 0b01011011, 0b01011100, 0b01011101, 0b01011110, 
  0b01011111, 0b01100101, 0b01100111, 0b01101001, 0b01101010, 0b01101011, 0b01101101, 0b01101110, 
  0b01101111, 0b01110001, 0b01110010, 0b01110011, 0b01110100, 0b01110101, 0b01110110, 0b01110111, 
  0b01111001, 0b01111010, 0b01111011, 0b01111100, 0b01111101, 0b01111110, 0b01111111, 0b10001010, 
  0b10001011, 0b10001110, 0b10001111, 0b10010010, 0b10010011, 0b10010100, 0b10010101, 0b10010110, 
  0b10010111, 0b10011010, 0b10011011, 0b10011100, 0b10011101, 0b10011110, 0b10011111, 0b10100010, 
  0b10100011, 0b10100100, 0b10100101, 0b10100110, 0b10100111, 0b10101000, 0b10101001, 0b10101010, 
  0b10101011, 0b10101100, 0b10101101, 0b10101110, 0b10101111, 0b10110010, 0b10110011, 0b10110100, 
  0b10110101, 0b10110110, 0b10110111, 0b10111000, 0b10111001, 0b10111010, 0b10111011, 0b10111100, 
  0b10111101, 0b10111110, 0b10111111, 0b11000101, 0b11000111, 0b11001001, 0b11001010, 0b11001011, 
  0b11001101, 0b11001110, 0b11001111, 0b11010001, 0b11010010, 0b11010011, 0b11010100, 0b11010101, 
  0b11010110, 0b11010111, 0b11011001, 0b11011010, 0b11011011, 0b11011100, 0b11011101, 0b11011110, 
  0b11011111, 0b11100010, 0b11100011, 0b11100100, 0b11100101, 0b11100110, 0b11100111, 0b11101000, 
  0b11101001, 0b11101010, 0b11101011, 0b11101100, 0b11101101, 0b11101110, 0b11101111, 0b11110001, 
  0b11110010, 0b11110011, 0b11110100, 0b11110101, 0b11110110, 0b11110111, 0b11111000, 0b11111001, 
  0b11111010, 0b11111011, 0b11111100, 0b11111101, 0b11111110, 0b11111111, 0b00110101, 0b01010001, 
};
const byte OFFSET_N1_SIZE = 36;
const byte OFFSET_N1_LIST[] = {
  0b00010000, 0b00011000, 0b00100000, 0b00100001, 0b00100100, 0b00101000, 0b00101100, 0b00110000, 
  0b00110100, 0b00111000, 0b00111100, 0b01000000, 0b01000001, 0b01001000, 0b01010000, 0b01011000, 
  0b01100000, 0b01100001, 0b01100011, 0b01101000, 0b01101100, 0b01110000, 0b01111000, 0b10000000, 
  0b10010000, 0b10100000, 0b10100001, 0b10110000, 0b10110001, 0b11000000, 0b11000001, 0b11010000, 
  0b11011000, 0b11100000, 0b11100001, 0b11110000, };
const byte OFFSET_0_SIZE = 24;
const byte OFFSET_0_LIST[] = {
  0b00010001, 0b00011001, 0b00100010, 0b00100110, 0b00110001, 0b00110010, 0b00110011, 0b01000100, 
  0b01000110, 0b01001100, 0b01100010, 0b01100100, 0b01100110, 0b10001000, 0b10001001, 0b10001100, 
  0b10010001, 0b10011000, 0b10011001, 0b11001000, 0b11001100, 0b00010011, 0b00100011, 0b11000100, 
};
const byte OFFSET_1_SIZE = 36;
const byte OFFSET_1_LIST[] = {
  0b00000001, 0b00000010, 0b00000011, 0b00000100, 0b00000101, 0b00000110, 0b00000111, 0b00001000, 
  0b00001001, 0b00001010, 0b00001011, 0b00001100, 0b00001101, 0b00001110, 0b00001111, 0b00010010, 
  0b00010100, 0b00010110, 0b00011010, 0b00011011, 0b00011100, 0b00011110, 0b00110110, 0b01000010, 
  0b01000011, 0b10000001, 0b10000010, 0b10000011, 0b10000100, 0b10000101, 0b10000110, 0b10000111, 
  0b10001101, 0b11000010, 0b11000011, 0b11000110, };
const byte OFFSET_IGNORE_SIZE = 160;
const byte OFFSET_IGNORE_LIST[] = {
  0b00000000, 0b00010101, 0b00010111, 0b00011101, 0b00011111, 0b00100101, 0b00100111, 0b00101001, 
  0b00101010, 0b00101011, 0b00101101, 0b00101110, 0b00101111, 0b00110111, 0b00111001, 0b00111010, 
  0b00111011, 0b00111101, 0b00111110, 0b00111111, 0b01000101, 0b01000111, 0b01001001, 0b01001010, 
  0b01001011, 0b01001101, 0b01001110, 0b01001111, 0b01010001, 0b01010010, 0b01010011, 0b01010100, 
  0b01010101, 0b01010110, 0b01010111, 0b01011001, 0b01011010, 0b01011011, 0b01011100, 0b01011101, 
  0b01011110, 0b01011111, 0b01100101, 0b01100111, 0b01101001, 0b01101010, 0b01101011, 0b01101101, 
  0b01101110, 0b01101111, 0b01110001, 0b01110010, 0b01110011, 0b01110100, 0b01110101, 0b01110110, 
  0b01110111, 0b01111001, 0b01111010, 0b01111011, 0b01111100, 0b01111101, 0b01111110, 0b01111111, 
  0b10001010, 0b10001011, 0b10001110, 0b10001111, 0b10010010, 0b10010011, 0b10010100, 0b10010101, 
  0b10010110, 0b10010111, 0b10011010, 0b10011011, 0b10011100, 0b10011101, 0b10011110, 0b10011111, 
  0b10100010, 0b10100011, 0b10100100, 0b10100101, 0b10100110, 0b10100111, 0b10101000, 0b10101001, 
  0b10101010, 0b10101011, 0b10101100, 0b10101101, 0b10101110, 0b10101111, 0b10110010, 0b10110011, 
  0b10110100, 0b10110101, 0b10110110, 0b10110111, 0b10111000, 0b10111001, 0b10111010, 0b10111011, 
  0b10111100, 0b10111101, 0b10111110, 0b10111111, 0b11000101, 0b11000111, 0b11001001, 0b11001010, 
  0b11001011, 0b11001101, 0b11001110, 0b11001111, 0b11010001, 0b11010010, 0b11010011, 0b11010100, 
  0b11010101, 0b11010110, 0b11010111, 0b11011001, 0b11011010, 0b11011011, 0b11011100, 0b11011101, 
  0b11011110, 0b11011111, 0b11100010, 0b11100011, 0b11100100, 0b11100101, 0b11100110, 0b11100111, 
  0b11101000, 0b11101001, 0b11101010, 0b11101011, 0b11101100, 0b11101101, 0b11101110, 0b11101111, 
  0b11110001, 0b11110010, 0b11110011, 0b11110100, 0b11110101, 0b11110110, 0b11110111, 0b11111000, 
  0b11111001, 0b11111010, 0b11111011, 0b11111100, 0b11111101, 0b11111110, 0b11111111, 0b00110101, 
};
bool indexOf(byte* arr, byte size, byte value) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == value) return true;
  }
  return false;
}

byte gsValueRotate(byte value, int16_t angle) {
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

void gsGetAngleOffset(int16_t currentAngle, int8_t* result) {
  byte gsValues = gsRead();
  gsValues = gsValueRotate(gsValues, currentAngle);

  if (indexOf(ANGLE_0_LIST, ANGLE_0_SIZE, gsValues)){
    result[0] = 0;
  } else if (indexOf(ANGLE_45_LIST, ANGLE_45_SIZE, gsValues)){
    result[0] = 45;
  } else if (indexOf(ANGLE_90_LIST, ANGLE_90_SIZE, gsValues)){
    result[0] = 90;
  } else if (indexOf(ANGLE_N45_LIST, ANGLE_N45_SIZE, gsValues)){
    result[0] = -45;
  } else {
    Serial.print("Unknown angle of pattern: "); Serial.println(gsValues, BIN);
  }
  
  if (indexOf(OFFSET_0_LIST, OFFSET_0_SIZE, gsValues)){
    result[1] = 0;
  } else if (indexOf(OFFSET_1_LIST, OFFSET_1_SIZE, gsValues)){
    result[1] = 1;
  } else if (indexOf(OFFSET_N1_LIST, OFFSET_N1_SIZE, gsValues)){
    result[1] = -1;
  } else {
    Serial.print("Unknown offset of pattern: "); Serial.println(gsValues, BIN);
  }
}
