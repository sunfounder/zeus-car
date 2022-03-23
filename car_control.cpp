#include "car_control.h"

#include <Arduino.h>
#include <SoftPWM.h>  //PWM库

Car::Car(int* motorPins, int* motorDirection) {
  this->motorPins = motorPins;
  this->motorDirection = motorDirection;
}

void Car::begin() {
  SoftPWMBegin();
  for (int i = 0; i < 8; i++) {
    SoftPWMSet(this->motorPins[i], 0);
    SoftPWMSetFadeTime(this->motorPins[i], 100, 100);
  }
}

void Car::forward()       { this->setMotors( 100,  100,  100,  100); }
void Car::backward()      { this->setMotors(-100, -100, -100, -100); }
void Car::left()          { this->setMotors(-100,  100, -100,  100); }
void Car::right()         { this->setMotors( 100, -100,  100, -100); }
void Car::turnLeft()      { this->setMotors( 100, -100, -100,  100); }
void Car::turnRight()     { this->setMotors(-100,  100,  100, -100); }
void Car::leftForword()   { this->setMotors( 100,    0,  100,    0); }
void Car::rightForword()  { this->setMotors(   0,  100,    0,  100); }
void Car::leftBackward()  { this->setMotors(   0, -100,    0, -100); }
void Car::rightBackward() { this->setMotors(-100,    0, -100,    0); }
void Car::stop()          { this->setMotors(   0,    0,    0,    0); }

void Car::setMotor(int motor, int power) {
  int a = motor * 2;
  int b = motor * 2 + 1;
  int dir = power > 0;
  if (motorDirection[motor]) dir = !dir;

  int newPower = map(abs(power), 0, 100, 0, 255);

  SoftPWMSet(motorPins[a],  dir * newPower);
  SoftPWMSet(motorPins[b], !dir * newPower);
}

void Car::setMotors(int power1, int power2, int power3, int power4) {
  setMotor(0, power1);
  setMotor(1, power2);
  setMotor(2, power3);
  setMotor(3, power4);
}

void Car::move(int angle, int power, int rot) {
  int power_0, power_1, power_2, power_3;

  // Limite angle to 0-360
  angle = angle % 360;
  if (angle < 0) {
    angle += 360;
  }
  // Offset angle as 0 to the front
  angle += 90;
  float rad = angle * PI / 180;

  // Calculate 4 wheel
  power_0 = power * sin(rad) + power * cos(rad) - rot;
  power_1 = power * sin(rad) - power * cos(rad) + rot;
  power_2 = power * sin(rad) + power * cos(rad) + rot;
  power_3 = power * sin(rad) - power * cos(rad) - rot;

  this->setMotors(power_0, power_1, power_2, power_3);
}
