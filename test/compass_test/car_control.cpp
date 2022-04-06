#include "car_control.h"

#include <Arduino.h>
#include <SoftPWM.h>  //PWM库
#include "compass.h"



#define MOTOR_POWER_MIN 22  // 28/255

float kP = 2.0;
float kI = 0.0;
float kD = 0.0;
int _lastError = 0;
int errorIntegral = 0;

Compass compass = Compass();

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
  compass.begin();
  this->resetHeading();
}

void Car::resetHeading() {
  originHeading = compass.read();
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
  int newPower = 0;
  if (motorDirection[motor]) dir = !dir;

  if (power == 0) {
    newPower = 0;
  } else {
    newPower = map(abs(power), 0, 100, MOTOR_POWER_MIN, 255);
  }

  SoftPWMSet(motorPins[a],  dir * newPower);
  SoftPWMSet(motorPins[b], !dir * newPower);
}

void Car::setMotors(int power1, int power2, int power3, int power4) {
  setMotor(0, power1);
  setMotor(1, power2);
  setMotor(2, power3);
  setMotor(3, power4);
}

void Car::move2(int angle, int power, int rot) {
  int heading;
  int error;

  heading = compass.read();
  error = heading - originHeading;
  // convert -360 to 360 to -180 to 180
  if (error > 180) {
    error -= 360;
  } else if (error < -180) {
    error += 360;
  }
  Serial.print("heading:");
  Serial.print(heading - originHeading);
  Serial.print(",base:");
  Serial.print(0);
  Serial.print(",error:");

  // rot += kP * error + kI * errorIntegral + kD * (_lastError - error);
  rot += kP * error + kI * errorIntegral + kD * (error - _lastError);
  Serial.println(rot);
  errorIntegral += error;
  _lastError = error;

  this->move(angle, power, rot);
}

void Car::move(int angle, int power, int rot) {
  int power_0, power_1, power_2, power_3;
  angle += 90;
  // Offset angle as 0 to the front
  float rad = angle * PI / 180;

  power /= sqrt(2);
  // Calculate 4 wheel
  power_0 = (power * sin(rad) + power * cos(rad)) * 0.7 - rot * 0.3;
  power_1 = (power * sin(rad) - power * cos(rad)) * 0.7 + rot * 0.3;
  power_2 = (power * sin(rad) + power * cos(rad)) * 0.7 + rot * 0.3;
  power_3 = (power * sin(rad) - power * cos(rad)) * 0.7 - rot * 0.3;

  // Serial.print("power: ");
  // Serial.print(power_0);
  // Serial.print(" ");
  // Serial.print(power_1);
  // Serial.print(" ");
  // Serial.print(power_2);
  // Serial.print(" ");
  // Serial.println(power_3);

  this->setMotors(power_0, power_1, power_2, power_3);
}
