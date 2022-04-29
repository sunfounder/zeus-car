#ifndef __GRAYSCALE_H__
#define __GRAYSCALE_H__
#include <Arduino.h>

void gsBegin();
byte gsRead();
void gsReadAngleOffsetInto(double* angle, double* offset);
void gsGetAngleOffset(int16_t currentAngle, int8_t* result);
void gsReadRawInto(uint16_t* data);
void gsReadInto(bool* data);
void gsReadInto(bool* data, int16_t angle);
void gsSetRef(uint16_t ref);

#endif // __GRAYSCALE_H__