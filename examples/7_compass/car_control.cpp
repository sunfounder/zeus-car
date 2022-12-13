#include "car_control.h"

#include <Arduino.h>
#include <SoftPWM.h>

#define MOTOR_POWER_MIN 28  // 28/255

/* 
  Set the pid parameters
*/
#define KP (float)0.8 
#define KI (float)0.0
#define KD (float)20.0  

int32_t _lastError = 0;
int32_t errorIntegral = 0;
int16_t originHeading;

/** 
* @brief Initialize the motor, and (block) the initialization compass
*/
void carBegin() {
  for (uint8_t i = 0; i < 8; i++) {
    SoftPWMSet(MOTOR_PINS[i], 0);
    SoftPWMSetFadeTime(MOTOR_PINS[i], 100, 100);
  }

  compassBegin();
  for (uint8_t i = 0; i < AVERAGE_FILTER_SIZE; i++) {
    carResetHeading();
  }

}

/** 
 * @name simple move functions with CAR_DEFAULT_POWER
 */
void carForward(int8_t power)       { carMove(   0, power, 0); }
void carBackward(int8_t power)      { carMove( 180, power, 0); }
void carLeft(int8_t power)          { carMove( -90, power, 0); }
void carRight(int8_t power)         { carMove(  90, power, 0); }
void carTurnLeft(int8_t power)      { carMove(   0, 0, power); }
void carTurnRight(int8_t power)     { carMove(   0, 0, -power); }
void carLeftForward(int8_t power)   { carMove( -45, power, 0); }
void carRightForward(int8_t power)  { carMove(  45, power, 0); }
void carLeftBackward(int8_t power)  { carMove(-135, power, 0); }
void carRightBackward(int8_t power) { carMove( 135, power, 0); }
void carStop()          { carMove(   0, 0, 0); }

/** 
 * @brief Set speed for 4 motors
 *
 * @param power0  0 ~ 100
 * @param power1  0 ~ 100
 * @param power2  0 ~ 100
 * @param power3 0 ~ 100
 */
void carSetMotors(int8_t power0, int8_t power1, int8_t power2, int8_t power3) {
  bool dir[4];
  int8_t power[4] = {power0, power1, power2, power3};
  int8_t newPower[4];

  for (uint8_t i = 0; i < 4; i++) {
    dir[i] = power[i] > 0;

    if (MOTOR_DIRECTIONS[i]) dir[i] = !dir[i];

    if (power[i] == 0) {
      newPower[i] = 0;
    } else {
      newPower[i] = map(abs(power[i]), 0, 100, MOTOR_POWER_MIN, 255);
    }
    SoftPWMSet(MOTOR_PINS[i*2], dir[i] * newPower[i]);
    SoftPWMSet(MOTOR_PINS[i*2+1], !dir[i] * newPower[i]);
  }
}

/** 
  * Control the car to move
  *  
  * @code {.cpp}
  * carMove(-90, 80, 0);
  * @endcode
  * 
  * @param angle the direction you want the car to move 
  * @param power moving speed  
  * @param rot the car fixed rotation angle during the movement
  * @param drift Whether it is a drift mode, default flase 
  *              true, drift mode, the car body will return to square
  *              flase, drift mode, the car body will not return to square
  */
void carMove(int16_t angle, int8_t power, int8_t rot, bool drift) {
  int8_t power_0, power_1, power_2, power_3;
  float speed;
  // Make forward 0
  angle += 90;
  // Offset angle as 0 to the front
  float rad = angle * PI / 180;

  if (rot == 0) speed = 1;
  else speed = 0.5;

  power /= sqrt(2);
  // Calculate 4 wheel
  if (drift) {
    power_0 = (power * sin(rad) - power * cos(rad)) * speed;
    power_1 = (power * sin(rad) + power * cos(rad)) * speed;
    power_2 = (power * sin(rad) - power * cos(rad)) * speed + rot * speed * 2;
    power_3 = (power * sin(rad) + power * cos(rad)) * speed - rot * speed * 2;
  } else {
    power_0 = (power * sin(rad) - power * cos(rad)) * speed - rot * speed;
    power_1 = (power * sin(rad) + power * cos(rad)) * speed + rot * speed;
    power_2 = (power * sin(rad) - power * cos(rad)) * speed + rot * speed;
    power_3 = (power * sin(rad) + power * cos(rad)) * speed - rot * speed;
  }
  
  carSetMotors(power_0, power_1, power_2, power_3);

}


/** 
  * Use the field center method to control the movement of the car
  *
  * @param angle the direction you want the car to move 
  * @param power moving speed  
  * @param heading the car head pointing
  * @param drift Whether it is a drift mode, default flase 
  *              true, drift mode, the car body will return to square
  *              flase, drift mode, the car body will not return to square
  */
void carMoveFieldCentric(int16_t angle, int8_t power, int16_t heading, bool drift) {
  int16_t currentHeading = 0;
  int32_t error = 0;
  int32_t offset = 0;
  int8_t rot = 0;

  currentHeading = compassReadAngle();

  error = currentHeading - originHeading - heading;

  // convert -360 to 360 to -180 to 180
  while (error > 180) {
    error -= 360;
  }
  while (error < -180) {
    error += 360;
  }

  if (error > 1 || error < -1) {
    offset += KP * error + KI * errorIntegral + KD * (error - _lastError);
    rot += max(-100, min(100, offset));
    errorIntegral += error;
    _lastError = error;
  }

  angle = angle - currentHeading + originHeading;
  carMove(angle, power, rot, drift);

}

/** 
  * Reset origin head pointing
  */
void carResetHeading() {
  originHeading = compassReadAngle();
}
