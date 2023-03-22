/*******************************************************************
  The control program of the Ardunio Mecanum wheel trolley.
  
  Please install SunFounder Controller APP from APP Store(iOS) or Google Play(Android).

  Development test environment:
    - Arduino IDE 1.8.19
  Board tools:
    - Arduino AVR Boards 1.8.3
  Libraries:
    - IRLremote
    - SoftPWM

  Version: 1.3.0
    -- https://github.com/sunfounder/zeus-car.git
  
  Author: Sunfounder
  Website: http://www.sunfounder.com
           https://docs.sunfounder.com

 *******************************************************************/
#define VERSION "1.3.0"

#include <Arduino.h>
#include <SoftPWM.h>
#include <string.h>

#include "rgb.h"
#include "compass.h"
#include "car_control.h"
#include "ir_obstacle.h"
#include "grayscale.h"
#include "ultrasonic.h"
#include "ir_remote.h"
#include "cmd_code_config.hpp"
#include "ai_camera.h"


/*************************** Configure *******************************/
/** @name Configure 
 * 
 */
///@{
/** Whether to enable Watchdog */
#define WATCH_DOG 0
#if WATCH_DOG
  #include <avr/wdt.h>
#endif

/** Whether to enable TEST mode */
#define TEST 0
#if TEST
  #include "test.h"
#endif

/** Whether to enable  */
#define MEM 0
#if MEM
  #include <MemoryFree.h>
  #include <pgmStrToRAM.h> // not needed for new way. but good to have for reference.
#endif


/** Configure Wifi mode, SSID, password*/
#define WIFI_MODE WIFI_MODE_AP
#define SSID "Zeus_Car"
#define PASSWORD "12345678"

// #define WIFI_MODE WIFI_MODE_STA
// #define SSID "xxxxxxxxxx"
// #define PASSWORD "xxxxxxxxxx"

/** Configure product name */
#define NAME "Zeus_Car"

/** Configure product type */
#define TYPE "Zeus_Car"

/** Configure websockets port
 * Sunfounder Controller APP fixed using port 8765
*/
#define PORT "8765"

/** Configure the motors speed in different modes */
#define SPEECH_REMOTE_POWER 40
#define IR_REMOTE_POWER  50
#define LINE_TRACK_POWER 50
#define OBSTACLE_AVOID_POWER 80
#define OBSTACLE_FOLLOW_POWER 80
#define CAR_CALIBRATION_POWER 80

/** Configure the offset angle of line track */
#define LINE_TRACK_OFFSET_ANGLE 30

/** Configure the follow distance of obstacle follow */
#define FOLLOW_DISTANCE 15

/** websocket communication headers */ 
#define WS_HEADER "WS+"

///@}

/*********************** Global variables ****************************/
/** Check if a string starts with a certain character */
#define IsStartWith(str, prefix) (strncmp(str, prefix, strlen(prefix)) == 0)

/** Instantiate aicamera, a class for serial communication with ESP32-CAM */
AiCamera aiCam = AiCamera(NAME, TYPE);

extern uint8_t currentMode;

extern int16_t currentAngle;
extern int16_t remoteAngle;
extern int8_t remotePower;
extern int8_t lastRemotePower;
extern int16_t remoteHeading;
extern bool remoteDriftEnable;

int16_t appRemoteAngle = 0;
int8_t appRemotePower = 0;
int16_t appRemoteHeading = 0;
int16_t appRemoteHeadingR = 0;
bool appRemoteDriftEnable = false;

bool irOrAppFlag = false; // true: App, false: IR

char speech_buf[20];

//@}

/*********************** setup() & loop() ************************/
/**
 * setup(), Ardunio main program entrance
 * 
 * Initialization of some peripherals
 */
void setup() {
  int m = millis();
  Serial.begin(115200);
  Serial.print("Arduino Car version ");Serial.println(VERSION);

  Serial.println(F("Initialzing..."));
  SoftPWMBegin(); // init softpwm, before the motors initialization and the rgb LEDs initialization
  rgbBegin();
  rgbWrite(ORANGE); // init hint
  carBegin();
  irBegin();
  irObstacleBegin();
  gsBegin();
  aiCam.begin(SSID, PASSWORD, WIFI_MODE, PORT);
  aiCam.setOnReceived(onReceive);
  while (millis() - m < 500) { // Wait for peripherals to be ready
    delay(1);
  }

  #if WATCH_DOG
  wdt_disable();  /* Disable the watchdog and wait for more than 2 seconds */
  delay(3000);  /* Done so that the Arduino doesn't keep resetting infinitely in case of wrong configuration */
  wdt_enable(WDTO_2S);  /* Enable the watchdog with a timeout of 2 seconds */
  #endif

  Serial.println(F("Okie!"));
  rgbWrite(GREEN); // init finished
}

/**
 * loop(), Ardunio main loop
 * 
 * - inclued
 *  - aiCam.loop()
 *  - irRemoteHandler()
 *  - modeHandler()
 * - or modules test
 */
void loop() {
  #if !TEST 
    // Note that "aiCam.loop()" needs to be before "irRemoteHandler"
    // because the value in a is constantly updated
    // Note that the cycle interval of the "aiCam.loop()" should be less than 80ms to avoid data d
    aiCam.loop();
    if (aiCam.ws_connected == false) {
      currentMode = MODE_NONE;
    }
    irRemoteHandler();
    modeHandler();
  #else
    /* Select the item to be tested, multiple selection allowed */
    motors_test();
    // rgb_test();
    // grayscale_test();
    // ultrasonic_test();
    // ir_obstacle_test();
    // obstacleAvoidance();
    // compass_test();
    // ir_remote_test();
  #endif 

  #if WATCH_DOG
    wdt_reset();  /* Reset the watchdog */
  #endif

  #if MEM
    Serial.print(F("Free RAM = ")); //F function does the same and is now a built in library, in IDE > 1.0.0
    Serial.println(freeMemory());  // print how much RAM is available in bytes.
  #endif

}

/***************************** Functions ******************************/
/**
 * modeHandler(), Execute the corresponding program according to the set mode
 * 
 * - inclued
 *  - MODE_NONE
 *  - MODE_LINE_TRACK
 *  - MODE_OBSTACLE_FOLLOWING
 *  - MODE_OBSTACLE_AVOIDANCE
 *  - MODE_REMOTE_CONTROL
 *  - MODE_APP_CONTROL
 *  - MODE_COMPASS_CALIBRATION
 */
void modeHandler() {
  switch (currentMode) {
    case MODE_NONE:
      rgbWrite(MODE_NONE_COLOR);
      carStop();
      break;
    case MODE_LINE_TRACK:
      rgbWrite(MODE_LINE_TRACK_COLOR);
      remotePower = LINE_TRACK_POWER;
      line_track();
      break;
    case MODE_OBSTACLE_FOLLOWING:
      rgbWrite(MODE_OBSTACLE_FOLLOWING_COLOR);
      remotePower = OBSTACLE_FOLLOW_POWER;
      obstacleFollowing();
      break;
    case MODE_OBSTACLE_AVOIDANCE:
      rgbWrite(MODE_OBSTACLE_AVOIDANCE_COLOR);
      remotePower = OBSTACLE_AVOID_POWER;
      obstacleAvoidance();
      break;
    case MODE_REMOTE_CONTROL:
      rgbWrite(MODE_REMOTE_CONTROL_COLOR);
      carMoveFieldCentric(remoteAngle, remotePower, remoteHeading, remoteDriftEnable);
      lastRemotePower = remotePower;
      break;
    case MODE_APP_CONTROL:
      rgbWrite(MODE_APP_CONTROL_COLOR);
      carMoveFieldCentric(remoteAngle, remotePower, remoteHeading, appRemoteDriftEnable);
      lastRemotePower = remotePower;
      break;
    case MODE_COMPASS_CALIBRATION:
      #if WATCH_DOG
        wdt_disable();  /* Disable the watchdog and wait for more than 2 seconds */
      #endif 
      bool changed = compassCalibrateLoop();
      if (changed) {
        rgbWrite(GREEN);
        delay(20);
        rgbOff();
      }
      if (compassCalibrateDone()) {
        currentMode = MODE_NONE;
        carStop();
      }
      #if WATCH_DOG
      wdt_enable(WDTO_2S);  /* Enable the watchdog with a timeout of 2 seconds */
      #endif
    default:
      break;
  }
}

/**
 * Line track program
 */
void line_track() {
  uint16_t result = gsGetAngleOffset();
  uint8_t angleType = result >> 8 & 0xFF;
  uint8_t offsetType = result & 0xFF;
  int16_t angle = 0;
  int8_t offset = 0;

  switch (angleType) {
    case ANGLE_N45:   angle = -45;break;
    case ANGLE_0:     angle =   0;break;
    case ANGLE_45:    angle =  45;break;
    case ANGLE_90:    angle =  90;break;
    case ANGLE_ERROR: angle = currentAngle;break;
  }
  switch (offsetType) {
    case OFFSET_N1:    offset = -1;break;
    case OFFSET_0:     offset =  0;break;
    case OFFSET_1:     offset =  1;break;
    case OFFSET_ERROR: offset =  0;break;
  }

  int16_t deltaAngle = currentAngle - angle;
  if (deltaAngle > 180) {
    deltaAngle -= 360;
  } else if (deltaAngle < -180) {
    deltaAngle += 360;
  } 

  if (deltaAngle > 90) {
    angle -= 180;
    offset *= -1;
  } else if (deltaAngle < -90) {
    angle += 180;
    offset *= -1;
  }

  currentAngle = angle + (offset*LINE_TRACK_OFFSET_ANGLE);
  carMoveFieldCentric(currentAngle, LINE_TRACK_POWER, 0, false);
}


/**
 * Obstacle follow program
 */
void obstacleFollowing() {
  byte result = irObstacleRead();
  bool leftIsClear = result & 0b00000001;
  bool rightIsClear = result & 0b00000010;
  float usDistance = ultrasonicRead();

  if (usDistance < 4) {
    carStop();
  } else if (usDistance < 10) {
    carForward(30);
  } else if (usDistance < FOLLOW_DISTANCE) {
    carForward(OBSTACLE_FOLLOW_POWER);
  } else {
    if (!leftIsClear) {
      carTurnLeft(OBSTACLE_FOLLOW_POWER);
    } else if (!rightIsClear) {
      carTurnRight(OBSTACLE_FOLLOW_POWER);
    } else {
      carStop();
    }
  }
}

/**
 * Obstacle avoidance program
 */
void obstacleAvoidance() {
  byte result = irObstacleRead();
  bool leftIsClear = result & 0b00000001;
  bool rightIsClear = result & 0b00000010;
  bool middleIsClear = ultrasonicIsClear();

  if (middleIsClear && leftIsClear && rightIsClear) {
    carForward(OBSTACLE_AVOID_POWER);
  } else {
    if (leftIsClear) {
      carTurnLeft(OBSTACLE_AVOID_POWER);
    } else if (rightIsClear) {
      carTurnRight(OBSTACLE_AVOID_POWER);
    } else {
      carMove(0, 0, 20);
      delay(400);
      carStop();
    }
  }
}

/**
 * irRemoteHandler, handle IR remote control key events
 */
void irRemoteHandler() {
  uint8_t key = irRead();
  if (key == IR_KEY_ERROR) {
    return; // No key pressed
  }else{
    remotePower = IR_REMOTE_POWER;
  }

  int8_t cmd_code = ir_key_2_cmd_code(key);
  if (cmd_code != -1) {
    currentMode = MODE_REMOTE_CONTROL;
    cmd_fuc_table[cmd_code]();
  }
  else{
    switch (key) {
      case IR_KEY_MODE:
        break;
      case IR_KEY_MUTE:
        currentMode = MODE_COMPASS_CALIBRATION;
        carMove(0, 0, CAR_CALIBRATION_POWER);
        compassCalibrateStart();
        break;
      case IR_KEY_PLAY_PAUSE:
        carResetHeading();
        // currentAngle = 0;
        irOrAppFlag = false;
        currentMode = MODE_LINE_TRACK;
        break;
      case IR_KEY_BACKWARD:
        carResetHeading();
        irOrAppFlag = false;
        currentMode = MODE_OBSTACLE_FOLLOWING;
        break;
      case IR_KEY_FORWARD:
        carResetHeading();
        irOrAppFlag = false;
        currentMode = MODE_OBSTACLE_AVOIDANCE;
        break;
      case IR_KEY_EQ:
        break;
      case IR_KEY_MINUS: // drift left
        currentMode = MODE_REMOTE_CONTROL;
        remoteAngle = 0;
        remotePower = lastRemotePower;
        remoteHeading = -90;
        remoteDriftEnable = true;
        carResetHeading();
        break;
      case IR_KEY_PLUS: // drift right
        currentMode = MODE_REMOTE_CONTROL;
        remoteAngle = 0;
        remotePower = lastRemotePower;
        remoteHeading = 90;
        remoteDriftEnable = true;
        carResetHeading();
        break;
      case IR_KEY_0: // Reset origin direction
        currentMode = MODE_REMOTE_CONTROL;
        remoteAngle = 0;
        remotePower = 0;
        remoteHeading = 0;
        remoteDriftEnable = false;
        carStop();
        carResetHeading();
        break;
    }
  }
}

/**
 * websocket received data processing
 */
void onReceive(char* recvBuf, char* sendBuf) {
  // Serial.print("recv:");Serial.println(recvBuf);

  // Mode select: line track, obstacle following, obstacle avoidance
  if (aiCam.getSwitch(recvBuf, REGION_N)) {
    irOrAppFlag = true;
    if (currentMode != MODE_LINE_TRACK) {
      // currentAngle = 0;
      carResetHeading();
      currentMode = MODE_LINE_TRACK;
    }
  } else if (aiCam.getSwitch(recvBuf, REGION_O)) {
    irOrAppFlag = true;
    if (currentMode != MODE_OBSTACLE_FOLLOWING) {
      carResetHeading();
      currentMode = MODE_OBSTACLE_FOLLOWING;
    }
  } else if (aiCam.getSwitch(recvBuf, REGION_P)) {
    irOrAppFlag = true;
    if (currentMode != MODE_OBSTACLE_AVOIDANCE) {
      carResetHeading();
      currentMode = MODE_OBSTACLE_AVOIDANCE;
    }
  } else {
    if (irOrAppFlag == true) {
      irOrAppFlag = false;
      currentMode = MODE_NONE;
      stop();
      carResetHeading();
      // currentAngle = 0;
      appRemoteHeading = 0;
      return;
    }
  }

  // Stop
  if (aiCam.getButton(recvBuf, REGION_F)) {
    currentMode = MODE_NONE;
    stop();
    return;
  }

  // Compass Calibrate
  if (aiCam.getButton(recvBuf, REGION_E)) {
    currentMode = MODE_COMPASS_CALIBRATION;
    carMove(0, 0, CAR_CALIBRATION_POWER); // rote to calibrate
    compassCalibrateStart();
    return;
  }

  // Reset Origin
  if (aiCam.getButton(recvBuf, REGION_I)) {
    currentMode = MODE_APP_CONTROL;
    carStop();
    carResetHeading();
    appRemoteHeading = 0;
    remoteHeading = 0;
    return;
  }

  //Joystick
  uint16_t angle = aiCam.getJoystick(recvBuf, REGION_K, JOYSTICK_ANGLE);
  uint8_t power = aiCam.getJoystick(recvBuf, REGION_K, JOYSTICK_RADIUS);
  power = map(power, 0, 100, 0, CAR_DEFAULT_POWER);
  if (appRemoteAngle != angle) {
    if (currentMode != MODE_APP_CONTROL) {
      currentMode = MODE_APP_CONTROL;
      carResetHeading();
    }
    appRemoteAngle = angle;
    remoteAngle = appRemoteAngle;
    appRemoteHeading = 0;
    remoteHeading = 0; // reset remoteHeading parameter, avoid "IR remote control" changed this value
  }
  if (appRemotePower != power) {
    if (currentMode != MODE_APP_CONTROL) {
      currentMode = MODE_APP_CONTROL;
      carResetHeading();
    }
    appRemotePower = power;
    remotePower = appRemotePower;
    appRemoteHeading = 0;
    remoteHeading = 0; // reset remoteHeading parameter, avoid "IR remote control" changed this value
  }

  // Drift 
  if (appRemoteDriftEnable != aiCam.getSwitch(recvBuf, REGION_J)) {
    if (currentMode != MODE_APP_CONTROL) {
      currentMode = MODE_APP_CONTROL;
      carResetHeading();
    }
    appRemoteDriftEnable = !appRemoteDriftEnable;
  }

  // MoveHead
  int moveHeadingA = aiCam.getJoystick(recvBuf, REGION_Q, JOYSTICK_ANGLE);
  int16_t moveHeadingR = aiCam.getJoystick(recvBuf, REGION_Q, JOYSTICK_RADIUS);
  if (appRemoteHeading != moveHeadingA || appRemoteHeadingR !=  moveHeadingR){
    if (currentMode != MODE_APP_CONTROL) {
      currentMode = MODE_APP_CONTROL;
      carResetHeading();
    }
    appRemoteHeading = moveHeadingA;
    appRemoteHeadingR = moveHeadingR;
    remoteHeading = moveHeadingA;
    if (appRemoteDriftEnable && moveHeadingR == 0) { // Drift mode
      carResetHeading();
      appRemoteHeading = 0;
      remoteHeading = 0;
    }
  }

  // Speech control
  char speech_buf_temp[20];
  aiCam.getSpeech(recvBuf, REGION_M, speech_buf_temp);
  if (strcmp(speech_buf_temp, speech_buf) != 0) {
    strcpy(speech_buf, speech_buf_temp);
    if (strlen(speech_buf) > 0) {
      int8_t cmd_code = text_2_cmd_code(speech_buf);
      if (cmd_code != -1) {
        remotePower = SPEECH_REMOTE_POWER;
        currentMode = MODE_APP_CONTROL;
        cmd_fuc_table[cmd_code]();
      }
    }
  }

}

