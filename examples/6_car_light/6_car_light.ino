/*******************************************************************
 * car_light
 
  Control the color of the rgb light bars via the remote.
  - key 1 to 9 ：red, orange, yellow, green, cyan, blue, purple, pink, white 
  - key 0 ： turn off 
  - key CYCLE : color gradient  
******************************************************************/
#include <Arduino.h>
#include <SoftPWM.h>
#include "ir_remote.h"

/** Indicate whether RGB leds are common-anodes or not 
 * - 0 common cathode
 * - 1 common anode
*/
#define COMMON_ANODE 0

/** Set the pins of RGB leds, the order is R,G,B */
#define RGB_PINS (uint8_t[3]){12, 13, 11}

/* Define the color of the response for different keys */
const uint8_t key_color_array[9][3] {
  {255, 0, 0}, // red
  {255, 165, 0}, // orange
  {255, 255, 0},  // yellow
  {0, 255, 0},  // green
  {0, 127, 255},  // cyan
  {0, 0, 255}, // blue
  {139, 0, 255}, // purple
  {255, 128, 255}, // pink
  {255, 255, 255}, // white
};

void rgbBegin();
void rgbWrite(uint32_t color);
void rgbWrite(uint8_t r, uint8_t g, uint8_t b);
void rgbOff();
void color_gradient();


void setup() {
  Serial.begin(115200);
  irBegin();
  SoftPWMBegin(); //init softpwm, before the rgb LEDs initialization
  rgbBegin(); // init rgb LEDs
}

void loop() {
  

  uint8_t key = irRead();
  if (key != IR_KEY_ERROR) {
    if (key < 16) {
      Serial.print("0x0");Serial.println(key, HEX);
    } else {
      Serial.print("0x");Serial.println(key, HEX);
    }
  }

  switch (key) {
    case IR_KEY_ERROR:
      break;
    case IR_KEY_1:
      color_show(0);
      break;
    case IR_KEY_2:
      color_show(1);
      break;
    case IR_KEY_3:
      color_show(2);
      break;
    case IR_KEY_4:
      color_show(3);
      break;
    case IR_KEY_5:
      color_show(4);
      break;
    case IR_KEY_6:
      color_show(5);
      break;
    case IR_KEY_7:
      color_show(6);
      break;
    case IR_KEY_8:
      color_show(7);
      break;
    case IR_KEY_9:
      color_show(8);
      break;
    case IR_KEY_0:
      rgbOff();
      break;
    case IR_KEY_CYCLE:
      color_gradient();
      break;
    default:
      break;
  }
}

/** Initialize RGB leds */
void rgbBegin() {
  for (uint8_t i = 0; i < 3; i++) {
    SoftPWMSet(RGB_PINS[i], 0);
    SoftPWMSetFadeTime(RGB_PINS[i], 100, 100);
  }
}

/** Set LED color in HEX */
void rgbWrite(uint32_t color) {
  uint8_t r = (color >> 16) & 0xFF;
  uint8_t g = (color >>  8) & 0xFF;
  uint8_t b = (color >>  0) & 0xFF;
  rgbWrite(r, g, b);
}

/** Set LED color in 8bit R,G,B (0 ~ 255)*/
void rgbWrite(uint8_t r, uint8_t g, uint8_t b) {
  #if COMMON_ANODE
    r = 255 - r;
    g = 255 - g;
    b = 255 - b;
  #endif
  SoftPWMSet(RGB_PINS[0], r);
  SoftPWMSet(RGB_PINS[1], g);
  SoftPWMSet(RGB_PINS[2], b);
}

/** Turn odd RGB LEDs*/
void rgbOff() {
  rgbWrite(0, 0, 0);
}

void color_show(uint8_t index) {
  uint8_t r = key_color_array[index][0];
  uint8_t g = key_color_array[index][1];
  uint8_t b = key_color_array[index][2];
  
  Serial.print("r:"); Serial.print(r);
  Serial.print(" ,g:"); Serial.print(g);
  Serial.print(" ,b:"); Serial.println(b);

  rgbWrite(r, g, b);
  delay(20);
}

/* color_gradient 
 * Gradient of RGB LEDs,
 * [255, 0, 255·to·0]
 * [255, 0·to·255, 0]
 * [255·to·0, 255, 0]
 * [0, 255, 0·to·255]
 * [0, 255·to·0, 255]
 * [0·to·255, 0, 255]
 * 
*/
void color_gradient() {
  uint8_t rgb[3] = {0, 0, 0};
  Serial.println("color_gradient");

  for (uint8_t i = 0; i < 3; i++) {
    // Note that "j" needs to use int16_t
    for (int16_t j = 255; j >= 0; j--) {
      rgb[i] = 255;
      rgb[(i+2)%3] = j;
      Serial.print("r:"); Serial.print(rgb[0]);
      Serial.print(" ,g:"); Serial.print(rgb[1]);
      Serial.print(" ,b:"); Serial.println(rgb[2]);
      rgbWrite(rgb[0], rgb[1], rgb[2]);
      delay(5);
    }
    for (int16_t j = 0; j <= 255; j++) {
      rgb[i] = 255;
      rgb[(i+1)%3] = j;
      Serial.print("r:"); Serial.print(rgb[0]);
      Serial.print(" ,g:"); Serial.print(rgb[1]);
      Serial.print(" ,b:"); Serial.println(rgb[2]);
      rgbWrite(rgb[0], rgb[1], rgb[2]);
      delay(5);
    }
  } 
}


