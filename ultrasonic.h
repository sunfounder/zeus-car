#ifndef __ULTRASONIC_H__
#define __ULTRASONIC_H__

class Ultrasonic{
  public:
    Ultrasonic(int echo, int trig);
    Ultrasonic(int pin);
    void begin();
    float read();
    bool isObstacle();
    bool isClear();
    void setRef(int ref);
  private:
    int echo;
    int trig;
    int ref;
};

#endif // __ULTRASONIC_H__