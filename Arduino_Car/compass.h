#ifndef __COMPASS_H__
#define __COMPASS_H__

#include <Arduino.h>

void compassBegin();
uint16_t compassReadAngle();
void compassCalibrate();

#endif // __COMPASS_H__