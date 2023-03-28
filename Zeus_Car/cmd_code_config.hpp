#ifndef __CMD_CODE_CONFIG_H__
#define __CMD_CODE_CONFIG_H__

#include <Arduino.h>
#include "rgb.h"
#include "car_control.h"
#include "ir_remote.h"

/** Mode Value Definition */
#define MODE_NONE                    0
#define MODE_LINE_TRACK              1
#define MODE_ROTATE_LINE_FOLLOWING   2
#define MODE_OBSTACLE_FOLLOWING      3
#define MODE_OBSTACLE_AVOIDANCE      4
#define MODE_REMOTE_CONTROL          5
#define MODE_APP_CONTROL             6
#define MODE_COMPASS_CALIBRATION     7

/** Set the color to match the mode */
#define ERROR_COLOR 0xFF0000 // Red
#define WARN_COLOR ORANGE

#define MODE_NONE_COLOR 0xE08080  // LightCyan

#define MODE_REMOTE_CONTROL_COLOR           GREEN_CYAN
#define MODE_APP_CONTROL_COLOR              MAGENTA

#define MODE_LINE_TRACK_COLOR               CYAN
#define MODE_OBSTACLE_FOLLOWING_COLOR       BLUE
#define MODE_OBSTACLE_AVOIDANCE_COLOR       PURPLE


// State machine for almost all mode. State define see every function
uint8_t currentMode = MODE_NONE;

int16_t currentAngle = 0;
int16_t remoteAngle = 0;
int8_t remotePower = 0;
int8_t lastRemotePower = 0;
int16_t remoteHeading = 0;

bool remoteDriftEnable  = false;

#define CMD_SUM 12

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
const char cmd_str_11[] PROGMEM = "pasue";

const char *const cmd_str_table[] PROGMEM = {
  cmd_str_0, cmd_str_1, cmd_str_2, cmd_str_3,
  cmd_str_4, cmd_str_5, cmd_str_6, cmd_str_7,
  cmd_str_8, cmd_str_9, cmd_str_10,cmd_str_11,
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
#define PAUSE       0x0B

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
  PAUSE,
};


int8_t text_2_cmd_code(char* text){
    String str = String(text);
    char buffer[20];
    for(uint8_t i=0; i<CMD_SUM; i++){
        strcpy_P(buffer, (char *)pgm_read_word(&cmd_str_table[i]));
        if(str.indexOf(buffer) != -1){
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
void pause();

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
  pause,
};

// ir_key_table: macth to cmd_code_table
const int8_t ir_key_table[CMD_SUM] PROGMEM={
  IR_KEY_POWER,
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
  IR_KEY_5,
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
  currentMode = MODE_NONE;
  remoteAngle = 0;
  remotePower = 0;
  lastRemotePower = 0;
  remoteHeading = 0;
  remoteDriftEnable = false;
  carStop();
  carResetHeading();
}

void forward(){
  remoteAngle = 0;
  remoteHeading = 0;
  remoteDriftEnable = false;
  carResetHeading();
}

void backward(){
  remoteAngle = 180;
  remoteHeading = 0;
  remoteDriftEnable = false;
  carResetHeading();
}

void turn_left(){
  remoteAngle = 0;
  remotePower = lastRemotePower;
  remoteHeading = -45;
  remoteDriftEnable = false;
  carResetHeading();
}

void turn_right(){
  remoteAngle = 0;
  remotePower = lastRemotePower;
  remoteHeading = 45;
  remoteDriftEnable = false;
  carResetHeading();
}

void left_forward(){
  remoteAngle = 315;
  remoteHeading = 0;
  remoteDriftEnable = false;
  carResetHeading();
}

void left_backward(){
  remoteAngle = 225;
  remoteHeading = 0;
  remoteDriftEnable = false;
  carResetHeading();
}

void right_forward(){
  remoteAngle = 45;
  remoteHeading = 0;
  remoteDriftEnable = false;
  carResetHeading();
}

void right_backward(){
  remoteAngle = 135;
  remoteHeading = 0;
  remoteDriftEnable = false;
  carResetHeading();
}

void left(){
  remoteAngle = 270;
  remoteHeading = 0;
  remoteDriftEnable = false;
  carResetHeading();
}

void right(){
  remoteAngle = 90;
  remoteHeading = 0;
  remoteDriftEnable = false;
  carResetHeading();
}

void pause(){
  remoteAngle = 0;
  remotePower = 0;
  remoteHeading = 0;
  remoteDriftEnable = false;
  carStop();
}

#endif

