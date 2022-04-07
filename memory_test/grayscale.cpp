#include "grayscale.h"

uint8_t grayscalePins[3] = {A0, A1, A2};
uint16_t grayscaleReference = 400;

void gsBegin() {
  pinMode(grayscalePins[0], INPUT);
  pinMode(grayscalePins[1], INPUT);
  pinMode(grayscalePins[2], INPUT);
}

void gsReadRawInto(uint16_t* data) {
  data[0] = analogRead(grayscalePins[0]);
  data[1] = analogRead(grayscalePins[1]);
  data[2] = analogRead(grayscalePins[2]);
}

void gsReadInto(bool* data) {
  data[0] = analogRead(grayscalePins[0]) > grayscaleReference;
  data[1] = analogRead(grayscalePins[1]) > grayscaleReference;
  data[2] = analogRead(grayscalePins[2]) > grayscaleReference;
}

void gsReadInto(bool* data, int16_t angle) {
  bool* gsValues;
  gsReadInto(gsValues);
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

void gsSetRef(uint16_t ref) {
  grayscaleReference = ref;
}
