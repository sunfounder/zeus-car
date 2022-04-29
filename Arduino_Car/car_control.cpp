#include "car_control.h"

#include <Arduino.h>
#include <SoftPWM.h>  //PWM库

#define MOTOR_POWER_MIN 28  // 28/255

#define MOTOR_DIRECTION_0 1
#define MOTOR_DIRECTION_1 0
#define MOTOR_DIRECTION_2 0
#define MOTOR_DIRECTION_3 1
#define MOTOR_PIN_0_A 3
#define MOTOR_PIN_0_B 4
#define MOTOR_PIN_1_A 5
#define MOTOR_PIN_1_B 6
#define MOTOR_PIN_2_A 7
#define MOTOR_PIN_2_B 8
#define MOTOR_PIN_3_A 9
#define MOTOR_PIN_3_B 10

#define KP 0.8
#define KI 0.0
#define KD 20.0

int32_t _lastError = 0;
int32_t errorIntegral = 0;

int16_t originHeading;

void carBegin() {
  SoftPWMBegin();
  SoftPWMSet(MOTOR_PIN_0_A, 0);
  SoftPWMSet(MOTOR_PIN_0_B, 0);
  SoftPWMSet(MOTOR_PIN_1_A, 0);
  SoftPWMSet(MOTOR_PIN_1_B, 0);
  SoftPWMSet(MOTOR_PIN_2_A, 0);
  SoftPWMSet(MOTOR_PIN_2_B, 0);
  SoftPWMSet(MOTOR_PIN_3_A, 0);
  SoftPWMSet(MOTOR_PIN_3_B, 0);
  SoftPWMSetFadeTime(MOTOR_PIN_0_A, 100, 100);
  SoftPWMSetFadeTime(MOTOR_PIN_0_B, 100, 100);
  SoftPWMSetFadeTime(MOTOR_PIN_1_A, 100, 100);
  SoftPWMSetFadeTime(MOTOR_PIN_1_B, 100, 100);
  SoftPWMSetFadeTime(MOTOR_PIN_2_A, 100, 100);
  SoftPWMSetFadeTime(MOTOR_PIN_2_B, 100, 100);
  SoftPWMSetFadeTime(MOTOR_PIN_3_A, 100, 100);
  SoftPWMSetFadeTime(MOTOR_PIN_3_B, 100, 100);
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

// void carSetMotor(uint8_t motor, int8_t power) {
//   bool dir = power > 0;
//   int8_t newPower = 0;

//   if (power == 0) {
//     newPower = 0;
//   } else {
//     newPower = map(abs(power), 0, 100, MOTOR_POWER_MIN, 255);
//   }
//   switch (motor) {
//     case 0:
//       if (MOTOR_DIRECTION_0) dir = !dir;
//       SoftPWMSet(MOTOR_PIN_0_A,  dir * newPower);
//       SoftPWMSet(MOTOR_PIN_0_B, !dir * newPower);
//       break;
//     case 1:
//       if (MOTOR_DIRECTION_1) dir = !dir;
//       SoftPWMSet(MOTOR_PIN_1_A,  dir * newPower);
//       SoftPWMSet(MOTOR_PIN_1_B, !dir * newPower);
//       break;
//     case 2:
//       if (MOTOR_DIRECTION_2) dir = !dir;
//       SoftPWMSet(MOTOR_PIN_2_A,  dir * newPower);
//       SoftPWMSet(MOTOR_PIN_2_B, !dir * newPower);
//       break;
//     case 3:
//       if (MOTOR_DIRECTION_3) dir = !dir;
//       SoftPWMSet(MOTOR_PIN_3_A,  dir * newPower);
//       SoftPWMSet(MOTOR_PIN_3_B, !dir * newPower);
//       break;
//   }
// }

// void carSetMotors(int8_t power1, int8_t power2, int8_t power3, int8_t power4) {
//   carSetMotor(0, power1);
//   carSetMotor(1, power2);
//   carSetMotor(2, power3);
//   carSetMotor(3, power4);
// }

void carSetMotors(int8_t power0, int8_t power1, int8_t power2, int8_t power3) {
  bool dir0, dir1, dir2, dir3;
  int8_t newPower0, newPower1, newPower2, newPower3;

  dir0 = power0 > 0;
  dir1 = power1 > 0;
  dir2 = power2 > 0;
  dir3 = power3 > 0;

  if (MOTOR_DIRECTION_0) dir0 = !dir0;
  if (MOTOR_DIRECTION_1) dir1 = !dir1;
  if (MOTOR_DIRECTION_2) dir2 = !dir2;
  if (MOTOR_DIRECTION_3) dir3 = !dir3;

  if (power0 == 0) newPower0 = 0;
  else newPower0 = map(abs(power0), 0, 100, MOTOR_POWER_MIN, 255);
  if (power1 == 0) newPower1 = 0;
  else newPower1 = map(abs(power1), 0, 100, MOTOR_POWER_MIN, 255);
  if (power2 == 0) newPower2 = 0;
  else newPower2 = map(abs(power2), 0, 100, MOTOR_POWER_MIN, 255);
  if (power3 == 0) newPower3 = 0;
  else newPower3 = map(abs(power3), 0, 100, MOTOR_POWER_MIN, 255);

  SoftPWMSet(MOTOR_PIN_0_A,  dir0 * newPower0);
  SoftPWMSet(MOTOR_PIN_0_B, !dir0 * newPower0);
  SoftPWMSet(MOTOR_PIN_1_A,  dir1 * newPower1);
  SoftPWMSet(MOTOR_PIN_1_B, !dir1 * newPower1);
  SoftPWMSet(MOTOR_PIN_2_A,  dir2 * newPower2);
  SoftPWMSet(MOTOR_PIN_2_B, !dir2 * newPower2);
  SoftPWMSet(MOTOR_PIN_3_A,  dir3 * newPower3);
  SoftPWMSet(MOTOR_PIN_3_B, !dir3 * newPower3);
}

// void carMove(int16_t angle, int8_t power, int8_t rot) {
//   int8_t power_0, power_1, power_2, power_3;
//   angle += 90;
//   // Offset angle as 0 to the front
//   float rad = angle * PI / 180;

//   power /= sqrt(2);
//   // Calculate 4 wheel
//   power_0 = (power * sin(rad) - power * cos(rad)) * 0.5 - rot * 0.5;
//   power_1 = (power * sin(rad) + power * cos(rad)) * 0.5 + rot * 0.5;
//   power_2 = (power * sin(rad) - power * cos(rad)) * 0.5 + rot * 0.5;
//   power_3 = (power * sin(rad) + power * cos(rad)) * 0.5 - rot * 0.5;
//   // Serial.print("power: ");
//   // Serial.print(power_0);
//   // Serial.print(" ");
//   // Serial.print(power_1);
//   // Serial.print(" ");
//   // Serial.print(power_2);
//   // Serial.print(" ");
//   // Serial.println(power_3);

//   carSetMotors(power_0, power_1, power_2, power_3);
// }

void _carMove(int16_t angle, int8_t power, int8_t rot, bool drift) {
  int8_t power_0, power_1, power_2, power_3;
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

// void carMove(int16_t angle, int8_t power, int8_t rot, bool drift) {
//   int16_t heading;
//   int32_t error;
//   int32_t offset;

//   if (rot == 0) {
//     heading = compassReadAngle();
//     error = heading - originHeading;
//     // convert -360 to 360 to -180 to 180
//     if (error > 180) {
//       error -= 360;
//     } else if (error < -180) {
//       error += 360;
//     }

//     // offset += KP * error + KI * errorIntegral + KD * (_lastError - error);
//     offset += KP * error + KI * errorIntegral + KD * (error - _lastError);
  
//     // Serial.print("originHeading:");
//     // Serial.print(originHeading);
//     // Serial.print(",heading:");
//     // Serial.print(heading);
//     // Serial.print(',');
//     // Serial.print("error:");
//     // Serial.print(error);
//     // Serial.print(",rot:");
//     // Serial.println(offset);

//     rot += max(-100, min(100, offset));
//     errorIntegral += error;
//     _lastError = error;
//   }
//   _carMove(angle, power, rot, drift);
// }

void carMove(int16_t angle, int8_t power, int16_t heading, bool drift) {
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

  // Serial.print("heading:");
  // Serial.print(heading);
  // Serial.print("tempHeading:");
  // Serial.print(tempHeading);
  // Serial.print("error:");
  // Serial.println(error);
  offset += KP * error + KI * errorIntegral + KD * (error - _lastError);

  rot += max(-100, min(100, offset));
  errorIntegral += error;
  _lastError = error;

  // currentHeading = compassReadAngle();
  int16_t fcAngle = angle - currentHeading + originHeading;
  // Serial.print(",originHeading:");
  // Serial.print(originHeading);
  // Serial.print(",currentHeading:");
  // Serial.print(currentHeading);
  // Serial.print(",fcAngle:");
  // Serial.print(fcAngle);
  // Serial.print(",fieldAngle:");
  // Serial.println(originHeading-angle);

  _carMove(fcAngle, power, rot, drift);
}

void carResetHeading() {
  for (uint8_t i = 0; i < AVERAGE_FILTER_SIZE; i++) {
    originHeading = compassReadAngle();
  }
}
