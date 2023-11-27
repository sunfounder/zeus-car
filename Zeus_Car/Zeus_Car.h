#define VERSION "1.5.0"

#include <Arduino.h>
#include <string.h>
#include <SoftPWM.h>
#include <SunFounder_AI_Camera.h>

#include "cmd_code_config.hpp"

#include "car_control.h"
#include "compass.h"
#include "grayscale.h"
#include "ir_obstacle.h"
#include "ir_remote.h"
#include "rgb.h"
#include "ultrasonic.h"



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

/** Whether to enable  */
#define MEM 0
#if MEM
#include <MemoryFree.h>
#include <pgmStrToRAM.h> // not needed for new way. but good to have for reference.
#endif

/** Configure AP SSID, password*/
#define AP_SSID "Zeus_Car"
#define AP_PASSWORD "12345678"

/** Configure product name */
#define NAME "Zeus_Car"
/** Configure product type */
#define TYPE "Zeus_Car"

/** Configure websockets port
 * Sunfounder Controller APP fixed using port 8765
 */
#define PORT "30102"

/**
 * Define State Machine
 */
#define STATE_IDLE 0
#define STATE_APP 1
#define STATE_IR_REMOTE 2

/** Configure the motors speed in different modes */
#define SPEECH_REMOTE_POWER 60
#define IR_REMOTE_POWER 60
#define LINE_TRACK_POWER 60
#define OBSTACLE_AVOID_POWER 65
#define OBSTACLE_FOLLOW_POWER 65
#define OBSTACLE_FOLLOW_ROTATE_POWER 50
#define CAR_CALIBRATION_POWER 90

/** Configure the offset angle of line track */
#define LINE_TRACK_OFFSET_ANGLE 35

/** Configure the follow distance of obstacle follow */
#define FOLLOW_DISTANCE 15

/** Calibration State */
#define CALIBRATION_STATE_IDLE 0
#define CALIBRATION_STATE_CALIBRATING 1
#define CALIBRATION_STATE_CALIBRATED 2
#define CALIBRATION_STATE_INTERRUPTED 3

/** websocket communication headers */
#define WS_HEADER "WS+"
#define WS_DATA_START_BIT 0xA0
#define WS_DATA_END_BIT 0xA1

///@}

/*********************** Global variables ****************************/
/** Check if a string starts with a certain character */
#define IsStartWith(str, prefix) (strncmp(str, prefix, strlen(prefix)) == 0)


void onReceive();
void irRemoteHandler();
void obstacleFollowing();
void obstacleAvoidance();
void line_track(bool useMag);
void modeHandler();
