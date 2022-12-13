/*******************************************************************
 * follow
  
  Follow the object
  using ultrasonic module and two infrared obstacle avoidance modules

  - Before use, you need to adjust the distance reference knob of 
  the two IR obstacle avoidance modules to the appropriate position
  
******************************************************************/
#include <Arduino.h>
#include "car_control.h"
#include "ir_obstacle.h"
#include "ultrasonic.h"

#define FOLLOW_DISTANCE 20

int8_t power = 80;
int8_t rotate_power = 50;
bool leftIsClear = false;
bool rightIsClear = false;
bool middleIsClear = false;

void setup() {
  Serial.begin(115200);
  Serial.println("Zeus Car auto follow");
  carBegin();
  irObstacleBegin();
}

void loop() {
  byte result = irObstacleRead();
  leftIsClear = result & 0b00000001;
  rightIsClear = result & 0b00000010;

  float usDistance = ultrasonicRead();
  Serial.print("usDistance:");Serial.print(usDistance);
  Serial.print(" leftIsClear:");Serial.print(leftIsClear);
  Serial.print(" rightIsClear:");Serial.println(rightIsClear);

  if (usDistance < 4) {
    carStop();
  } else if (usDistance < 10) {
    carForward(30);
  }
  else if (usDistance < FOLLOW_DISTANCE) {
    carForward(power);
  } else {
    if (!leftIsClear) {
      carTurnLeft(rotate_power);
    } else if (!rightIsClear) {
      carTurnRight(rotate_power);
    } else {
      carStop();
    }
  }

  delay(20);
}
