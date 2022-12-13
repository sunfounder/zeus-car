/*******************************************************************
 * remote_control
 
  Use the IR remote control to control the car 
  to move or rotate in different directions.

******************************************************************/
#include <Arduino.h>
#include <SoftPWM.h>
#include "car_control.h"
#include "ir_remote.h"

int angle=0;
int power=0;
int rotate=0;

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
      angle=0;
      power=0;
      rotate=0;      
      break;
    case IR_KEY_2:
      angle=0;
      power=80;
      rotate=0;      
      break;
    case IR_KEY_3:
      angle=45;
      power=80;
      rotate=0;      
      break;
    case IR_KEY_6:
      angle=90;
      power=80;
      rotate=0;      
      break;
    case IR_KEY_9:
      angle=135;
      power=80;
      rotate=0;      
      break;
    case IR_KEY_8:
      angle=180;
      power=80;
      rotate=0;      
      break;
    case IR_KEY_7:
      angle=255;
      power=80;
      rotate=0;      
      break;
    case IR_KEY_4:
      angle=270;
      power=80;
      rotate=0;      
      break;
    case IR_KEY_1:
      angle=315;
      power=80;
      rotate=0;      
      break;
    case IR_KEY_5:
      angle=0;
      power=0;
      rotate=0;      
      break;
    case IR_KEY_CYCLE:
      rotate=50;      
      break;
    case IR_KEY_U_SD:
      rotate=-50;  
      break;
    default:
      break;
  }
    carMove(angle, power,rotate);
  delay(20);
}
