/*******************************************************************
 * rotate_and_move
 
  Add rotation based on omni move.
  carMove() function adds rotate parameter

  Go forward and turn in different radii.
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
int8_t rotate_power = 10;

void setup() {
  Serial.begin(115200);
  Serial.println("Zeus Car omni-directional move");
  SoftPWMBegin();  //init softpwm, before the motors initialization
  carBegin();      // init motors
}

void loop() {
  carMove(0, 0, rotate_power);  // anticlockwise rotate
  delay(1000);
  carMove(0, 0, -rotate_power);  // clockwise rotate
  delay(1000);
  carMove(0, 0, 0);
  delay(2000);
  for (uint8_t i = 0; i < 65; i += 5) {
    rotate_power = i;
    carMove(0, power, rotate_power);
    delay(1000);
  }
  carMove(0, 0, 0);
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
  */
void carMove(int16_t angle, int8_t power, int8_t rot) {
  int8_t power_0, power_1, power_2, power_3;
  float speed;
  // Make forward 0
  angle += 90;
  // Offset angle as 0 to the front
  float rad = angle * PI / 180;

  if (rot == 0) speed = 1;  // limit power value over 100
  else speed = 0.5;

  power /= sqrt(2);  // limit power value over 100

  power_0 = (power * sin(rad) - power * cos(rad)) * speed - rot * speed;
  power_1 = (power * sin(rad) + power * cos(rad)) * speed + rot * speed;
  power_2 = (power * sin(rad) - power * cos(rad)) * speed + rot * speed;
  power_3 = (power * sin(rad) + power * cos(rad)) * speed - rot * speed;

  carSetMotors(power_0, power_1, power_2, power_3);
}

void carStop() {
  carSetMotors(0, 0, 0, 0);
}