#ifndef __COMPASS_H__
#define __COMPASS_H__

#include <Arduino.h>

/** Set the number of samples for average filtering
 * 
 * default 30
 */
#define AVERAGE_FILTER_SIZE 30

/** Set the EEPROM start address where the calibration value is stored 
 * 
 * default 0
 */
#define EEPROM_CALIBRATION_ADDRESS 0

/** Set the time required for calibration values to stabilize
 * 
 * uinit millisecond， default 3000
 */
#define CALIBRATION_TIME 3000

/** Whether to turn on the average filter
 * 
 * default true
*/
#define AVERAGE_FILTER true
// #define AVERAGE_FILTER false

void compassBegin();
int16_t compassReadAngle();
int16_t compassGetAzimuth();
void compassCalibrateStart();
bool compassCalibrateLoop();
bool compassCalibrateDone();

#endif // __COMPASS_H__
