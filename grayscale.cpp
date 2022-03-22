#include "grayscale.h"
#include <Arduino.h>

Grayscale::Grayscale(int pin1, int pin2, int pin3, int ref) {
  this->pins[0] = pin1;
  this->pins[1] = pin2;
  this->pins[2] = pin3;
  this->ref = ref;
}

Grayscale::Grayscale(int* pins, int ref) {
  for (int i = 0; i < 3; i++) {
    this->pins[i] = pins[i];
  }
  this->ref = ref;
}

void Grayscale::begin() {
  pinMode(this->pins[0], INPUT);
  pinMode(this->pins[1], INPUT);
  pinMode(this->pins[2], INPUT);
}

void Grayscale::readRawInto(int* data) {
  data[0] = analogRead(this->pins[0]);
  data[1] = analogRead(this->pins[1]);
  data[2] = analogRead(this->pins[2]);
}

void Grayscale::readInto(int* data) {
  data[0] = analogRead(this->pins[0]) > this->ref;
  data[1] = analogRead(this->pins[1]) > this->ref;
  data[2] = analogRead(this->pins[2]) > this->ref;
}

void Grayscale::readInto(int* data, int angle) {
  int* gsValues;
  this->readInto(gsValues);
  angle = angle % 360;
  if (angle < 0) {
    angle += 360;
  }
  if (angle > 330 || angle <= 30) {
    data[0] = gsValues[0];
    data[1] = gsValues[1];
    data[2] = gsValues[2];
  } else if (angle > 30 && angle <= 90) {
    data[0] = gsValues[0];
    data[1] = gsValues[2];
    data[2] = gsValues[1];
  } else if (angle > 90 && angle <= 150) {
    data[0] = gsValues[2];
    data[1] = gsValues[0];
    data[2] = gsValues[1];
  } else if (angle > 150 && angle <= 210) {
    data[0] = gsValues[2];
    data[1] = gsValues[1];
    data[2] = gsValues[0];
  } else if (angle > 210 && angle <= 270) {
    data[0] = gsValues[1];
    data[1] = gsValues[2];
    data[2] = gsValues[0];
  } else if (angle > 270 && angle <= 330) {
    data[0] = gsValues[1];
    data[1] = gsValues[0];
    data[2] = gsValues[2];
  }
}

void Grayscale::setRef(int ref) {
  this->ref = ref;
}
