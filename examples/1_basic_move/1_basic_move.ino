/*******************************************************************
 * basic_move
 
  Control the direction and speed of motors rotation by pwm,
  to make the car go forward, backward, left turn, right turn and stop.

******************************************************************/
#include <Arduino.h>
#include <SoftPWM.h>

/*
 *  [0]--|||--[1]
 *   |         |
 *   |         |
 *   |         |
 *   |         |
 *  [3]-------[2]
 */
/** Set the pins for the motors */
#define MOTOR_PINS \
  (uint8_t[8]) { \
    3, 4, 5, 6, A3, A2, A1, A0 \
  }
/** Set the positive and negative directions for the motors */
#define MOTOR_DIRECTIONS \
  (uint8_t[4]) { \
    1, 0, 0, 1 \
  }

#define MOTOR_POWER_MIN 28  // 28/255

int8_t power = 80;

void setup() {
  Serial.begin(115200);
  Serial.println("Zeus Car basic move");
  SoftPWMBegin();  //init softpwm, before the motors initialization
  carBegin();      // init motors
}

void loop() {

  carForward(power);
  delay(1000);
  carBackward(power);
  delay(1000);
  carLeft(power);
  delay(1000);
  carRight(power);
  delay(1000);
  carLeftForward(power);
  delay(1000);
  carLeftBackward(power);
  delay(1000);
  carRightForward(power);
  delay(1000);
  carRightBackward(power);
  delay(1000);
  carTurnLeft(power);
  delay(1000);
  carTurnRight(power);
  delay(1000);
  carStop();
  delay(2000);
}


void carBegin() {
  for (uint8_t i = 0; i < 8; i++) {
    SoftPWMSet(MOTOR_PINS[i], 0);
    SoftPWMSetFadeTime(MOTOR_PINS[i], 100, 100);
  }
}

void carSetMotors(int8_t power0, int8_t power1, int8_t power2, int8_t power3) {
  bool dir[4];
  int8_t power[4] = { power0, power1, power2, power3 };
  int8_t newPower[4];

  for (uint8_t i = 0; i < 4; i++) {
    dir[i] = power[i] > 0;

    if (MOTOR_DIRECTIONS[i]) dir[i] = !dir[i];

    if (power[i] == 0) {
      newPower[i] = 0;
    } else {
      newPower[i] = map(abs(power[i]), 0, 100, MOTOR_POWER_MIN, 255);
    }
    SoftPWMSet(MOTOR_PINS[i * 2], dir[i] * newPower[i]);
    SoftPWMSet(MOTOR_PINS[i * 2 + 1], !dir[i] * newPower[i]);
  }
}

void carForward(int8_t power) {
  carSetMotors(power, power, power, power);
}

void carBackward(int8_t power) {
  carSetMotors(-power, -power, -power, -power);
}

void carLeft(int8_t power) {
  carSetMotors(-power, power, -power, power);
}

void carRight(int8_t power) {
  carSetMotors(power, -power, power, -power);
}

void carLeftForward(int8_t power) {
  carSetMotors(0, power, 0, power);
}

void carLeftBackward(int8_t power) {
  carSetMotors(-power, 0, -power, 0);
}

void carRightForward(int8_t power) {
  carSetMotors(power, 0, power, 0);
}

void carRightBackward(int8_t power) {
  carSetMotors(0, -power, 0, -power);
}

void carTurnLeft(int8_t power) {
  carSetMotors(-power, power, power, -power);
}

void carTurnRight(int8_t power) {
  carSetMotors(power, -power, -power, power);
}

void carStop() {
  carSetMotors(0, 0, 0, 0);
}