
#ifndef __CAR_CONTROL_H__
#define __CAR_CONTROL_H__

#define CAR_WIDTH  14.76/2      //定义宽度
#define CAR_LENGTH  11.48/2     //定义长度

// [0]-------[1]
//  |         |
//  |         |
//  |         |
//  |         |
// [3]-------[2]

class Car{
  public:
    Car(int* pins, int* directions);
    void begin();
    void setMotor(int motor, int power);
    void setMotors(int power1, int power2, int power3, int power4)
    void forward();
    void backward();
    void turnLeft();
    void turnRight();
    void leftForword();
    void rightForword();
    void leftBackward();
    void rightBackward();
    void left();
    void right();
    void stop();
    void move(int angle, int power,int rot);
  
  private:
    int* motorPins;
    int* motorDirection;
};


#endif // __CAR_CONTROL_H__