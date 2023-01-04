#ifndef __AI_CAMERA_H__
#define __AI_CAMERA_H__

#include <Arduino.h>
#include <string.h>


/**
 * @name Set the print level of information received by esp32-cam
 *
 * @code {.cpp}
 * #define CAM_DEBUG_LEVEL CAM_DEBUG_LEVEL_INFO
 * @endcode
 * 
 */
#define CAM_DEBUG_LEVEL CAM_DEBUG_LEVEL_INFO
#define CAM_DEBUG_LEVEL_OFF 0
#define CAM_DEBUG_LEVEL_ERROR 1
#define CAM_DEBUG_LEVEL_INFO 2
#define CAM_DEBUG_LEVEL_DEBUG 3
#define CAM_DEBUG_LEVEL_ALL 4

#define CAM_DEBUG_HEAD_ALL "[CAM_A]"
#define CAM_DEBUG_HEAD_ERROR "[CAM_E]"
#define CAM_DEBUG_HEAD_INFO "[CAM_I]"
#define CAM_DEBUG_HEAD_DEBUG "[CAM_D]"

/**
 * @name Define component-related values
 */
#define DPAD_STOP     0
#define DPAD_FORWARD  1
#define DPAD_BACKWARD 2
#define DPAD_LEFT     3
#define DPAD_RIGHT    4

#define JOYSTICK_X       0
#define JOYSTICK_Y       1
#define JOYSTICK_ANGLE   2
#define JOYSTICK_RADIUS  3

#define WIFI_MODE_NONE "0"
#define WIFI_MODE_STA  "1"
#define WIFI_MODE_AP   "2"

#define REGION_A 0
#define REGION_B 1
#define REGION_C 2
#define REGION_D 3
#define REGION_E 4
#define REGION_F 5
#define REGION_G 6
#define REGION_H 7
#define REGION_I 8
#define REGION_J 9
#define REGION_K 10
#define REGION_L 11
#define REGION_M 12
#define REGION_N 13
#define REGION_O 14
#define REGION_P 15
#define REGION_Q 16
#define REGION_R 17
#define REGION_S 18
#define REGION_T 19
#define REGION_U 20
#define REGION_V 21
#define REGION_W 22
#define REGION_X 23
#define REGION_Y 24
#define REGION_Z 25


class AiCamera {
  public:
    AiCamera(const char* name, const char* type);

    void begin(const char* ssid, const char* password, const char* wifiMode, const char* wsPort);
    void debug(char* msg);
    void readInto(char* buffer);
    void sendData(char* buf);
    void command(const char* command, const char* value, char* result) ;
    void set(const char* command);
    void set(const char* command, const char* value);
    void get(const char* command, char* result);
    void get(const char* command, const char* value, char* result);
    void setOnReceived(void (*func)(char*, char*));
    void loop();

    int16_t getSlider(char* buf, uint8_t region);
    bool getButton(char* buf, uint8_t region);
    bool getSwitch(char* buf, uint8_t region);
    int16_t getJoystick(char* buf, uint8_t region, uint8_t axis);
    uint8_t getDPad(char* buf, uint8_t region);
    int16_t getThrottle(char* buf, uint8_t region);
    void setMeter(char* buf, uint8_t region, double value);
    void setRadar(char* buf, uint8_t region, int16_t angle, double distance);
    void setGreyscale(char* buf, uint8_t region, uint16_t value1, uint16_t value2, uint16_t value3);
    void setValue(char* buf, uint8_t region, double value);
    void getSpeech(char* buf, uint8_t region, char* result);

  private:
    void subString(char* str, int16_t start, int16_t end=-1);
    void getStrOf(char* str, uint8_t index, char* result, char divider);
    void setStrOf(char* str, uint8_t index, String value, char divider=';');
    int16_t getIntOf(char* str, uint8_t index, char divider=';');
    bool getBoolOf(char* str, uint8_t index);
    double getDoubleOf(char* str, uint8_t index);
};

#endif // __AI_CAMERA_H__
