#ifndef __CMD_CODE_CONFIG_H__
#define __CMD_CODE_CONFIG_H__

#include <Arduino.h>
// #include "car_control.h"

// #define REMOTE_MODE_FIELD_CENTRIC
#define REMOTE_MODE_DRIFT

#define CMD_SUM 11

// State machine for almost all mode. State define see every function
int16_t remoteAngle;
int8_t remotePower;
int16_t remoteHeading;
int16_t remoteHeadingR;
bool remoteDriftEnable;

// Pay attention to the order,
// eg: 'left forward' needs to be placed before' left' and 'forward'
const char cmd_str_0[] PROGMEM = "stop";
const char cmd_str_1[] PROGMEM = "forward";
const char cmd_str_2[] PROGMEM = "backward";
const char cmd_str_3[] PROGMEM = "turn left";
const char cmd_str_4[] PROGMEM = "turn right";
const char cmd_str_5[] PROGMEM = "left forward";
const char cmd_str_6[] PROGMEM = "left backward";
const char cmd_str_7[] PROGMEM = "right forward";
const char cmd_str_8[] PROGMEM = "right backward";
const char cmd_str_9[] PROGMEM = "move left";
const char cmd_str_10[] PROGMEM = "move right";

const char *const cmd_str_table[] PROGMEM = {
  cmd_str_0, cmd_str_1, cmd_str_2, cmd_str_3,
  cmd_str_4, cmd_str_5, cmd_str_6, cmd_str_7,
  cmd_str_8, cmd_str_9, cmd_str_10,
};

#define STOP        0x00
#define FORWARD     0x01
#define BACKWARD    0x02
#define TRUE_LEFT   0x03
#define TRUE_RIGHT  0x04
#define LEFT_FORWARD 0x05
#define LEFT_BACKWARD 0x06
#define RIGHT_FORWARD 0x07
#define RIGHT_BACKWARD 0x08
#define LEFT        0x09
#define RIGHT       0x0A

const int8_t cmd_code_table[CMD_SUM] PROGMEM={
  STOP,
  FORWARD,
  BACKWARD,
  TRUE_LEFT,
  TRUE_RIGHT,
  LEFT_FORWARD,
  LEFT_BACKWARD,
  RIGHT_FORWARD,
  RIGHT_BACKWARD,
  LEFT,
  RIGHT, 
};


int8_t text_2_cmd_code(char* text){
    String str = String(text);
    char buffer[20];
    for(uint8_t i=0; i<CMD_SUM; i++){
        strcpy_P(buffer, (char *)pgm_read_word(&cmd_str_table[i]));
        if(str.indexOf(buffer) != -1){
            // Serial.print(pgm_read_byte(&cmd_code_table[i]), HEX);
            // Serial.print(" , ");
            // Serial.println(buffer);
            return pgm_read_byte(&cmd_code_table[i]);
        }
    }
    return -1; //error-code
}


void stop();
void forward();
void backward();
void turn_left();
void turn_right();
void left_forward();
void left_backward();
void right_forward();
void right_backward();
void left();
void right();

void (*cmd_fuc_table [])(){
  stop,
  forward,
  backward,
  turn_left,
  turn_right,
  left_forward,
  left_backward,
  right_forward,
  right_backward,
  left,
  right,
};

// ir_key_table: macth to cmd_code_table
const int8_t ir_key_table[CMD_SUM] PROGMEM={
  IR_KEY_5,
  IR_KEY_2,
  IR_KEY_8,
  IR_KEY_CYCLE,
  IR_KEY_U_SD,
  IR_KEY_1,
  IR_KEY_7,
  IR_KEY_3,
  IR_KEY_9,
  IR_KEY_4,
  IR_KEY_6,
};


int8_t ir_key_2_cmd_code(uint8_t key){
  for(uint8_t i=0; i<CMD_SUM; i++){
    if(pgm_read_byte(&ir_key_table[i]) == key){
      return pgm_read_byte(&cmd_code_table[i]);
    }
  }
  return -1; //error-code
}

void stop(){
  // Serial.println(F("stop"));
  remoteAngle = 0;
  remotePower = 0;
  #ifdef REMOTE_MODE_DRIFT
  remoteHeading = 0;
  remoteDriftEnable = false;
  #endif
  carStop();
}

void forward(){
  // Serial.println(F("forward"));
  remoteAngle = 0;
  #ifdef REMOTE_MODE_DRIFT
  remoteHeading = 0;
  carResetHeading();
  remoteDriftEnable = false;
  #endif

}

void backward(){
  // Serial.println(F("backward"));
  remoteAngle = 180;
  #ifdef REMOTE_MODE_DRIFT
  remoteHeading = 0;
  remoteDriftEnable = false;
  carResetHeading();
  #endif

}

void turn_left(){
  // Serial.println(F("turn left"));
  #ifdef REMOTE_MODE_FIELD_CENTRIC
  remoteAngle = 0;
  remotePower = 0;
  remoteHeading -= 45;
  if (remoteHeading < -180) {
    remoteHeading += 360;
  }
  #endif
  #ifdef REMOTE_MODE_DRIFT
  remoteHeading = -90;
  remoteDriftEnable = true;
  #endif
}

void turn_right(){
  // Serial.println(F("turn right"));
  #ifdef REMOTE_MODE_FIELD_CENTRIC
  remoteAngle = 0;
  remotePower = 0;
  remoteHeading += 45;
  if (remoteHeading > 180) {
    remoteHeading -= 360;
  }
  #endif
  #ifdef REMOTE_MODE_DRIFT
  remoteHeading = 90;
  remoteDriftEnable = true;
  #endif
}

void left_forward(){
  // Serial.println(F("left forward"));
  remoteAngle = 315;
  #ifdef REMOTE_MODE_DRIFT
  remoteHeading = 0;
  remoteDriftEnable = false;
  #endif
}

void left_backward(){
  // Serial.println(F("left backward"));
  remoteAngle = 225;
  #ifdef REMOTE_MODE_DRIFT
  remoteHeading = 0;
  remoteDriftEnable = false;
  #endif
}

void right_forward(){
  // Serial.println(F("right forward"));
  remoteAngle = 45;
  #ifdef REMOTE_MODE_DRIFT
  remoteHeading = 0;
  remoteDriftEnable = false;
  #endif
}

void right_backward(){
  // Serial.println(F("right backward"));
  remoteAngle = 135;
  #ifdef REMOTE_MODE_DRIFT
  remoteHeading = 0;
  remoteDriftEnable = false;
  #endif
}

void left(){
  // Serial.println(F("left"));
  remoteAngle = 270;
  #ifdef REMOTE_MODE_DRIFT
  remoteHeading = 0;
  remoteDriftEnable = false;
  #endif
}

void right(){
  // Serial.println(F("right"));
  remoteAngle = 90;
  #ifdef REMOTE_MODE_DRIFT
  remoteHeading = 0;
  remoteDriftEnable = false;
  #endif
}

#endif

