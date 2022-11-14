/*******************************************************************
 * obstacle_avoid
  
  Automatic obstacle avoidance driving using ultrasonic module 
  and two infrared obstacle avoidance modules

  - Before use, you need to adjust the distance reference knob of 
  the two IR obstacle avoidance modules to the appropriate position
  
******************************************************************/
#include <Arduino.h>
#include "car_control.h"
#include "ir_obstacle.h"
#include "ultrasonic.h"

#define AVOID_DISTANCE 20

int8_t power = 80;
int8_t rotate_power = 80;
bool leftIsClear = false;
bool rightIsClear = false;
bool middleIsClear = false;

void setup() {
  Serial.begin(115200);
  Serial.println("Zeus Car auto obstacle avoid");
  carBegin();
  irObstacleBegin();
}

void loop() {
  byte result = irObstacleRead();
  leftIsClear = result & 0b00000001;
  rightIsClear = result & 0b00000010;

  float distance = ultrasonicRead();
  Serial.print("distance: ");Serial.print(distance);
  if (distance > AVOID_DISTANCE) {
    middleIsClear = true;
  } else {
    middleIsClear = false;
  }

  Serial.print("  obstacle: [ ");Serial.print(leftIsClear? "_" : "X");
  Serial.print(" ");Serial.print(middleIsClear? "_" : "X");
  Serial.print(" ");Serial.print(rightIsClear? "_" : "X");
  Serial.println("]");


  if (middleIsClear && leftIsClear && rightIsClear) {
    carForward(power);
  } else {
    if (leftIsClear) {
      carTurnLeft(rotate_power);
    } else if (rightIsClear) {
      carTurnRight(rotate_power);
    } else {
      carMove(0, 0, 20);
      delay(400);
      carStop();
    }
  }
  delay(20);
}
