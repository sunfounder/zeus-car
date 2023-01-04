/*******************************************************************
 * APP control
 
  Use esp32-cam to communicate with the app via wifi to control the car
  
1. Note：
  when downloading the code, you need to set the switch on the expansion board to upload, 
  and when running, you need to set the switch to cam.
2. Firstly, set the wifi, name, etc., send the service command to esp32-cam, 
  esp32-cam will open the websocket server and communicate with app after 
  screensuccessfully connect to the wifi, and also open the webcam 
3. use the left stick to control the direction of movement, 
  the right stick to control the direction of the front of the car, 
  switch to control enable drift

******************************************************************/
#include <Arduino.h>
#include "rgb.h"
#include "car_control.h"
#include "ai_camera.h"

/** Configure Wifi AP mode，SSID, password*/
#define WIFI_MODE WIFI_MODE_AP
#define SSID "Zeus_Car"
#define PASSWORD "12345678"

/** Configure Wifi STA mode，SSID, password*/
// #define WIFI_MODE WIFI_MODE_STA
// #define SSID "xxxxxxxxxx"
// #define PASSWORD "xxxxxxxxxx"

/** Configure product name and type*/
#define NAME "Zeus_Car"
#define TYPE "Zeus_Car"

/* Configure websockets port
 * - Sunfounder Controller APP fixed using port 8765
*/
#define PORT "8765"

/** Instantiate aicamera, a class for serial communication with ESP32-CAM */
AiCamera aiCam = AiCamera(NAME, TYPE);

/*********************** Global variables ****************************/
int16_t remoteAngle;
int16_t remotePower;
int16_t remoteHeading;
int16_t remoteHeadingR;
bool remoteDriftEnable;

/*********************** setup() & loop() ************************/
void setup() {
  int m = millis();
  Serial.begin(115200);
  rgbBegin();
  rgbWrite(0xFF2500); // orange
  carBegin();
  
  aiCam.begin(SSID, PASSWORD, WIFI_MODE, PORT);
  aiCam.setOnReceived(onReceive);

  while (millis() - m < 500) { // Wait for peripherals to be ready
    delay(1);
  }

  Serial.println(F("Okie!"));
  rgbWrite(0x0AFF0A); // green
 
}

void loop() {
  aiCam.loop();
  carMoveFieldCentric(remoteAngle, remotePower, remoteHeading, remoteDriftEnable);

}

/***************************** Functions ******************************/
/**
 * websocket received data processing
 */
void onReceive(char* recvBuf, char* sendBuf) {

  //Joystick [K]
  uint16_t angle = aiCam.getJoystick(recvBuf, REGION_K, JOYSTICK_ANGLE);
  uint8_t power = aiCam.getJoystick(recvBuf, REGION_K, JOYSTICK_RADIUS);
  power = map(power, 0, 100, 0, CAR_DEFAULT_POWER);
  if (remoteAngle != angle) {
    remoteAngle = angle;
  }
  if (remotePower != power) {
    remotePower = power;
  }

  // Drift [J]
  // Serial.print("Drift:");Serial.println(remoteDriftEnable);
  if (remoteDriftEnable != aiCam.getSwitch(recvBuf, REGION_J)) {
    remoteDriftEnable = !remoteDriftEnable;
  }

  // MoveHead [Q]
  int moveHeadingA = aiCam.getJoystick(recvBuf, REGION_Q, JOYSTICK_ANGLE);
  int16_t moveHeadingR = aiCam.getJoystick(recvBuf, REGION_Q, JOYSTICK_RADIUS);
  if ((remoteHeading !=  moveHeadingA) || (remoteHeadingR !=  moveHeadingR)){
    remoteHeading = moveHeadingA;
    remoteHeadingR = moveHeadingR;
    if (remoteDriftEnable && moveHeadingR == 0) { // Drift mode
      carResetHeading();
      remoteHeading = 0;
    } 
  }

}
