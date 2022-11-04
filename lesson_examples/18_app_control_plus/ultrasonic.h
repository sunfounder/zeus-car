#ifndef __ULTRASONIC_H__
#define __ULTRASONIC_H__

/** Set pins of ultrasonic 
 * |To save IO ports, echo and tring could share an identical pin
*/
#define ULTRASONIC_TRIG_PIN 10
#define ULTRASONIC_ECHO_PIN 10

/** Configure ultrasonic obstacle avoidance distance, unit cm */
#define ULTRASONIC_AVOIDANCE_THRESHOLD 20

#define MAX_DISTANCE 2000 // unit: cm 

/** Return the distance read by the ultrasonic module, unit cm */
float ultrasonicRead();

/** Determine whether there is an obstacle ahead according to the set ULTRASONIC_AVOIDANCE_THRESHOLD */
bool ultrasonicIsObstacle();

/** Determine whether there is clear ahead according to the set ULTRASONIC_AVOIDANCE_THRESHOLD */
bool ultrasonicIsClear();

#endif // __ULTRASONIC_H__
