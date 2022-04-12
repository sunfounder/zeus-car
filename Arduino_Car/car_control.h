#ifndef __CAR_CONTROL_H__
#define __CAR_CONTROL_H__

#include <Arduino.h>
#include "compass.h"

#define CAR_WIDTH  14.76/2      //定义宽度
#define CAR_LENGTH  11.48/2     //定义长度

// [0]-------[1]
//  |         |
//  |         |
//  |         |
//  |         |
// [3]-------[2]

void carBegin();
void carSetMotor(uint8_t motor, int8_t power);
void carSetMotors(int8_t power1, int8_t power2, int8_t power3, int8_t power4);
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
void carMove(int16_t angle, int8_t power, int8_t rot);
void carMove2(int16_t angle, int8_t power, int8_t rot);
void carMoveFieldCentric(int16_t angle, int8_t power, int8_t rot);
void carMove3(int16_t angle, int8_t power, int16_t heading);
void carResetHeading();
void carHeading();

#endif // __CAR_CONTROL_H__