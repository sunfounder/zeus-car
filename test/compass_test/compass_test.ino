
#include "car_control.h"
// #include "ai_camera.h"

// #define WIFI_MODE WIFI_MODE_AP
// #define SSID "AIC_Test"
// #define PASSWORD "12345678"


// #define CAMERA_MODE CAMERA_MODE_STREAM
// #define PORT "8765"

// AiCamera aiCam = AiCamera("aiCam", "aiCam");

int motorDirection[] = {1, 0, 0, 1};
int motorPins[8] = {2, 3, 4, 5, 6, 7, 8, 9};

Car car = Car(motorPins, motorDirection);

void setup() {
  Serial.begin(115200);
  car.begin();
  // aiCam.begin(SSID, PASSWORD, WIFI_MODE, PORT, CAMERA_MODE);
}

void loop() {
  car.move(45, 60, 0);
  // testPower();
}

void testPower() {
  for (int i=0; i<100; i++) {
    Serial.print(i);
    Serial.print(" ");
    Serial.println(map(i, 0, 100, 0, 255));

    car.setMotors(i, i, i, i);
    delay(1000);
  }
}