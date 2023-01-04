/*******************************************************************
 * APP control
 
  Use esp32-cam to communicate with the app via wifi to control the car
  
1. Note：
  when downloading the code, you need to set the switch on the expansion board to upload, 
  and when running, you need to set the switch to cam.
2. Firstly, set the wifi, name, etc., send the service command to esp32-cam, 
  esp32-cam will open the websocket server and communicate with app after 
  screensuccessfully connect to the wifi, and also open the webcam 

******************************************************************/
#include <Arduino.h>
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




/*********************** setup() & loop() ************************/
void setup() {

  Serial.begin(115200);
  
  aiCam.begin(SSID, PASSWORD, WIFI_MODE, PORT);
  aiCam.setOnReceived(onReceive);


 
}

void loop() {
  aiCam.loop();
}

/***************************** Functions ******************************/
/**
 * websocket received data processing
 */
void onReceive(char* recvBuf, char* sendBuf) {

  }

