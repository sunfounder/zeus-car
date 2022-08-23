#ifndef __ULTRASONIC_H__
#define __ULTRASONIC_H__

//To save IO ports, echo and tring share an identical pin
#define ULTRASONIC_TRIG_PIN 10
#define ULTRASONIC_ECHO_PIN 10

#define ULTRASONIC_AVOIDANCE_THRESHOLD 20
#define ULTRASONIC_FOLLOW_THRESHOLD 30
#define ULTRASONIC_STOP_THRESHOLD 10

float ultrasonicRead();
bool ultrasonicIsObstacle();
bool ultrasonicIsClear();

#endif // __ULTRASONIC_H__
