#include "car_control.h"

#include <Arduino.h>
#include <SoftPWM.h>  //PWM库

#define MOTOR_POWER_MIN 28  // 28/255

bool motorDirection[4] = {1, 0, 0, 1};
uint8_t motorPins[8] = {3, 4, 5, 6, 7, 8, 9, 10};

float kP = 0.8;
float kI = 0.0;
float kD = 20;
int32_t _lastError = 0;
int32_t errorIntegral = 0;

int16_t originHeading;

void carBegin() {
  SoftPWMBegin();
  for (uint8_t i = 0; i < 8; i++) {
    SoftPWMSet(motorPins[i], 0);
    SoftPWMSetFadeTime(motorPins[i], 100, 100);
  }
  compassBegin();
  carResetHeading();
}

void carForward()       { carSetMotors( 100,  100,  100,  100); }
void carBackward()      { carSetMotors(-100, -100, -100, -100); }
void carLeft()          { carSetMotors(-100,  100, -100,  100); }
void carRight()         { carSetMotors( 100, -100,  100, -100); }
void carTurnLeft()      { carSetMotors( 100, -100, -100,  100); }
void carTurnRight()     { carSetMotors(-100,  100,  100, -100); }
void carLeftForword()   { carSetMotors( 100,    0,  100,    0); }
void carRightForword()  { carSetMotors(   0,  100,    0,  100); }
void carLeftBackward()  { carSetMotors(   0, -100,    0, -100); }
void carRightBackward() { carSetMotors(-100,    0, -100,    0); }
void carStop()          { carSetMotors(   0,    0,    0,    0); }

void carSetMotor(uint8_t motor, int8_t power) {
  uint8_t a = motor * 2;
  uint8_t b = motor * 2 + 1;
  bool dir = power > 0;
  int8_t newPower = 0;
  if (motorDirection[motor]) dir = !dir;

  if (power == 0) {
    newPower = 0;
  } else {
    newPower = map(abs(power), 0, 100, MOTOR_POWER_MIN, 255);
  }

  SoftPWMSet(motorPins[a],  dir * newPower);
  SoftPWMSet(motorPins[b], !dir * newPower);
}

void carSetMotors(int8_t power1, int8_t power2, int8_t power3, int8_t power4) {
  carSetMotor(0, power1);
  carSetMotor(1, power2);
  carSetMotor(2, power3);
  carSetMotor(3, power4);
}

void carMove(int16_t angle, int8_t power, int8_t rot) {
  int8_t power_0, power_1, power_2, power_3;
  angle += 90;
  // Offset angle as 0 to the front
  float rad = angle * PI / 180;

  power /= sqrt(2);
  // Calculate 4 wheel
  power_0 = (power * sin(rad) - power * cos(rad)) * 0.6 - rot * 0.4;
  power_1 = (power * sin(rad) + power * cos(rad)) * 0.6 + rot * 0.4;
  power_2 = (power * sin(rad) - power * cos(rad)) * 0.6 + rot * 0.4;
  power_3 = (power * sin(rad) + power * cos(rad)) * 0.6 - rot * 0.4;
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

void carMove2(int16_t angle, int8_t power, int8_t rot) {
  int16_t heading;
  int32_t error;
  int32_t offset;

  if (rot == 0) {
    heading = compassReadAngle();
    error = heading - originHeading;
    // convert -360 to 360 to -180 to 180
    if (error > 180) {
      error -= 360;
    } else if (error < -180) {
      error += 360;
    }

    // offset += kP * error + kI * errorIntegral + kD * (_lastError - error);
    offset += kP * error + kI * errorIntegral + kD * (error - _lastError);
  
    // Serial.print("originHeading:");
    // Serial.print(originHeading);
    // Serial.print(",heading:");
    // Serial.print(heading);
    // Serial.print(',');
    Serial.print("error:");
    Serial.print(error);
    Serial.print(",rot:");
    Serial.println(offset);

    rot += max(-100, min(100, offset));
    errorIntegral += error;
    _lastError = error;
  }
  carMove(angle, power, rot);
}

void carMoveFieldCentric(int16_t angle, int8_t power, int8_t rot) {
  uint16_t heading;
  heading = compassReadAngle();
  int16_t fcAngle = angle - heading + originHeading;
  // Serial.print("originHeading:");
  // Serial.print(originHeading);
  // Serial.print(",heading:");
  // Serial.print(heading);
  // Serial.print(",fcAngle:");
  // Serial.print(fcAngle);
  // Serial.print(",fieldAngle:");
  // Serial.println(originHeading-angle);

  carMove(fcAngle, power, rot);
}

void carMove3(int16_t angle, int8_t power, int16_t heading) {
  int16_t currentHeading;
  int32_t error;
  int32_t offset;
  int8_t rot;
  int16_t tempHeading = originHeading + heading;

  currentHeading = compassReadAngle();
  error = currentHeading - tempHeading;
  // convert -360 to 360 to -180 to 180
  if (error > 180) {
    error -= 360;
  } else if (error < -180) {
    error += 360;
  }

  // offset += kP * error + kI * errorIntegral + kD * (_lastError - error);
  offset += kP * error + kI * errorIntegral + kD * (error - _lastError);

  // Serial.print("tempHeading:");
  // Serial.print(tempHeading);
  // Serial.print(",currentHeading:");
  // Serial.print(currentHeading);
  // Serial.print(',');
  // Serial.print("error:");
  // Serial.print(error);
  // Serial.print(",rot:");
  // Serial.println(offset);

  rot += max(-100, min(100, offset));
  errorIntegral += error;
  _lastError = error;

  currentHeading = compassReadAngle();
  int16_t fcAngle = angle - currentHeading + originHeading;
  Serial.print("originHeading:");
  Serial.print(originHeading);
  Serial.print(",currentHeading:");
  Serial.print(currentHeading);
  Serial.print(",fcAngle:");
  Serial.print(fcAngle);
  Serial.print(",fieldAngle:");
  Serial.println(originHeading-angle);

  carMove(fcAngle, power, rot);
}

void carResetHeading() {
  for (uint8_t i = 0; i < AVERAGE_FILTER_SIZE; i++) {
    originHeading = compassReadAngle();
  }
}

void carHeading() {
  return originHeading;
}