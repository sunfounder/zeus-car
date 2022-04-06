#include "ultrasonic.h"
#include "Arduino.h"

Ultrasonic::Ultrasonic(int echo, int trig) {
  this->echo = echo;
  this->trig = trig;
}

Ultrasonic::Ultrasonic(int pin) {
  this->echo = pin;
  this->trig = pin;
}

void Ultrasonic::begin() {
}

float Ultrasonic::read() {
  pinMode(this->trig, OUTPUT);
  digitalWrite(this->trig, LOW);
  delayMicroseconds(2);
  digitalWrite(this->trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(this->trig, LOW);
  pinMode(this->echo, INPUT);
  float duration = pulseIn(this->echo, HIGH);
  float distance = duration  * 34.0 / 1000;
  return distance;
}

bool Ultrasonic::isObstacle() {
  float distance = this->read();
  if (distance < this->ref) {
    return true;
  }
  return false;
}

bool Ultrasonic::isClear() {
  float distance = this->read();
  if (distance > this->ref) {
    return true;
  }
  return false;
}

void Ultrasonic::setRef(int ref) {
  this->ref = ref;
}