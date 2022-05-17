#include "car_control.h"

#include <Arduino.h>
#include <SoftPWM.h>

#define MOTOR_POWER_MIN 28  // 28/255

#define KP (float)0.8
#define KI (float)0.0
#define KD (float)20.0

int32_t _lastError = 0;
int32_t errorIntegral = 0;

int16_t originHeading;

void carBegin() {
  for (uint8_t i = 0; i < 8; i++) {
    SoftPWMSet(MOTOR_PINS[i], 0);
    SoftPWMSetFadeTime(MOTOR_PINS[i], 100, 100);
  }
  compassBegin();
  carResetHeading();
}

// void carForward()       { carSetMotors( 100,  100,  100,  100); }
// void carBackward()      { carSetMotors(-100, -100, -100, -100); }
// void carLeft()          { carSetMotors(-100,  100, -100,  100); }
// void carRight()         { carSetMotors( 100, -100,  100, -100); }
// void carTurnLeft()      { carSetMotors( 100, -100, -100,  100); }
// void carTurnRight()     { carSetMotors(-100,  100,  100, -100); }
// void carLeftForword()   { carSetMotors( 100,    0,  100,    0); }
// void carRightForword()  { carSetMotors(   0,  100,    0,  100); }
// void carLeftBackward()  { carSetMotors(   0, -100,    0, -100); }
// void carRightBackward() { carSetMotors(-100,    0, -100,    0); }
// void carStop()          { carSetMotors(   0,    0,    0,    0); }

void carForward()       { _carMove(   0, CAR_DEFAULT_POWER, 0); }
void carBackward()      { _carMove( 180, CAR_DEFAULT_POWER, 0); }
void carLeft()          { _carMove( -90, CAR_DEFAULT_POWER, 0); }
void carRight()         { _carMove(  90, CAR_DEFAULT_POWER, 0); }
void carTurnLeft()      { _carMove(   0, 0, -CAR_ROTATE_POWER); }
void carTurnRight()     { _carMove(   0, 0,  CAR_ROTATE_POWER); }
void carLeftForword()   { _carMove( -45, CAR_DEFAULT_POWER, 0); }
void carRightForword()  { _carMove(  45, CAR_DEFAULT_POWER, 0); }
void carLeftBackward()  { _carMove(-135, CAR_DEFAULT_POWER, 0); }
void carRightBackward() { _carMove( 135, CAR_DEFAULT_POWER, 0); }
void carStop()          { _carMove(   0, 0, 0); }

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

void _carMove(int16_t angle, int8_t power, int8_t rot, bool drift) {
  int8_t power_0, power_1, power_2, power_3;
  // Make forward 0
  angle += 90;
  // Offset angle as 0 to the front
  float rad = angle * PI / 180;

  power /= sqrt(2);
  // Calculate 4 wheel
  if (drift) {
    power_0 = (power * sin(rad) - power * cos(rad)) * 0.5;
    power_1 = (power * sin(rad) + power * cos(rad)) * 0.5;
    power_2 = (power * sin(rad) - power * cos(rad)) * 0.5 + rot * 0.5 * 2;
    power_3 = (power * sin(rad) + power * cos(rad)) * 0.5 - rot * 0.5 * 2;
  } else {
    power_0 = (power * sin(rad) - power * cos(rad)) * 0.5 - rot * 0.5;
    power_1 = (power * sin(rad) + power * cos(rad)) * 0.5 + rot * 0.5;
    power_2 = (power * sin(rad) - power * cos(rad)) * 0.5 + rot * 0.5;
    power_3 = (power * sin(rad) + power * cos(rad)) * 0.5 - rot * 0.5;
  }

  // Serial.print("power: ");
  // Serial.print(power_0);
  // Serial.print(" ");
  // Serial.print(power_1);
  // Serial.print(" ");
  // Serial.print(power_2);
  // Serial.print(" ");
  // Serial.println(power_3);

  carSetMotors(power_0, power_1, power_2, power_3);
}

void carMove(int16_t angle, int8_t power, int8_t rot, bool drift) {
  int32_t error;
  int32_t offset;

  if (rot == 0) {
    error = angle - originHeading;
    // convert -360 to 360 to -180 to 180
    if (error > 180) {
      error -= 360;
    } else if (error < -180) {
      error += 360;
    }

    offset += KP * error + KI * errorIntegral + KD * (error - _lastError);

    rot += max(-100, min(100, offset));
    errorIntegral += error;
    _lastError = error;
  }

  // Serial.print("offset:");
  // Serial.print(offset);
  // Serial.print(",error:");Serial.print(error);
  // Serial.print(",currentHeading: ");Serial.println(currentHeading);
  // Serial.print(",rot:");
  // Serial.print(rot);
  // Serial.print(",currentHeading:");
  // Serial.println(currentHeading);

  _carMove(angle, power, rot, drift);
}

void carMoveFieldCentric(int16_t angle, int8_t power, int16_t heading, bool drift) {
  int16_t currentHeading;
  int32_t error;
  int32_t offset;
  int8_t rot;

  currentHeading = compassReadAngle();

  if (rot == 0) {
    error = currentHeading - originHeading - heading;
    // convert -360 to 360 to -180 to 180
    if (error > 180) {
      error -= 360;
    } else if (error < -180) {
      error += 360;
    }

    offset += KP * error + KI * errorIntegral + KD * (error - _lastError);

    rot += max(-100, min(100, offset));
    errorIntegral += error;
    _lastError = error;
  }

  angle = angle - currentHeading + originHeading;
  _carMove(angle, power, rot, drift);
}

void carResetHeading() {
  for (uint8_t i = 0; i < AVERAGE_FILTER_SIZE; i++) {
    originHeading = compassReadAngle();
  }
}
