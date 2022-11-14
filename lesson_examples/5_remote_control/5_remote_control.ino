/*******************************************************************
 * remote_control
 
  Use the IR remote control to control the car 
  to move or rotate in different directions.

******************************************************************/
#include <Arduino.h>
#include "car_control.h"
#include "ir_remote.h"

int8_t power = 80;

void setup() {
  Serial.begin(115200);
  Serial.println("Zeus Car IR remote control");
  SoftPWMBegin(); //init softpwm, before the motors initialization
  carBegin(); // init motors
  irBegin();
}

void loop() {
  uint8_t key = irRead();
  if (key != IR_KEY_ERROR) {
    Serial.print("key: 0x");Serial.println(key, HEX);
  }

  switch (key) {
    case IR_KEY_ERROR:
      break;
    case IR_KEY_POWER:
      carMove(0, 0);
      break;
    case IR_KEY_2:
      carMove(0, power);
      break;
    case IR_KEY_3:
      carMove(45, power);
      break;
    case IR_KEY_6:
      carMove(90, power);
      break;
    case IR_KEY_9:
      carMove(135, power);
      break;
    case IR_KEY_8:
      carMove(180, power);
      break;
    case IR_KEY_7:
      carMove(225, power);
      break;
    case IR_KEY_4:
      carMove(270, power);
      break;
    case IR_KEY_1:
      carMove(315, power);
      break;
    case IR_KEY_5:
      carMove(0, 0);
      break;
    case IR_KEY_PLUS:
      carTurnRight(power);
      break;
    case IR_KEY_MINUS:
      carTurnLeft(power);
      break;
    case IR_KEY_FORWARD:
      carMove(0, power, -90);
      break;
    case IR_KEY_BACKWARD:
      carMove(0, power, 90);
      break;
    default:
      break;
  }
  delay(20);
}
