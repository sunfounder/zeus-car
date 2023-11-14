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
    - ArduinoJson

  Version: 1.5.0
    -- https://github.com/sunfounder/zeus-car.git

  Documentation:
    -- https://docs.sunfounder.com/projects/zeus-car/en/latest/

  Author: Sunfounder
  Website: http://www.sunfounder.com
           https://docs.sunfounder.com

 *******************************************************************/
#include "Zeus_Car.h"

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

// last button state for app buttons:Line no Mag, Line, Follow, Avoid button
bool current_button_state[4] = {0, 0, 0, 0};
bool last_button_state[4] = {0, 0, 0, 0};

char speech_buf[20];

//@}

/*********************** setup() & loop() ************************/
/**
 * setup(), Ardunio main program entrance
 *
 * Initialization of some peripherals
 */
void setup()
{
  int m = millis();
  Serial.begin(115200);
  Serial.print(F("Arduino Car version "));
  Serial.println(F(VERSION));

  Serial.println(F("Initialzing..."));

  aiCam.begin(SSID, PASSWORD, WIFI_MODE, PORT);
  aiCam.setOnReceived(onReceive);

  while (millis() - m < 500)
  { // Wait for peripherals to be ready
    delay(1);
  }

#if WATCH_DOG
  wdt_disable();       /* Disable the watchdog and wait for more than 2 seconds */
  delay(3000);         /* Done so that the Arduino doesn't keep resetting infinitely in case of wrong configuration */
  wdt_enable(WDTO_2S); /* Enable the watchdog with a timeout of 2 seconds */
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
void loop()
{
  // Note that "aiCam.loop()" needs to be before "irRemoteHandler"
  // because the value in a is constantly updated
  // Note that the cycle interval of the "aiCam.loop()" should be less than 80ms to avoid data d
  aiCam.loop();
  if (aiCam.ws_connected == false && irOrAppFlag == 1)
  {
    currentMode = MODE_NONE;
  }
  irRemoteHandler();
  modeHandler();

#if WATCH_DOG
  wdt_reset(); /* Reset the watchdog */
#endif

#if MEM
  Serial.print(F("Free RAM = ")); // F function does the same and is now a built in library, in IDE > 1.0.0
  Serial.println(freeMemory());   // print how much RAM is available in bytes.
#endif
}

/***************************** Functions ******************************/
// https://docs.arduino.cc/learn/programming/memory-guide
int freeRam()
{
  extern int __heap_start, *__brkval;
  int v;
  return (int)&v - (__brkval == 0
                        ? (int)&__heap_start
                        : (int)__brkval);
}

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
void modeHandler()
{
  switch (currentMode)
  {
  case MODE_NONE:
    rgbWrite(MODE_NONE_COLOR);
    carStop();
    carResetHeading();
    break;
  case MODE_LINE_TRACK_WITHOUT_MAG:
    rgbWrite(MODE_LINE_TRACK_WITHOUT_MAG_COLOR);
    remotePower = LINE_TRACK_POWER;
    line_track(false);
    break;
  case MODE_LINE_TRACK_WITH_MAG:
    rgbWrite(MODE_LINE_TRACK_WITH_MAG_COLOR);
    remotePower = LINE_TRACK_POWER;
    line_track(true);
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
    wdt_disable(); /* Disable the watchdog and wait for more than 2 seconds */
#endif
    bool changed = compassCalibrateLoop();
    if (changed)
    {
      rgbWrite(GREEN);
      delay(20);
      rgbOff();
    }
    if (compassCalibrateDone())
    {
      currentMode = MODE_NONE;
      carStop();
    }
#if WATCH_DOG
    wdt_enable(WDTO_2S); /* Enable the watchdog with a timeout of 2 seconds */
#endif
  default:
    break;
  }
}

/**
 * Line track program
 *
 * @param useMag whether to use the geomagnetic sensor to keep the direction of the car,
 *               true(default), use the geomagnetic sensor,
 *               false, without the geomagnetic sensor
 */
void line_track(bool useMag)
{
  uint16_t result = gsGetAngleOffset();
  uint8_t angleType = result >> 8 & 0xFF;
  uint8_t offsetType = result & 0xFF;
  int16_t angle = 0;
  int8_t offset = 0;

  switch (angleType)
  {
  case ANGLE_N45:
    angle = -45;
    break;
  case ANGLE_0:
    angle = 0;
    break;
  case ANGLE_45:
    angle = 45;
    break;
  case ANGLE_90:
    angle = 90;
    break;
  case ANGLE_ERROR:
    angle = currentAngle;
    break;
  }
  switch (offsetType)
  {
  case OFFSET_N1:
    offset = -1;
    break;
  case OFFSET_0:
    offset = 0;
    break;
  case OFFSET_1:
    offset = 1;
    break;
  case OFFSET_ERROR:
    offset = 0;
    break;
  }

  int16_t deltaAngle = currentAngle - angle;
  if (deltaAngle > 180)
  {
    deltaAngle -= 360;
  }
  else if (deltaAngle < -180)
  {
    deltaAngle += 360;
  }

  if (deltaAngle > 90)
  {
    angle -= 180;
    offset *= -1;
  }
  else if (deltaAngle < -90)
  {
    angle += 180;
    offset *= -1;
  }
  currentAngle = angle + (offset * LINE_TRACK_OFFSET_ANGLE);

  if (useMag)
  {
    carMoveFieldCentric(currentAngle, LINE_TRACK_POWER, 0, false, true);
  }
  else
  {
    carMove(currentAngle, LINE_TRACK_POWER, 0, false);
  }
}

/**
 * Obstacle follow program
 */
void obstacleFollowing()
{
  byte result = irObstacleRead();
  bool leftIsClear = result & 0b00000001;
  bool rightIsClear = result & 0b00000010;
  float usDistance = ultrasonicRead();

  if (usDistance < 4)
  {
    carStop();
  }
  else if (usDistance < 10)
  {
    carForward(30);
  }
  else if (usDistance < FOLLOW_DISTANCE)
  {
    carForward(OBSTACLE_FOLLOW_POWER);
  }
  else
  {
    if (!leftIsClear)
    {
      carTurnLeft(OBSTACLE_FOLLOW_ROTATE_POWER);
    }
    else if (!rightIsClear)
    {
      carTurnRight(OBSTACLE_FOLLOW_ROTATE_POWER);
    }
    else
    {
      carStop();
    }
  }
}

/**
 * Obstacle avoidance program
 */
int8_t last_clear = -1; // last_clear, 1, left; -1, right;
bool last_forward = false;

void obstacleAvoidance()
{
  byte result = irObstacleRead();
  bool leftIsClear = result & 0b00000001;
  bool rightIsClear = result & 0b00000010;
  bool middleIsClear = ultrasonicIsClear();

  if (middleIsClear && leftIsClear && rightIsClear)
  { // 111
    last_forward = true;
    carForward(OBSTACLE_AVOID_POWER);
  }
  else
  {
    if ((leftIsClear && rightIsClear) || (!leftIsClear && !rightIsClear))
    {                                 // 101, 000, 010
      carMove(0, 0, last_clear * 50); // last_clear=1, turn left
      last_forward = false;
    }
    else if (leftIsClear)
    { // 100, 110
      if (last_clear == 1 || last_forward == true)
      {
        carTurnLeft(OBSTACLE_AVOID_POWER);
        last_clear = 1;
        last_forward = false;
      }
    }
    else if (rightIsClear)
    { // 001, 011
      if (last_clear == -1 || last_forward == true)
      {
        carTurnRight(OBSTACLE_AVOID_POWER);
        last_clear = -1;
        last_forward = false;
      }
    }
  }
}

/**
 * irRemoteHandler, handle IR remote control key events
 */
void irRemoteHandler()
{

  uint8_t key = irRead();
  if (key == IR_KEY_ERROR)
  {
    return; // No key pressed
  }
  else
  {
    remotePower = IR_REMOTE_POWER;
    irOrAppFlag = false;
  }

  int8_t cmd_code = ir_key_2_cmd_code(key);
  if (cmd_code != -1)
  {
    currentMode = MODE_REMOTE_CONTROL;
    cmd_fuc_table[cmd_code]();
  }
  else
  {
    switch (key)
    {
    case IR_KEY_MODE:
      break;
    case IR_KEY_MUTE:
      currentMode = MODE_COMPASS_CALIBRATION;
      carMove(0, 0, CAR_CALIBRATION_POWER);
      compassCalibrateStart();
      break;
    case IR_KEY_PLAY_PAUSE:
      carResetHeading();
      currentMode = MODE_LINE_TRACK_WITH_MAG;
      break;
    case IR_KEY_EQ:
      carResetHeading();
      currentMode = MODE_LINE_TRACK_WITHOUT_MAG;
      break;
    case IR_KEY_BACKWARD:
      carResetHeading();
      currentMode = MODE_OBSTACLE_FOLLOWING;
      break;
    case IR_KEY_FORWARD:
      carResetHeading();
      currentMode = MODE_OBSTACLE_AVOIDANCE;
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
void onReceive()
{
  Serial.print("recv:");
  Serial.println(aiCam.recvBuffer);
  irOrAppFlag = true;

  // Mode select: line track without magnetic field, line track withmagnetic field, obstacle following, obstacle avoidance
  current_button_state[0] = aiCam.getSwitch(REGION_M);
  current_button_state[1] = aiCam.getSwitch(REGION_N);
  current_button_state[2] = aiCam.getSwitch(REGION_O);
  current_button_state[3] = aiCam.getSwitch(REGION_P);

  // check change
  bool is_change = false;
  for (int i = 0; i < 4; i++)
  {
    if (current_button_state[i] != last_button_state[i])
    {
      is_change = true;
      last_button_state[i] = current_button_state[i];
    }
  }
  // changed
  if (is_change || currentMode == MODE_APP_CONTROL)
  {
    if (current_button_state[0])
    {
      if (currentMode != MODE_LINE_TRACK_WITHOUT_MAG)
      {
        carResetHeading();
        currentMode = MODE_LINE_TRACK_WITHOUT_MAG;
      }
    }
    else if (current_button_state[1])
    {
      if (currentMode != MODE_LINE_TRACK_WITH_MAG)
      {
        carResetHeading();
        currentMode = MODE_LINE_TRACK_WITH_MAG;
      }
    }
    else if (current_button_state[2])
    {
      if (currentMode != MODE_OBSTACLE_FOLLOWING)
      {
        carResetHeading();
        currentMode = MODE_OBSTACLE_FOLLOWING;
      }
    }
    else if (current_button_state[3])
    {
      if (currentMode != MODE_OBSTACLE_AVOIDANCE)
      {
        carResetHeading();
        currentMode = MODE_OBSTACLE_AVOIDANCE;
      }
    }
    else
    {
      if (currentMode != MODE_APP_CONTROL)
      {
        appRemoteHeading = 0;
        currentMode = MODE_NONE;
      }
    }
  }

  // Stop
  if (aiCam.getButton(REGION_F))
  {
    currentMode = MODE_NONE;
    stop();
    return;
  }

  // Compass Calibrate
  if (aiCam.getButton(REGION_E))
  {
    currentMode = MODE_COMPASS_CALIBRATION;
    carMove(0, 0, CAR_CALIBRATION_POWER); // rote to calibrate
    compassCalibrateStart();
    return;
  }

  // Reset Origin
  if (aiCam.getButton(REGION_G))
  {
    currentMode = MODE_APP_CONTROL;
    carStop();
    carResetHeading();
    appRemoteHeading = 0;
    remoteHeading = 0;
    return;
  }

  // Joystick
  uint16_t angle = aiCam.getJoystick(REGION_K, JOYSTICK_ANGLE);
  uint8_t power = aiCam.getJoystick(REGION_K, JOYSTICK_RADIUS);
  // power = map(power, 0, 100, 0, CAR_DEFAULT_POWER);

  if (appRemoteAngle != angle || appRemotePower != power || angle != 0 || power != 0)
  {
    if (currentMode != MODE_APP_CONTROL)
    {
      currentMode = MODE_APP_CONTROL;
      carResetHeading();
    }
    appRemoteAngle = angle;
    remoteAngle = appRemoteAngle;
    appRemotePower = power;
    remotePower = appRemotePower;
    appRemoteHeading = 0;
    remoteHeading = 0; // reset remoteHeading parameter, avoid "IR remote control" changed this value
  }

  // Drift
  if (appRemoteDriftEnable != aiCam.getSwitch(REGION_J))
  {
    if (currentMode != MODE_APP_CONTROL)
    {
      currentMode = MODE_APP_CONTROL;
      carResetHeading();
    }
    appRemoteDriftEnable = !appRemoteDriftEnable;
  }

  // MoveHead
  int moveHeadingA = aiCam.getJoystick(REGION_Q, JOYSTICK_ANGLE);
  int16_t moveHeadingR = aiCam.getJoystick(REGION_Q, JOYSTICK_RADIUS);
  if (appRemoteHeading != 0 || appRemoteHeadingR != 0 || appRemoteHeading != moveHeadingA || appRemoteHeadingR != moveHeadingR)
  {
    if (currentMode != MODE_APP_CONTROL)
    {
      currentMode = MODE_APP_CONTROL;
      carResetHeading();
    }
    appRemoteAngle = angle;
    remoteAngle = appRemoteAngle;
    appRemotePower = power;
    remotePower = appRemotePower;
    appRemoteHeading = moveHeadingA;
    appRemoteHeadingR = moveHeadingR;
    remoteHeading = moveHeadingA;
    if (appRemoteDriftEnable && moveHeadingR == 0)
    { // Drift mode
      carResetHeading();
      appRemoteHeading = 0;
      remoteHeading = 0;
    }
  }

  // Speech control
  char speech_buf_temp[20];

  aiCam.getSpeech(REGION_I, speech_buf_temp);
  if (strlen(speech_buf_temp) > 0)
  {
    if (aiCam.send_doc["I"].isNull() == false)
    {
      bool _last_stat = aiCam.send_doc["I"].as<bool>();
      if (_last_stat == 1)
      {
        aiCam.send_doc["I"] = 0;
      }
      else
      {
        aiCam.send_doc["I"] = 1;
      }
    }
    else
    {
      aiCam.send_doc["I"] = 0;
    }
  }

  if (strcmp(speech_buf_temp, speech_buf) != 0)
  {
    strcpy(speech_buf, speech_buf_temp);
    if (strlen(speech_buf) > 0)
    {
      int8_t cmd_code = text_2_cmd_code(speech_buf);
      if (cmd_code != -1)
      {
        remotePower = SPEECH_REMOTE_POWER;
        currentMode = MODE_APP_CONTROL;
        cmd_fuc_table[cmd_code]();
      }
    }
  }
}
