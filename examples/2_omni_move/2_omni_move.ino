/*******************************************************************
 * omni_move
  
  The car uses the characteristics of the Mecanum wheel
  to move in different directions.

  Move along 0, 45, 90, 135, 180, 225, 270, 315, 360 direction 
  in turn for 1 second
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
#define MOTOR_PINS       (uint8_t[8]){3, 4, 5, 6, A3, A2, A1, A0} 
/** Set the positive and negative directions for the motors */
#define MOTOR_DIRECTIONS (uint8_t[4]){1, 0, 0, 1}

#define MOTOR_POWER_MIN 28  // 28/255

int8_t power = 80;

void setup() {
  Serial.begin(115200);
  Serial.println("Zeus Car omni-directional move");
  SoftPWMBegin(); //init softpwm, before the motors initialization
  carBegin(); // init motors
}

void loop() {
  carMove(0, power);
  delay(800);
  carMove(45, power);
  delay(1000);
  carMove(90, power);
  delay(1000);
  carMove(135, power);
  delay(1000);
  carMove(180, power);
  delay(800);
  carMove(225, power);
  delay(1000);
  carMove(270, power);
  delay(1000);
  carMove(315, power);
  delay(1000);
}

void carBegin() {
  for (uint8_t i = 0; i < 8; i++) {
    SoftPWMSet(MOTOR_PINS[i], 0);
    SoftPWMSetFadeTime(MOTOR_PINS[i], 100, 100);
  }
}

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
  * carMove(-90, 80);
  * @endcode
  * 
  * @param angle the direction you want the car to move 
  * @param power moving speed  
  */
void carMove(int16_t angle, int8_t power) {
  int8_t power_0, power_1, power_2, power_3;
  // Make forward 0
  angle += 90;
  // Offset angle as 0 to the front
  float rad = angle * PI / 180;
  
  power /= sqrt(2);
  
  
  power_0 = (power * sin(rad) - power * cos(rad));
  power_1 = (power * sin(rad) + power * cos(rad));
  power_2 = (power * sin(rad) - power * cos(rad));
  power_3 = (power * sin(rad) + power * cos(rad));
  
  carSetMotors(power_0, power_1, power_2, power_3);

}

void carStop() {
    carSetMotors(0, 0, 0, 0);
}
