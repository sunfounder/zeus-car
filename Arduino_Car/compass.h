#ifndef __COMPASS_H__
#define __COMPASS_H__

#include <Arduino.h>

#define AVERAGE_FILTER_SIZE 30
#define EEPROM_CALIBRATION_ADDRESS 0
#define CALIBRATION_TIME 5000

#define AVERAGE_FILTER true

void compassBegin();
uint16_t compassReadAngle();
void compassCalibrateStart();
void compassCalibrateLoop();
bool compassCalibrateDone();

#endif // __COMPASS_H__