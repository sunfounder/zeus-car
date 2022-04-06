#include "compass.h"
#include <QMC5883LCompass.h>


QMC5883LCompass qmc5883l;

Compass::Compass() {}

void Compass::begin() {
  qmc5883l.init();
  // qmc5883l.setCalibration(-1120, 843, -1302, 747, 0, 492);
  // delay(2000);
  for (int i = 0; i < AVERAGE_FILTER_SIZE; i++) {
    this->read();
    // delay(10);
  }
}

int Compass::read() {
  int heading = this->readRaw();
  this->filterBufferAppend(heading);
  int sum = 0;
  for (int i = 0; i < AVERAGE_FILTER_SIZE; i++) {
    sum += filterBuffer[i];
  }
  return sum / AVERAGE_FILTER_SIZE;
}

int Compass::readRaw() {
  qmc5883l.read();
  int value = qmc5883l.getAzimuth();
  return value;
}

void Compass::filterBufferAppend(int value) {
  this->filterBuffer[this->filterBufferIndex] = value;
  this->filterBufferIndex++;
  if (this->filterBufferIndex >= AVERAGE_FILTER_SIZE) {
    this->filterBufferIndex = 0;
  }
}