#include "ai_camera.h"
#include "car_control.h"

// Uncomment the following line to use STA mode
// #define mode = WIFI_MODE_STA;
// #define SSID = "***********";
// #define PASSWORD = "***********";

// Uncomment the following line to use AP mode
#define WIFI_MODE WIFI_MODE_AP
#define SSID "Flash"
#define PASSWORD "12345678"

#define CAMERA_MODE CAMERA_MODE_STREAM
#define PORT "8765"

#define CAR_DEFAULT_POWER 40

int motorDirection[] = {1, 0, 0, 1};
int motorPins[8] = {2, 3, 4, 5, 6, 7, 8, 9};

AiCamera aiCam = AiCamera("Flash", "Flash");
Car car = Car(motorPins, motorDirection);

void on_receive() {
  Serial.print("Slider D: ");Serial.println(aiCam.getSlider("D"));
  Serial.print("Switch J: ");Serial.println(aiCam.getSwitch("J"));
  Serial.print("Button I: ");Serial.println(aiCam.getButton("I"));
  Serial.print("Joystick Q X: ");Serial.println(aiCam.getJoystick("Q", JOYSTICK_X));
  Serial.print("Joystick Q Y: ");Serial.println(aiCam.getJoystick("Q", JOYSTICK_Y));
  Serial.print("Throttle K: ");Serial.println(aiCam.getThrottle("K"));
  aiCam.setMeter("H", 46);
  aiCam.setRadar("B", 20, 30);
  aiCam.setGreyscale("A", 300, 234, 678);
  aiCam.setValue("C", 498);
}

void setup() {
  Serial.begin(115200);
  aiCam.begin(SSID, PASSWORD, WIFI_MODE, PORT, CAMERA_MODE);
  aiCam.setOnReceived(on_receive);
  car.begin();
}

void loop() {
  aiCam.loop();
  delay(10);
}