/*******************************************************************
 * ultrasonic
  
  Read the value of two ultrasonic module

  - To save Io, echo and string share one pin

******************************************************************/
#include <Arduino.h>
#include <SoftPWM.h>

/** Set pins of ultrasonic 
 * To save IO ports, echo and tring could share an identical pin
*/
#define ULTRASONIC_TRIG_PIN 10
#define ULTRASONIC_ECHO_PIN 10

/** Configure ultrasonic obstacle avoidance distance, unit cm */
#define ULTRASONIC_AVOIDANCE_THRESHOLD 20
#define MAX_DISTANCE 2000 // unit: cm 

void setup() {
  Serial.begin(115200);
  SoftPWMBegin();

}

void loop() {
  float distance = ultrasonicRead();
  Serial.print("distance: ");Serial.print(distance);
  bool is_obstacle = ultrasonicIsObstacle();
  Serial.print("  is_obstacle: ");Serial.println(is_obstacle);
  delay(200);
}

/** Return the distance read by the ultrasonic module, unit cm */
float ultrasonicRead() {
  delay(4); // A delay is required between consecutive readings, otherwise the reading may be 0
  
  pinMode(ULTRASONIC_TRIG_PIN, OUTPUT);
  digitalWrite(ULTRASONIC_TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRASONIC_TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_TRIG_PIN, LOW);
  pinMode(ULTRASONIC_ECHO_PIN, INPUT);
  
  // noInterrupts(); // Pause all interruptions to avoid affecting data
                // However，turning off interrupts affects the functionality of softpwm, such as motors

  float duration = pulseIn(ULTRASONIC_ECHO_PIN, HIGH);
  float distance = duration  * 0.017; // S = vt = 340m/s * t_us / 2= (340 * 100 cm/s) * 0.5 * (t / 10^6)s = 0.017 * t (divided by 2 (go and back))
  
  // interrupts(); // resume interruptions

  if (distance > MAX_DISTANCE) {  
    return -1;
  }
  return distance;
}


/** Determine whether there is an obstacle ahead according to the set ULTRASONIC_AVOIDANCE_THRESHOLD */
bool ultrasonicIsObstacle() {
  return ultrasonicRead() < ULTRASONIC_AVOIDANCE_THRESHOLD;
}

/** Determine whether there is clear ahead according to the set ULTRASONIC_AVOIDANCE_THRESHOLD */
bool ultrasonicIsClear() {
  return ultrasonicRead() > ULTRASONIC_AVOIDANCE_THRESHOLD;
}
