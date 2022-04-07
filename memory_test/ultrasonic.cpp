#include "ultrasonic.h"
#include "Arduino.h"

uint8_t ultrasonicTrig = 11;
uint8_t ultrasonicEcho = 11;

float ultrasonicRead() {
  pinMode(ultrasonicTrig, OUTPUT);
  digitalWrite(ultrasonicTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(ultrasonicTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultrasonicTrig, LOW);
  pinMode(ultrasonicEcho, INPUT);
  float duration = pulseIn(ultrasonicEcho, HIGH);
  float distance = duration  * 34.0 / 1000;
  return distance;
}

bool ultrasonicIsObstacle() {
  return ultrasonicRead() < ULTRASONIC_AVOIDANCE_THRESHOLD;
}

bool ultrasonicIsClear() {
  return ultrasonicRead() > ULTRASONIC_AVOIDANCE_THRESHOLD;
}
