#include "car_control.h"

#include <SoftPWM.h>  //PWM库
#include <Arduino.h>

Car::Car(int* motorPins, int* motorDirection) {
  this->motorPins = motorPins;
  this->motorDirection = motorDirection;
}

void Car::begin() {
  SoftPWMBegin();
  for (int i = 0; i < 8; i++) {
    SoftPWMSet(this->motorPins[i], 0);
    SoftPWMSetFadeTime(this->motorPins[i], 100, 100);
  }
}

void Car::forward() {  //前进
  setMotor(0, 100);
  setMotor(1, 100);
  setMotor(2, 100);
  setMotor(3, 100);
}
void Car::backward() {  //后退
  setMotor(0, -100);
  setMotor(1, -100);
  setMotor(2, -100);
  setMotor(3, -100);
}
void Car::left() {  //向左
  setMotor(0, -100);
  setMotor(1, 100);
  setMotor(2, -100);
  setMotor(3, 100);
}
void Car::right() {  //向右
  setMotor(0, 100);
  setMotor(1, -100);
  setMotor(2, 100);
  setMotor(3, -100);
}
void Car::turnLeft() {  //左旋转
  setMotor(0, 100);
  setMotor(1, -100);
  setMotor(2, -100);
  setMotor(3, 100);
}
void Car::turnRight() {  //右旋转
  setMotor(0, -100);
  setMotor(1, 100);
  setMotor(2, 100);
  setMotor(3, -100);
}
void Car::leftForword() {  //左前进
  setMotor(0, 100);
  setMotor(1, 0);
  setMotor(2, 100);
  setMotor(3, 0);
}
void Car::rightForword() {  //右前进
  setMotor(0, 0);
  setMotor(1, 100);
  setMotor(2, 0);
  setMotor(3, 100);
}
void Car::leftBackward() {  //左后退
  setMotor(0, 0);
  setMotor(1, -100);
  setMotor(2, 0);
  setMotor(3, -100);
}
void Car::rightBackward() {  //右后退
  setMotor(0, -100);
  setMotor(1, 0);
  setMotor(2, -100);
  setMotor(3, 0);
}
void Car::stop() {  //停止
  setMotor(0, 0);
  setMotor(1, 0);
  setMotor(2, 0);
  setMotor(3, 0);
}

void Car::setMotor(int motor, int power) {  //定义电机转向
  int a = motor * 2;
  int b = motor * 2 + 1;
  int dir = power > 0;
  if (motorDirection[motor]) dir = !dir;

  int newPower = map(abs(power), 0, 100, 0, 255);

  SoftPWMSet(motorPins[a], dir * newPower);
  SoftPWMSet(motorPins[b], !dir * newPower);
}

void Car::move(int angle, int power,
               int rot) {  //设置小车极坐标 int angle 》 角度 、int power 》
                           //速度 、int rot 》 弧度 --》定义电机运动方向
  int power_0, power_1, power_2, power_3;  //设置4个轮子的速度

  angle = angle % 360;  //角度限制在0-360
  if (angle < 0) { //角度限制在0-360
    angle += 360;
  }
  angle += 90;  //打印出来的值与实际相差90，需进行等比对换，变成我们需要的值
  float rad = angle * PI / 180;  // PI-->π转换

  // Calculate 4 wheel
  power_0 = power * sin(rad) + power * cos(rad) -
            rot;  // * (CAR_WIDTH+CAR_LENGTH);计算小车车轮行驶方向以及速度
  power_1 = power * sin(rad) - power * cos(rad) +
            rot;  // * (CAR_WIDTH+CAR_LENGTH);计算小车车轮行驶方向以及速度
  power_2 = power * sin(rad) + power * cos(rad) +
            rot;  // * (CAR_WIDTH+CAR_LENGTH);计算小车车轮行驶方向以及速度
  power_3 = power * sin(rad) - power * cos(rad) -
            rot;  // * (CAR_WIDTH+CAR_LENGTH);计算小车车轮行驶方向以及速度

  setMotor(0, power_0);  //电机行驶方向以及速度
  setMotor(1, power_1);  //电机行驶方向以及速度
  setMotor(2, power_2);  //电机行驶方向以及速度
  setMotor(3, power_3);  //电机行驶方向以及速度
}
