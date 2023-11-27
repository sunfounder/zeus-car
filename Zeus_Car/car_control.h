#ifndef __CAR_CONTROL_H__
#define __CAR_CONTROL_H__

#include <Arduino.h>
#include "compass.h"

/*
 *  [0]--|||--[1]
 *   |         |
 *   |         |
 *   |         |
 *   |         |
 *  [3]-------[2]
 */

/** Set the pins for the motors */
#define MOTOR_PINS       (uint8_t[8]){3, 4, 5, 6, A3, A2, A1, A0} 
/** Set the positive and negative directions for the motors */
#define MOTOR_DIRECTIONS (uint8_t[4]){1, 0, 0, 1}

/** define motors default speed */
#define CAR_DEFAULT_POWER 80


void carBegin();
void carSetMotors(int8_t power0, int8_t power1, int8_t power2, int8_t power3);
void carForward(int8_t power);
void carBackward(int8_t power);
void carTurnLeft(int8_t power);
void carTurnRight(int8_t power);
void carLeftForword(int8_t power);
void carRightForword(int8_t power);
void carLeftBackward(int8_t power);
void carRightBackward(int8_t power);
void carLeft(int8_t power);
void carRight(int8_t power);
void carStop();
void carMove(int16_t angle, int8_t power, int8_t rot=0, bool drift=false);
void carMoveFieldCentric(int16_t angle, int8_t power, int16_t heading=0, bool drift=false, bool angFlag=false);
void carResetHeading();
void carSetHeading(int16_t heading);
int16_t carGetHeading();

#endif // __CAR_CONTROL_H__

