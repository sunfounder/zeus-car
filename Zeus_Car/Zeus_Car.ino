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

/** global variables */
// current state
uint8_t currentState = STATE_IDLE;
// last state
uint8_t lastState = 255;
// line track power
uint8_t lineTrackPower = 0;
// obstacle power
uint8_t obstaclePower = 0;
// calibration State
uint8_t calibrationState = CALIBRATION_STATE_IDLE;
// last mode
uint8_t lastMode = 255;
// app control power
int8_t appControlPower = 0;
// app control angle
int16_t appControlAngle = 0;
// app control heading
int16_t appControlHeading = 0;
// app control rotatePower
int8_t appControlRotatePower = 0;
// app control move time ms
uint16_t appControlMoveTimeMs = 0;
// app control moving state
uint8_t appControlMovingState = MOVING_STATE_IDLE;
// app control move start time ms
uint32_t appControlMoveStartTimeMs = 0;
// remote control state
uint8_t remoteControlState = REMOTE_CONTROL_STATE_NONE;

/**
 * setup(), Ardunio main program entrance
 *
 * Initialization of some peripherals
 */
void setup() {
  int m = millis();
  Serial.begin(115200);
  Serial.print(F("Zeus Car version "));
  Serial.println(F(VERSION));

  Serial.println(F("Initialzing..."));
  SoftPWMBegin(); // init softpwm, before the motors initialization and the rgb LEDs initialization
  rgbBegin();
  rgbWrite(ORANGE); // init hint
  carBegin();
  irBegin();
  irObstacleBegin();
  gsBegin();
  
  aiCam.begin(AP_SSID, AP_PASSWORD, PORT, false);
  aiCam.setOnReceivedBinary(onReceive);

  while (millis() - m < 500) {  // Wait for peripherals to be ready
    delay(1);
  }

#if WATCH_DOG
  wdt_disable();       /* Disable the watchdog and wait for more than 2 seconds */
  delay(3000);         /* Done so that the Arduino doesn't keep resetting infinitely in case of wrong configuration */
  wdt_enable(WDTO_2S); /* Enable the watchdog with a timeout of 2 seconds */
#endif

  Serial.println(F("Okie!"));
  rgbWrite(GREEN);  // init finished
}

/**
 * loop(), Ardunio main loop
 *
 */
void loop() {
  if (lastState != currentState) {
    Serial.print(F("State changed to "));
    lastState = currentState;
    switch (currentState) {
      case STATE_IDLE: {
        Serial.println(F("IDLE"));
        rgbWrite(COLOR_STATE_IDLE);
        carStop();
        break;
      }
      case STATE_IR_REMOTE: {
        Serial.println(F("IR Remote"));
        currentMode = MODE_REMOTE_CONTROL;
        rgbWrite(COLOR_STATE_IR_REMOTE);
        if (lastState == STATE_APP) {
          aiCam.reset(false);
        }
        break;
      }
      case STATE_APP: {
        Serial.println(F("APP"));
        currentMode = MODE_REMOTE_CONTROL;
        rgbWrite(COLOR_STATE_APP);
        break;
      }
      default:
        break;
    }
  }
  switch (currentState) {
    case STATE_IDLE:
      {
        aiCam.loop();
        if (aiCam.ws_connected == true) {
          currentState = STATE_APP;
        }
        break;
      }
    case STATE_APP:
      {
        // Serial.println(F("aiCam loop"));
        aiCam.loop();
        // Serial.println(F("aiCam loop done"));
        handleSensorData();
        if (aiCam.ws_connected == false) {
          currentState = STATE_IDLE;
        }
        modeHandler();
        break;
      }
    case STATE_IR_REMOTE:
      {
        irRemoteHandler();
        modeHandler();
        break;
      }
    default:
      break;
  }

#if WATCH_DOG
  wdt_reset(); /* Reset the watchdog */
#endif

#if MEM
  Serial.print(F("Free RAM = "));  // F function does the same and is now a built in library, in IDE > 1.0.0
  Serial.println(freeMemory());    // print how much RAM is available in bytes.
#endif
}

/***************************** Functions ******************************/
// https://docs.arduino.cc/learn/programming/memory-guide
int freeRam() {
  extern int __heap_start, *__brkval;
  int v;
  return (int)&v - (__brkval == 0 ? (int)&__heap_start : (int)__brkval);
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
void modeHandler() {
  if (lastMode != currentMode) {
    Serial.print(F("Mode Change: "));Serial.print(lastMode);Serial.print(F(" -> "));Serial.println(currentMode);
    if (lastMode == MODE_COMPASS_CALIBRATION && calibrationState != CALIBRATION_STATE_CALIBRATED) {
      Serial.print(F("Calibration interrupted"));
      calibrationState = CALIBRATION_STATE_INTERRUPTED;
    }
  }
  lastMode = currentMode;
  switch (currentMode) {
    case MODE_LINE_TRACK_WITHOUT_MAG:
      // rgbWrite(COLOR_MODE_LINE_TRACK_NO_MAG);
      remotePower = LINE_TRACK_POWER;
      line_track(false);
      break;
    case MODE_LINE_TRACK_WITH_MAG:
      // rgbWrite(COLOR_MODE_LINE_TRACK_MAG);
      remotePower = LINE_TRACK_POWER;
      line_track(true);
      break;
    case MODE_OBSTACLE_FOLLOWING:
      // rgbWrite(COLOR_MODE_OBSTACLE_FOLLOWING);
      remotePower = OBSTACLE_FOLLOW_POWER;
      obstacleFollowing();
      break;
    case MODE_OBSTACLE_AVOIDANCE:
      // rgbWrite(COLOR_MODE_OBSTACLE_AVOIDANCE);
      remotePower = OBSTACLE_AVOID_POWER;
      obstacleAvoidance();
      break;
    case MODE_REMOTE_CONTROL:
      // rgbWrite(COLOR_STATE_IR_REMOTE);
      switch (remoteControlState) {
        case REMOTE_CONTROL_STATE_CAR_CENTRIC:
          carMove(appControlAngle, appControlPower, appControlRotatePower);
          break;
        case REMOTE_CONTROL_STATE_FIELD_CENTRIC:
          carMoveFieldCentric(appControlAngle, appControlPower, appControlHeading);
          break;
        case REMOTE_CONTROL_STATE_NONE:
          break;
        // If move time is not zero, the car will move for the specified time and then stop.
        if (appControlMoveTimeMs > 0) {
          // If the car is not moving, start moving
          if (appControlMovingState == MOVING_STATE_IDLE) {
            appControlMoveStartTimeMs = millis();
            appControlMovingState = MOVING_STATE_MOVING;
          } else {
            // If the car is moving, check if the time is up
            uint32_t elapsedTimeMs = millis() - appControlMoveStartTimeMs;
            if (elapsedTimeMs >= appControlMoveTimeMs) {
              appControlMovingState = MOVING_STATE_IDLE;
              appControlPower = 0;
              appControlAngle = 0;
              appControlHeading = 0;
              appControlRotatePower = 0;
              appControlMoveTimeMs = 0;
              appControlMoveStartTimeMs = 0;
              carStop();
            }
          }
        }
      }
      // carMoveFieldCentric(remoteAngle, remotePower, remoteHeading);
      // lastRemotePower = remotePower;
      break;
    case MODE_COMPASS_CALIBRATION:
#if WATCH_DOG
      wdt_disable(); /* Disable the watchdog and wait for more than 2 seconds */
#endif
      bool changed = compassCalibrateLoop();
      if (changed) {
        rgbWrite(GREEN);
        delay(20);
        rgbOff();
      }
      if (compassCalibrateDone()) {
        currentMode = MODE_REMOTE_CONTROL;
        calibrationState = CALIBRATION_STATE_CALIBRATED;
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
 * stopAll(), Stop the car
 */
void stopAll() {
  currentMode = MODE_REMOTE_CONTROL;
  remoteControlState = REMOTE_CONTROL_STATE_NONE;
  appControlPower = 0;
  appControlAngle = 0;
  appControlHeading = 0;
  appControlRotatePower = 0;
  appControlMoveTimeMs = 0;
  appControlMovingState = MOVING_STATE_IDLE;
  appControlMoveStartTimeMs = 0;
  calibrationState = CALIBRATION_STATE_IDLE;
  rgbOff();
  carStop();
}

/**
 * Line track program
 *
 * @param useMag whether to use the geomagnetic sensor to keep the direction of the car,
 *               true(default), use the geomagnetic sensor,
 *               false, without the geomagnetic sensor
 */
void line_track(bool useMag) {
  uint16_t result = gsGetAngleOffset();
  uint8_t angleType = result >> 8 & 0xFF;
  uint8_t offsetType = result & 0xFF;
  int16_t angle = 0;
  int8_t offset = 0;

  switch (angleType) {
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
  switch (offsetType) {
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
  currentAngle = angle + (offset * LINE_TRACK_OFFSET_ANGLE);

  if (useMag) {
    carMoveFieldCentric(currentAngle, lineTrackPower, 0, false, true);
  } else {
    carMove(currentAngle, lineTrackPower, 0, false);
  }
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
      carTurnLeft(obstaclePower);
    } else if (!rightIsClear) {
      carTurnRight(obstaclePower);
    } else {
      carStop();
    }
  }
}

/**
 * Obstacle avoidance program
 */
int8_t last_clear = -1;  // last_clear, 1, left; -1, right;
bool last_forward = false;

void obstacleAvoidance() {
  byte result = irObstacleRead();
  bool leftIsClear = result & 0b00000001;
  bool rightIsClear = result & 0b00000010;
  bool middleIsClear = ultrasonicIsClear();

  if (middleIsClear && leftIsClear && rightIsClear) {  // 111
    last_forward = true;
    carForward(OBSTACLE_AVOID_POWER);
  } else {
    if ((leftIsClear && rightIsClear) || (!leftIsClear && !rightIsClear)) {  // 101, 000, 010
      carMove(0, 0, last_clear * 50);                                        // last_clear=1, turn left
      last_forward = false;
    } else if (leftIsClear) {  // 100, 110
      if (last_clear == 1 || last_forward == true) {
        carTurnLeft(OBSTACLE_AVOID_POWER);
        last_clear = 1;
        last_forward = false;
      }
    } else if (rightIsClear) {  // 001, 011
      if (last_clear == -1 || last_forward == true) {
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
void irRemoteHandler() {

  uint8_t key = irRead();
  if (key == IR_KEY_ERROR) {
    return;  // No key pressed
  } else {
    remotePower = IR_REMOTE_POWER;
  }

  int8_t cmd_code = ir_key_2_cmd_code(key);
  if (cmd_code != -1) {
    currentMode = MODE_REMOTE_CONTROL;
    cmd_fuc_table[cmd_code]();
  } else {
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
      case IR_KEY_MINUS:  // drift left
        currentMode = MODE_REMOTE_CONTROL;
        remoteAngle = 0;
        remotePower = lastRemotePower;
        remoteHeading = -90;
        remoteDriftEnable = true;
        carResetHeading();
        break;
      case IR_KEY_PLUS:  // drift right
        currentMode = MODE_REMOTE_CONTROL;
        remoteAngle = 0;
        remotePower = lastRemotePower;
        remoteHeading = 90;
        remoteDriftEnable = true;
        carResetHeading();
        break;
      case IR_KEY_0:  // Reset origin direction
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
void onReceive() {
  Serial.print("onReceive:");
  for (int i = 0; i < aiCam.recvBufferLength; i++) {
    Serial.print(aiCam.recvBuffer[i], HEX);
    Serial.print(" ");
  }
  Serial.println(" ");
  for (int i = 0; i < aiCam.recvBufferLength; i++) {
    uint8_t entityId = aiCam.recvBuffer[i];
    switch (entityId) {
      case 0x01:  // Car move car centric
        {
          i += 1;
          uint8_t angleMSB = aiCam.recvBuffer[i];
          i += 1;
          uint8_t angleLSB = aiCam.recvBuffer[i];
          i += 1;
          int8_t movePower = aiCam.recvBuffer[i];
          i += 1;
          int8_t rotatePower = aiCam.recvBuffer[i];
          int16_t angle = (angleMSB << 8) | angleLSB;
          // Serial.println("Car move car centric");
          // Serial.print("angle:");Serial.println(angle);
          // Serial.print("movePower:");Serial.println(movePower);
          // Serial.print("rotatePower:");Serial.println(rotatePower);
          // carMove(angle, movePower, rotatePower);
          appControlAngle = angle;
          appControlPower = movePower;
          appControlRotatePower = rotatePower;
          currentMode = MODE_REMOTE_CONTROL;
          remoteControlState = REMOTE_CONTROL_STATE_CAR_CENTRIC;
          break;
        }
      case 0x02:  // Car move field centric
        {
          i += 1;
          uint8_t moveAngleMSB = aiCam.recvBuffer[i];
          i += 1;
          uint8_t moveAngleLSB = aiCam.recvBuffer[i];
          i += 1;
          int8_t movePower = aiCam.recvBuffer[i];
          i += 1;
          uint8_t headingAngleMSB = aiCam.recvBuffer[i];
          i += 1;
          uint8_t headingAngleLSB = aiCam.recvBuffer[i];
          int16_t moveAngle = (moveAngleMSB << 8) | moveAngleLSB;
          int16_t headingAngle = (headingAngleMSB << 8) | headingAngleLSB;
          // Serial.println(F("Car move field centric"));
          // Serial.print(F("moveAngle:"));Serial.println(moveAngle);
          // Serial.print(F("movePower:"));Serial.println(movePower);
          // Serial.print(F("headingAngle:"));Serial.println(headingAngle);
          // carMoveFieldCentric(moveAngle, movePower, headingAngle);
          appControlAngle = moveAngle;
          appControlPower = movePower;
          appControlHeading = headingAngle;
          currentMode = MODE_REMOTE_CONTROL;
          remoteControlState = REMOTE_CONTROL_STATE_FIELD_CENTRIC;
          break;
        }
      case 0x03:  // Direct motor control
        {
          i += 1;
          int8_t motor0 = aiCam.recvBuffer[i];
          i += 1;
          int8_t motor1 = aiCam.recvBuffer[i];
          i += 1;
          int8_t motor2 = aiCam.recvBuffer[i];
          i += 1;
          int8_t motor3 = aiCam.recvBuffer[i];
          // Serial.println(F("Direct motor control"));
          // Serial.print(F("motor0:"));Serial.println(motor0);
          // Serial.print(F("motor1:"));Serial.println(motor1);
          // Serial.print(F("motor2:"));Serial.println(motor2);
          // Serial.print(F("motor3:"));Serial.println(motor3);
          currentMode = MODE_REMOTE_CONTROL;
          remoteControlState = REMOTE_CONTROL_STATE_NONE;
          carSetMotors(motor0, motor1, motor2, motor3);
          break;
        }
      case 0x04:  // RGB control
        {
          i += 1;
          uint8_t r = aiCam.recvBuffer[i];
          i += 1;
          uint8_t g = aiCam.recvBuffer[i];
          i += 1;
          uint8_t b = aiCam.recvBuffer[i];
          // Serial.println(F("Set RGB: ("));Serial.print(r);
          // Serial.print(F(", "));Serial.print(g);
          // Serial.print(F(", "));Serial.print(b);Serial.println(")");
          rgbWrite(r, g, b);
          break;
        }
      case 0x05:  // Set User Heading
        {
          i += 1;
          uint8_t userHeadingMSB = aiCam.recvBuffer[i];
          i += 1;
          uint8_t userHeadingLSB = aiCam.recvBuffer[i];
          int16_t userHeading = (userHeadingMSB << 8) | userHeadingLSB;
          // Serial.print(F("Set Heading: "));Serial.println(userHeading);
          carSetHeading(userHeading);
          break;
        }
      case 0x06:  // Calibrate compass
        {
          i += 1;
          uint8_t calibrationState = aiCam.recvBuffer[i];
          if (calibrationState == 0) {
            // Serial.println(F("Compass calibration stop"));
            currentMode = MODE_REMOTE_CONTROL;
            calibrationState = CALIBRATION_STATE_INTERRUPTED;
            carStop();
          } else if (calibrationState == 1) {
            if (currentMode == MODE_COMPASS_CALIBRATION) break;
            Serial.println(F("Calibrate compass"));
            carMove(0, 0, CAR_CALIBRATION_POWER);
            compassCalibrateStart();
            currentMode = MODE_COMPASS_CALIBRATION;
            calibrationState = CALIBRATION_STATE_CALIBRATING;
          }
          break;
        }
      case 0x07:  // Line Track mode
        {
          i += 1;
          uint8_t state = aiCam.recvBuffer[i];
          i += 1;
          uint8_t mag = aiCam.recvBuffer[i];
          i += 1;
          lineTrackPower = aiCam.recvBuffer[i];
          // Serial.print(F("Line Track"));
          if (state == 1) {
            // Serial.print(F(" ON"));
            if (mag == 1) {
              // Serial.print(F(" with mag"));
              currentMode = MODE_LINE_TRACK_WITH_MAG;
            } else {
              // Serial.print(F(" without mag"));
              currentMode = MODE_LINE_TRACK_WITHOUT_MAG;
            }
          } else {
            // Serial.print(F(" OFF"));
            currentMode = MODE_REMOTE_CONTROL;
          }
          // Serial.print(F(" power:"));Serial.println(lineTrackPower);
          break;
        }
      case 0x08:  // Obstacle mode
        {
          i += 1;
          uint8_t state = aiCam.recvBuffer[i];
          i += 1;
          uint8_t mode = aiCam.recvBuffer[i];
          i += 1;
          obstaclePower = aiCam.recvBuffer[i];
          // Serial.print(F("Obstacle "));
          if (state) {
            // Serial.print(F(" ON"));
            if (mode == 0) {
              // Serial.print(F(" avoidance"));
              currentMode = MODE_OBSTACLE_AVOIDANCE;
            } else {
              // Serial.print(F(" following"));
              currentMode = MODE_OBSTACLE_FOLLOWING;
            }
          } else {
            // Serial.print(F(" OFF"));
            currentMode = MODE_REMOTE_CONTROL;
          }
          // Serial.print(F(" power:"));Serial.println(obstaclePower);
          break;
        }
      case 0x09:  // Car move car centric for ms
        {
          i += 1;
          uint8_t angleMSB = aiCam.recvBuffer[i];
          i += 1;
          uint8_t angleLSB = aiCam.recvBuffer[i];
          i += 1;
          int8_t movePower = aiCam.recvBuffer[i];
          i += 1;
          int8_t rotatePower = aiCam.recvBuffer[i];
          i += 1;
          int8_t moveTimeMsMSB = aiCam.recvBuffer[i];
          i += 1;
          int8_t moveTimeMsLSB = aiCam.recvBuffer[i];

          int16_t angle = (angleMSB << 8) | angleLSB;
          int16_t moveTimeMs = (moveTimeMsMSB << 8) | moveTimeMsLSB;
          // Serial.println("Car move car centric for ms");
          // Serial.print("angle:");Serial.println(angle);
          // Serial.print("movePower:");Serial.println(movePower);
          // Serial.print("rotatePower:");Serial.println(rotatePower);
          // Serial.print("moveTimeMs:");Serial.println(moveTimeMs);
          appControlAngle = angle;
          appControlPower = movePower;
          appControlRotatePower = rotatePower;
          currentMode = MODE_REMOTE_CONTROL;
          remoteControlState = REMOTE_CONTROL_STATE_CAR_CENTRIC;
          appControlMoveTimeMs = moveTimeMs;
          break;
        }
      case 0x0A:  // Car move field centric for ms
        {
          i += 1;
          uint8_t moveAngleMSB = aiCam.recvBuffer[i];
          i += 1;
          uint8_t moveAngleLSB = aiCam.recvBuffer[i];
          i += 1;
          int8_t movePower = aiCam.recvBuffer[i];
          i += 1;
          uint8_t headingAngleMSB = aiCam.recvBuffer[i];
          i += 1;
          uint8_t headingAngleLSB = aiCam.recvBuffer[i];
          int16_t moveAngle = (moveAngleMSB << 8) | moveAngleLSB;
          int16_t headingAngle = (headingAngleMSB << 8) | headingAngleLSB;
          // Serial.println(F("Car move field centric for ms"));
          // Serial.print(F("moveAngle:"));Serial.println(moveAngle);
          // Serial.print(F("movePower:"));Serial.println(movePower);
          // Serial.print(F("headingAngle:"));Serial.println(headingAngle);
          // carMoveFieldCentric(moveAngle, movePower, headingAngle);
          appControlAngle = moveAngle;
          appControlPower = movePower;
          appControlHeading = headingAngle;
          currentMode = MODE_REMOTE_CONTROL;
          remoteControlState = REMOTE_CONTROL_STATE_FIELD_CENTRIC;
          break;
        }
      case 0x0B:  // Stop
        {
          // Serial.println(F("Stop"));
          stopAll();
          break;
        }
    }
  }
}

void handleSensorData() {
  uint8_t toSend[WS_BUFFER_SIZE];
  int index = 0;
  toSend[index] = WS_DATA_START_BIT;

  // data length placeholder
  index += 1;
  toSend[index] = 0x00;

  // checksum placeholder
  index += 1;
  toSend[index] = 0x00;

  // UltraSonic
  index += 1;
  toSend[index] = 0x81;
  uint16_t ultrasonicMM = ultrasonicRead() * 10.0;
  uint8_t ultrasonicMMMSB = ultrasonicMM >> 8;
  uint8_t ultrasonicMMLS = ultrasonicMM & 0xFF;
  index += 1;
  toSend[index] = ultrasonicMMMSB;
  index += 1;
  toSend[index] = ultrasonicMMLS;

  // IR Obstacle
  index += 1;
  toSend[index] = 0x82;
  uint8_t irObstacle = irObstacleRead();
  index += 1;
  toSend[index] = irObstacle;

  // Grayscale Value
  index += 1;
  toSend[index] = 0x83;
  uint8_t grayscale = gsRead();
  index += 1;
  toSend[index] = grayscale;

  // Grayscale State
  index += 1;
  toSend[index] = 0x84;
  uint16_t grayscaleState = gsGetAngleOffset();
  uint8_t grayscaleAngle = grayscaleState >> 8;
  uint8_t grayscaleOffset = grayscaleState & 0xFF;
  index += 1;
  toSend[index] = grayscaleAngle | grayscaleOffset << 3;

  // User Heading
  index += 1;
  toSend[index] = 0x85;
  int16_t userHeading = carGetHeading();
  // Serial.print("userHeading:");Serial.println(userHeading);
  uint8_t userHeadingMSB = userHeading >> 8;
  uint8_t userHeadingLSB = userHeading & 0xFF;
  index += 1;
  toSend[index] = userHeadingMSB;
  index += 1;
  toSend[index] = userHeadingLSB;

  // Car Heading
  index += 1;
  toSend[index] = 0x86;
  int16_t carHeading = compassReadAngle();
  // Serial.print("car heading:");Serial.println(carHeading);
  uint8_t carHeadingMSB = carHeading >> 8;
  uint8_t carHeadingLSB = carHeading & 0xFF;
  index += 1;
  toSend[index] = carHeadingMSB;
  index += 1;
  toSend[index] = carHeadingLSB;

  // Calibration State
  index += 1;
  toSend[index] = 0x87;
  index += 1;
  toSend[index] = calibrationState;

  // Car Moving State
  index += 1;
  toSend[index] = 0x88;
  index += 1;
  toSend[index] = appControlMovingState;

  // End bit
  index += 1;
  toSend[index] = WS_DATA_END_BIT;

  uint8_t payloadLength = index + 1;

  // Data length
  toSend[1] = payloadLength - 4;

  // Checksum
  uint8_t checksum = 0;
  for (int i = 0; i < payloadLength - 1; i++) {
    checksum ^= toSend[i];
  }
  toSend[2] = checksum;

  aiCam.sendBinaryData(toSend, payloadLength);
}
