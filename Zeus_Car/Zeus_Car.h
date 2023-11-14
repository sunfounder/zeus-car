#define VERSION "1.5.0"

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
#include <SunFounder_AI_Camera.h>


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

/** Configure AP SSID, password*/
#define WIFI_MODE WIFI_MODE_AP
#define SSID "Zeus_Car"
#define PASSWORD "12345678"

/** Configure product name */
#define NAME "Zeus_Car"

/** Configure product type */
#define TYPE "Zeus_Car"

/** Configure websockets port
 * Sunfounder Controller APP fixed using port 8765
 */
#define PORT "8765"

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

/** websocket communication headers */
#define WS_HEADER "WS+"

///@}

/*********************** Global variables ****************************/
/** Check if a string starts with a certain character */
#define IsStartWith(str, prefix) (strncmp(str, prefix, strlen(prefix)) == 0)
