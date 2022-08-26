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
#define MOTOR_DIRECTIONS (uint8_t[4]){1, 0, 0, 0}

/** define motors default speed */
#define CAR_DEFAULT_POWER 80
/** define motors rotate speed */
#define CAR_ROTATE_POWER 80
/** define motors calibration speed */
#define CAR_CALIBRATION_POWER 80

/** define car body width */
#define CAR_WIDTH  14.76/2   
/** define car body length */
#define CAR_LENGTH  11.48/2     

void carBegin();
void carSetMotors(int8_t power0, int8_t power1, int8_t power2, int8_t power3);
void carForward();
void carBackward();
void carTurnLeft();
void carTurnRight();
void carLeftForword();
void carRightForword();
void carLeftBackward();
void carRightBackward();
void carLeft();
void carRight();
void carStop();
void _carMove(int16_t angle, int8_t power, int8_t rot, bool drift=false);
void carMove(int16_t angle, int8_t power, int8_t rot, bool drift=false);
void carMoveFieldCentric(int16_t angle, int8_t power, int16_t heading, bool drift=false);
void carResetHeading();

#endif // __CAR_CONTROL_H__

