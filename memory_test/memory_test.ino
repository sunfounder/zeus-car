
#include "Arduino.h"
#include "Arduino_Car.h"
#include "car_control.h"
#include "grayscale.h"
#include "ir_remote.h"
#include "ultrasonic.h"

uint8_t irObstaclePins[] = {12, A3, 12, 13, 13};

#define CAR_DEFAULT_POWER 40
#define CAR_CALIBRATION_POWER 80
#define NORMAL_LINE_FOLLOW_POWER 30
#define NORMAL_LINE_FOLLOW_ANGLE 45

// Current mode of the car
uint8_t currentMode = MODE_REMOTE_CONTROL;
// State machine for almost all mode. State define see every function
uint8_t currentState = 0;
uint16_t remoteAngle = 0;
int8_t remotePower = 0;
int8_t remoteRot = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("Seting up...");
  carBegin();
  gsBegin();
  irBegin();
  Serial.println("Setup done");
}

void loop() {
  uint8_t key = irRead();
  if (key != IR_KEY_ERROR) {
    currentState = 0;
  }
  switch (key) {
    case IR_KEY_POWER:
      currentMode = MODE_NONE;
      carStop();
      break;
    case IR_KEY_MODE:
      break;
    case IR_KEY_MUTE:
      currentMode = MODE_COMPASS_CALIBRATION;
      carMove(0, 0, CAR_CALIBRATION_POWER);
      carStop();
      Serial.println("Calibrate compass");
      break;
    case IR_KEY_PLAY_PAUSE:
      currentMode = MODE_NORMAL_LINE_FOLLOWING;
      Serial.println("Change mode to normal line following");
      break;
    case IR_KEY_BACKWARD:
      currentMode = MODE_NORMAL_OBSTACLE_FOLLOWING;
      Serial.println("Change mode to normal obstacle following");
      break;
    case IR_KEY_FORWARD:
      currentMode = MODE_NORMAL_OBSTACLE_AVOIDANCE;
      Serial.println("Change mode to normal obstacle avoidance");
      break;
    case IR_KEY_EQ:
      currentMode = MODE_PARALLEL_LINE_FOLLOWING;
      Serial.println("Change mode to parallel line following");
      break;
    case IR_KEY_MINUS:
      currentMode = MODE_PARALLEL_OBSTACLE_FOLLOWING;
      Serial.println("Change mode to parallel obstacle following");
      break;
    case IR_KEY_PLUS:
      currentMode = MODE_PARALLEL_OBSTACLE_AVOIDANCE;
      Serial.println("Change mode to parallel obstacle avoidance");
      break;
    case IR_KEY_0:
    case IR_KEY_CYCLE:
    case IR_KEY_U_SD:
    case IR_KEY_1:
    case IR_KEY_2:
    case IR_KEY_3:
    case IR_KEY_4:
    case IR_KEY_5:
    case IR_KEY_6:
    case IR_KEY_7:
    case IR_KEY_8:
    case IR_KEY_9:
      currentMode = MODE_REMOTE_CONTROL;
      remoteControl(key);
      Serial.println("Change mode to remote control");
      break;
    default:
      break;
  }

  switch (currentMode) {
    case MODE_NORMAL_LINE_FOLLOWING:
      normalLineFollowing();
      break;
    case MODE_NORMAL_OBSTACLE_FOLLOWING:
      normalObstacleFollowing();
      break;
    case MODE_NORMAL_OBSTACLE_AVOIDANCE:
      normalObstacleAvoidance();
      break;
    case MODE_PARALLEL_LINE_FOLLOWING:
      parallelLineFollowing();
      break;
    case MODE_PARALLEL_OBSTACLE_FOLLOWING:
      parallelObstacleFollowing();
      break;
    case MODE_PARALLEL_OBSTACLE_AVOIDANCE:
      parallelObstacleAvoidance();
      break;
    case MODE_REMOTE_CONTROL:
      carMove2(remoteAngle, remotePower, remoteRot);
      break;
    case MODE_COMPASS_CALIBRATION:
      compassCalibrate();
    default:
      break;
  }
}

// 循迹传感器呈倒三角形，放在小车正下方。旋转巡线（普通巡线）
void normalLineFollowing() {
  bool sensorL, sensorM, sensorR;
  bool gsValues[3];
  gsReadInto(gsValues);
  sensorL = gsValues[0];
  sensorM = gsValues[1];
  sensorR = gsValues[2];
  Serial.print(sensorL);
  Serial.print(", ");
  Serial.print(sensorM);
  Serial.print(", ");
  Serial.println(sensorR);
  if (sensorL == 0 && sensorM == 1 && sensorR == 0) {
    carMove(0, NORMAL_LINE_FOLLOW_POWER, 0);
  } else if (sensorL == 1 && sensorM == 0 && sensorR == 0) {
    carMove(-NORMAL_LINE_FOLLOW_ANGLE, NORMAL_LINE_FOLLOW_POWER, 0);
  } else if (sensorL == 0 && sensorM == 0 && sensorR == 1) {
    carMove(NORMAL_LINE_FOLLOW_ANGLE, NORMAL_LINE_FOLLOW_POWER, 0);
  } else if (sensorL == 1 && sensorM == 1 && sensorR == 0) {
    carMove(0, 0, NORMAL_LINE_FOLLOW_POWER);
  } else if (sensorL == 0 && sensorM == 1 && sensorR == 1) {
    carMove(0, 0, -NORMAL_LINE_FOLLOW_POWER);
  }
}

// State machine: state 0: follow, state 1: turn to find Obstacle
void normalObstacleFollowing() {
  bool sensor_values[5];
  float us_dis;
  us_dis = ultrasonicRead();
  for (uint8_t i = 0; i < 5; i++) {
    sensor_values[i] = digitalRead(irObstaclePins[i]);
  }
  if (us_dis < ULTRASONIC_STOP_THRESHOLD) {
    carStop();
    currentState = 0;
  } else if (us_dis < ULTRASONIC_FOLLOW_THRESHOLD) {
    carMove(0, CAR_DEFAULT_POWER, 0);
    currentState = 0;
  } else if (sensor_values[0] + sensor_values[1] + sensor_values[2] < 3) {
    // if any of the three sensors are triggered, turn left
    carMove(0, 0, -CAR_DEFAULT_POWER);
    currentState = 1;
  } else if (sensor_values[3] + sensor_values[4] < 2) {
    // if any of the two sensors are triggered, turn right
    carMove(0, 0, CAR_DEFAULT_POWER);
    currentState = 1;
  } else {
    if (currentState == 0) {
      carStop();
    }
  }
}

void normalObstacleAvoidance() {
  bool middle_clear = ultrasonicIsClear();
  bool left_clear = digitalRead(irObstaclePins[4]);
  bool right_clear = digitalRead(irObstaclePins[0]);
  if (middle_clear && left_clear && right_clear) {
    carMove(0, CAR_DEFAULT_POWER, 0);  //前进
  } else {
    if (!left_clear) {
      carMove(0, 0, -CAR_DEFAULT_POWER);
    } else {
      carMove(0, 0, CAR_DEFAULT_POWER);
    }
  }
}

// 循迹传感器呈倒三角形，放在小车正下方。平移巡线
int16_t moveAngle = 0;
uint16_t lineFollowOffLineCount = 0;
void parallelLineFollowing() {
  bool sensorL, sensorM, sensorR;
  bool gsValues[3];
  gsReadInto(gsValues, moveAngle);
  sensorL = gsValues[0];
  sensorM = gsValues[1];
  sensorR = gsValues[2];
  if (sensorL == 0 && sensorM == 1 && sensorR == 0) {
    // Serial.println("前进");
    carMove(moveAngle, CAR_DEFAULT_POWER, 0);
  } else if (sensorL == 1 && sensorM == 0 && sensorR == 0) {
    // Serial.println("左移");
    carMove(moveAngle - 60, CAR_DEFAULT_POWER, 0);
  } else if (sensorL == 0 && sensorM == 0 && sensorR == 1) {
    // Serial.println("右移");
    carMove(moveAngle + 60, CAR_DEFAULT_POWER, 0);
  } else if (sensorL == 0 && sensorM == 1 && sensorR == 1) {
    if (moveAngle % 120 == 0) {
      moveAngle += 60;
    } else {
      moveAngle -= 60;
    }
    carMove(moveAngle, CAR_DEFAULT_POWER, 0);
    // Wait until only one sensor is on the line
    while (gsValues[0] + gsValues[1] + gsValues[2] == 1) {
      gsReadInto(gsValues, moveAngle);
    }
    Serial.print("改变方向：");
    Serial.println(moveAngle);
  } else if (sensorL == 1 && sensorM == 1 && sensorR == 0) {
    if (moveAngle % 120 == 0) {
      moveAngle -= 60;
    } else {
      moveAngle += 60;
    }
    carMove(moveAngle, CAR_DEFAULT_POWER, 0);
    // Wait until only one sensor is on the line
    while (gsValues[0] + gsValues[1] + gsValues[2] == 1) {
      gsReadInto(gsValues, moveAngle);
    }
    Serial.print("改变方向：");
    Serial.println(moveAngle);
  }
  if (sensorL == 0 && sensorM == 0 && sensorR == 0) {
    lineFollowOffLineCount += 1;
    if (lineFollowOffLineCount > 1000) {
      carStop();
    }
  } else {
    lineFollowOffLineCount = 0;
  }
  moveAngle = moveAngle % 360;
  if (moveAngle < 0) {
    moveAngle += 360;
  }
}

void parallelObstacleFollowing() {
  bool sensor_values[5];  //定义五个传感器
  float us_dis;
  uint8_t i;
  ultrasonicRead();
  us_dis = ultrasonicRead();  //定义us_dis为超声波的测试距离
  for (i = 0; i < 5; i++) {
    sensor_values[i] =
        digitalRead(irObstaclePins[i]);  //定义传感器起为irObstaclePins[i]的读值
  }
  if (us_dis < ULTRASONIC_AVOIDANCE_THRESHOLD && us_dis > 10) {
    carMove(0, CAR_DEFAULT_POWER, 0);  //前进
  } else if (sensor_values[0] == 0) {
    carMove(60, CAR_DEFAULT_POWER, 0);  //右前进
  } else if (sensor_values[1] == 0) {
    carMove(120, CAR_DEFAULT_POWER, 0);  //右后退
  } else if (sensor_values[2] == 0) {
    carMove(180, CAR_DEFAULT_POWER, 0);  //后退
  } else if (sensor_values[3] == 0) {
    carMove(240, CAR_DEFAULT_POWER, 0);  //左后退
  } else if (sensor_values[4] == 0) {
    carMove(300, CAR_DEFAULT_POWER, 0);  //左前进
  } else if (us_dis < ULTRASONIC_AVOIDANCE_THRESHOLD && sensor_values[0] == 0) {
    carMove(45, CAR_DEFAULT_POWER, 0);  //右前进
  } else if (sensor_values[0] == 0 && sensor_values[1] == 0) {
    carMove(90, CAR_DEFAULT_POWER, 0);  //右转
  } else if (sensor_values[1] == 0 && sensor_values[2] == 0) {
    carMove(150, CAR_DEFAULT_POWER, 0);  //右后退
  } else if (sensor_values[2] == 0 && sensor_values[3] == 0) {
    carMove(210, CAR_DEFAULT_POWER, 0);  //左后退
  } else if (sensor_values[3] == 0 && sensor_values[4] == 0) {
    carMove(270, CAR_DEFAULT_POWER, 0);  //左转
  } else if (sensor_values[4] == 0 && us_dis < ULTRASONIC_AVOIDANCE_THRESHOLD) {
    carMove(330, CAR_DEFAULT_POWER, 0);  //左前进
  } else if (ULTRASONIC_AVOIDANCE_THRESHOLD < us_dis) {
    carMove(0, 0, 0);  //暂停
  }
}

// 平移避障
//      0
//    /
//   5-----1
//      /
//   4-----2
//       /
//      3
uint8_t loopOrder[6] = {0, 5, 1, 4, 2, 3};
uint8_t currentDir = 0;
void parallelObstacleAvoidance() {
  bool sensorValues[6];
  uint8_t i, j;
  // Read sensors
  sensorValues[0] = ultrasonicIsClear();
  for (i = 0; i < 5; i++) {
    sensorValues[i + 1] = digitalRead(irObstaclePins[i]);
  }
  // Check if current direction, current direction left and current direction
  // right is obstacled
  uint8_t currentDirLeft = (currentDir + 5) % 6;
  uint8_t currentDirRight = (currentDir + 1) % 6;
  Serial.print("currentDir: ");
  Serial.println(currentDir);
  Serial.print("current State: ");
  Serial.print(sensorValues[currentDirLeft]);
  Serial.print(" ");
  Serial.print(sensorValues[currentDir]);
  Serial.print(" ");
  Serial.println(sensorValues[currentDirRight]);
  if (sensorValues[currentDir] == 0 || sensorValues[currentDirLeft] == 0 ||
      sensorValues[currentDirRight] == 0) {
    Serial.println("obstacle");
    // Check if there is any direction is not obstacled, Skip 0 as it will interferes
    for (i = 1; i < 6; i++) {
      uint8_t index = loopOrder[i];
      // Add currentDir to transfer to the current direction
      index = (currentDir + i) % 6;
      // Check if the current direction is clear
      if (sensorValues[index] == 1) {
        // Update currentDir to the current direction
        currentDir = index;
        break;
      }
    }
  }
  // Move
  carMove(currentDir * 60, CAR_DEFAULT_POWER, 0);
}

void remoteControl(uint8_t key) {
  switch (key) {
    case IR_KEY_CYCLE:  // Turn Left
      remoteAngle = 0;
      remotePower = 0;
      remoteRot = CAR_DEFAULT_POWER;
      Serial.println("Turn Left");
      break;
    case IR_KEY_U_SD:  // Turn Right
      remoteAngle = 0;
      remotePower = 0;
      remoteRot = -CAR_DEFAULT_POWER;
      Serial.println("Turn Right");
      break;
    case IR_KEY_0: // Reset origin direction
      remoteAngle = 0;
      remotePower = 0;
      remoteRot = 0;
      carResetHeading();
      break;
    case IR_KEY_1:  // Left Forward
      remoteAngle = 315;
      remotePower = CAR_DEFAULT_POWER;
      remoteRot = 0;
      Serial.println("Left Forward");
      break;
    case IR_KEY_2:  // Forward
      remoteAngle = 0;
      remotePower = CAR_DEFAULT_POWER;
      remoteRot = 0;
      Serial.println("Forward");
      break;
    case IR_KEY_3:  // Right Forward
      remoteAngle = 45;
      remotePower = CAR_DEFAULT_POWER;
      remoteRot = 0;
      Serial.println("Right Forward");
      break;
    case IR_KEY_4:  // Left
      remoteAngle = 270;
      remotePower = CAR_DEFAULT_POWER;
      remoteRot = 0;
      Serial.println("Left");
      break;
    case IR_KEY_5:  // Stop
      remoteAngle = 0;
      remotePower = 0;
      remoteRot = 0;
      Serial.println("Stop");
      break;
    case IR_KEY_6:  // Right
      remoteAngle = 90;
      remotePower = CAR_DEFAULT_POWER;
      remoteRot = 0;
      Serial.println("Right");
      break;
    case IR_KEY_7:  // Left Backward
      remoteAngle = 225;
      remotePower = CAR_DEFAULT_POWER;
      remoteRot = 0;
      Serial.println("Left Backward");
      break;
    case IR_KEY_8:  // Backward
      remoteAngle = 180;
      remotePower = CAR_DEFAULT_POWER;
      remoteRot = 0;
      Serial.println("Backward");
      break;
    case IR_KEY_9:  // Right Backward
      remoteAngle = 135;
      remotePower = CAR_DEFAULT_POWER;
      remoteRot = 0;
      Serial.println("Right Backward");
      break;
    default:
      remoteAngle = 0;
      remotePower = 0;
      remoteRot = 0;
      Serial.println("Stop");
      break;
  }
}

void compassCalibrate() {
}
