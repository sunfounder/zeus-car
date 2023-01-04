#include "ai_camera.h"

/**
* Use custom serial port
*/
// #define AI_CAM_DEBUG_CUSTOM
#ifdef AI_CAM_DEBUG_CUSTOM
  #include <SoftwareSerial.h>
  SoftwareSerial dSerial(10, 11); // RX, TX
  #define DateSerial dSerial
  #define DebugSerial Serial
#else
  #define DateSerial Serial
  #define DebugSerial Serial
#endif

/**
*  Set SERIAL_TIMEOUT & WS_BUFFER_SIZE
*/
#define SERIAL_TIMEOUT 100
#define WS_BUFFER_SIZE 100

/**
* Some keywords for communication with ESP32-CAM
*/
#define CHECK "SC"
#define OK_FLAG "[OK]"
#define ERROR_FLAG "[ERR]"
#define WS_HEADER "WS+"
#define CAM_INIT "[Init]"

/**
*  functions for manipulating string 
*/
#define IsStartWith(str, prefix) (strncmp(str, prefix, strlen(prefix)) == 0)
#define StrAppend(str, suffix) uint32_t len=strlen(str); str[len] = suffix; str[len+1] = '\0'
#define StrClear(str) str[0] = 0

/**
* Declare global variables
*/
char name[32];
char type[32];
char readBuffer[WS_BUFFER_SIZE + strlen(WS_HEADER)];

/**
* Declare the receive callback function
*/
void (*__on_receive__)(char*, char*);

/**
 * @brief instantiate AiCamera Class, set name and type
 * @param _name set name
 * @param _type set type
 */
AiCamera::AiCamera(const char* _name, const char* _type) {
  strcpy(name, _name);
  strcpy(type, _type);
}

/**
 * @brief Set wifi and websocket port to esp32-cam, 
 *        block and wait for the setting to succeed
 *        
 * @param ssid  wifi ssid
 * @param password wifi password
 * @param wifiMode  0,None; 1, STA; 2, AP
 * @param wsPort websocket server port
 */
void AiCamera::begin(const char* ssid, const char* password, const char* wifiMode, const char* wsPort) {
  #ifdef AI_CAM_DEBUG_CUSTOM
  DateSerial.begin(115200);
  #endif
  char ip[15];
  // this->set("RESET");
  this->set("NAME", name);
  this->set("TYPE", type);
  this->set("SSID", ssid);
  this->set("PSK",  password);
  this->set("MODE", wifiMode);
  this->set("PORT", wsPort);
  this->get("START", ip);
  DebugSerial.print(F("WebServer started on ws://"));
  DebugSerial.print(ip);
  DebugSerial.print(F(":"));
  DebugSerial.println(wsPort);
}

/**
 * @brief Set callback function method
 *         
 * @param func  callback function pointer
 */
void AiCamera::setOnReceived(void (*func)(char*, char*)) { __on_receive__ = func; }


/**
 * @brief Receive and process serial port data in a loop
 */
void AiCamera::loop() {
  char recvBuffer[WS_BUFFER_SIZE + strlen(WS_HEADER)];
  char sendBuffer[WS_BUFFER_SIZE] = ";;;;;;;;;;;;;;;;;;;;;;;;;";
  this->readInto(recvBuffer);
  if (strlen(recvBuffer) != 0) {
    // ESP32-CAM reboot detection
    if (IsStartWith(recvBuffer, CAM_INIT)) {
      Serial.println(F("ESP32-CAM reboot detected"));
      while(1);
    }

    if (IsStartWith(recvBuffer, WS_HEADER)) {
      Serial.println(recvBuffer);
      this->subString(recvBuffer, strlen(WS_HEADER));
      if (__on_receive__ != NULL) {
        __on_receive__(recvBuffer, sendBuffer);
      }
    }
  this->sendData(sendBuffer);
  }
}


/**
 * @brief Print the information received from esp32-CAm,
 *        according to the set of CAM_DEBUG_LEVEL
 *         
 * @param msg Message to be detected
 */
void AiCamera::debug(char* msg) {
  #if (CAM_DEBUG_LEVEL ==  CAM_DEBUG_LEVEL_ALL) // all
    DebugSerial.print(CAM_DEBUG_HEAD_ALL);
    DebugSerial.println(msg);
  #elif (CAM_DEBUG_LEVEL ==  CAM_DEBUG_LEVEL_ERROR)  // error
    if (IsStartWith(msg, CAM_DEBUG_HEAD_ERROR)) {
      DebugSerial.println(msg);  
    }
  #elif (CAM_DEBUG_LEVEL ==  CAM_DEBUG_LEVEL_INFO)  // info
    if (IsStartWith(msg, CAM_DEBUG_HEAD_ERROR)) {
      DebugSerial.println(msg);  
    }else if (IsStartWith(msg, CAM_DEBUG_HEAD_INFO)) {
      DebugSerial.println(msg);  
    }
  #elif (CAM_DEBUG_LEVEL ==  CAM_DEBUG_LEVEL_DEBUG) // debug
    if (IsStartWith(msg, CAM_DEBUG_HEAD_ERROR)) {
      DebugSerial.println(msg);  
    }else if (IsStartWith(msg, CAM_DEBUG_HEAD_INFO)) {
      DebugSerial.println(msg);  
    }else if (IsStartWith(msg, CAM_DEBUG_HEAD_DEBUG)) {
      DebugSerial.println(msg);  
    }
  #endif
}

/** 
 * @brief Store the data read from the serial port into the buffer
 *       
 * @param buffer  Pointer to the character value of the stored data
 */
void AiCamera::readInto(char* buffer) {
  bool finished = false;
  char incomingChar;
  StrClear(buffer);
  uint32_t count = 0;

  // recv Byte
  while (DateSerial.available()) {
    count += 1;
    if (count > WS_BUFFER_SIZE) {
      // Serial.print(F("count = ")); Serial.println(count);  
      // rgbWrite(0, 0, 0);
      // while (1);
      finished = true;
      break;
    }

    incomingChar = (char)DateSerial.read();
    if (incomingChar == '\n') {
      finished = true;
      break;
    } else if (incomingChar == '\r') {
      continue;
    } else if ((int)incomingChar > 31 && (int)incomingChar < 127) {
      StrAppend(readBuffer, incomingChar);
    }
  }
  // recv finished
  if (finished) {
    debug(readBuffer);
    if (IsStartWith(readBuffer, CAM_DEBUG_HEAD_DEBUG)) {
      #if (CAM_DEBUG_LEVEL ==  CAM_DEBUG_LEVEL_DEBUG) // all
        DebugSerial.print(CAM_DEBUG_HEAD_DEBUG);
        DebugSerial.println(readBuffer);
      #endif
      StrClear(buffer);
    }else{
      strcpy(buffer, readBuffer);
    }
    StrClear(readBuffer);
  }
}

/** 
 * @brief Serial port sends data, automatically adds header (WS_HEADER)
 *         
 * @param sendBuffer  Pointer to the character value of the data buffer to be sent
 */
void AiCamera::sendData(char* sendBuffer) {
  DateSerial.print(F(WS_HEADER));
  DateSerial.println(sendBuffer);
}

/** 
 * @brief Send command to ESP32-CAM with serial
 *         
 * @param command command keyword
 * @param value
 * @param result returned information from serial
 */
void AiCamera::command(const char* command, const char* value, char* result) {
  bool is_ok = false;
  while(1) {
    DateSerial.print("SET+");
    DateSerial.print(command);
    DateSerial.println(value);

    while (1) {
      this->readInto(result);
      if (IsStartWith(result, OK_FLAG)){
        is_ok = true;
        this->subString(result, strlen(OK_FLAG) + 1); // Add 1 for Space
        break;
      }
    }

    if(is_ok == true) {
      break;
    }
  }
}

/** 
 * @brief Use the comand() function to set up the ESP32-CAM
 * 
 * @param command command keyword
 */
void AiCamera::set(const char* command) {
  char result[10];
  this->command(command, "", result);
}

/** 
 * @brief Use the comand() function to set up the ESP32-CAM
 * 
 * @param command command keyword
 * @param value
 * 
 * @code {.cpp}
 * set("NAME", "Zeus_Car");
 * set("TYPE", "Zeus_Car");
 * set("SSID", "Zeus_Car");
 * set("PSK",  "12345678");
 * set("MODE", WIFI_MODE_AP);
 * set("PORT", "8765");
 * @endcode
 * 
 */
void AiCamera::set(const char* command, const char* value) {
  char result[10];
  this->command(command, value, result);
}

/** 
 * @brief Use the comand() function to set up the ESP32-CAM,
 *        and receive return information
 * 
 * @param command command keyword
 * @param value
 * @param result returned information from serial
 * @code {.cpp}
 * char ip[15];
 * get("START", ip);
 * @endcode
 */
void AiCamera::get(const char* command, char* result) {
  this->command(command, "", result);
}

/** 
 * @brief Use the comand() function to set up the ESP32-CAM,
 *        and receive return information
 * 
 * @param command command keyword
 * @param value
 * @param result returned information from serial
 */
void AiCamera::get(const char* command, const char* value, char* result) {
  this->command(command, value, result);
}


/** 
 * @brief Interpret the value of the slider contorl component from the buf string
 *         
 * @param buf string pointer to be interpreted  
 * @param region the key of component
 * @return the value of the slider contorl component 
 */
int16_t AiCamera::getSlider(char* buf, uint8_t region) {
  int16_t value = getIntOf(buf, region);
  return value;
}

/** 
 * @brief Interpret the value of the Button component from the buf string
 *         
 * @param buf string pointer to be interpreted  
 * @param region the key of component
 * @return the value of the Joystick component
 *        - true
 *        - flase 
 */
bool AiCamera::getButton(char* buf, uint8_t region) {
  bool value = getBoolOf(buf, region);
  return value;
}

/** 
 * @brief Interpret the value of the getSwitch component from the buf string
 *         
 * @param buf string pointer to be interpreted  
 * @param region the key of component
 * @return the value of the Joystick component
 *        - true
 *        - flase 
 */
bool AiCamera::getSwitch(char* buf, uint8_t region) {
  bool value = getBoolOf(buf, region);
  return value;
}

/** 
 * @brief Interpret the value of the Joystick component from the buf string
 *         
 * @param buf string pointer to be interpreted  
 * @param region the key of component
 * @param axis which type of value that you want, 
 *             could be JOYSTICK_X, JOYSTICK_Y, JOYSTICK_ANGLE, JOYSTICK_RADIUS
 * @return the value of the Joystick component 
 */
int16_t AiCamera::getJoystick(char* buf, uint8_t region, uint8_t axis) {
  char valueStr[10];
  char xStr[4];
  char yStr[4];
  int16_t x, y, angle, radius;
  getStrOf(buf, region, valueStr, ';');
  x = getIntOf(valueStr, 0, ',');
  y = getIntOf(valueStr, 1, ',');
  angle = atan2(x, y) * 180.0 / PI;
  radius = sqrt(y * y + x * x);
  switch (axis) {
    case JOYSTICK_X: return x;
    case JOYSTICK_Y: return y;
    case JOYSTICK_ANGLE: return angle;
    case JOYSTICK_RADIUS: return radius;
    default: return 0;
  }
}

/** 
 * @brief Interpret the value of the DPad component from the buf string
 *         
 * @param buf string pointer to be interpreted  
 * @param region the key of component
 * 
 * @return the value of the DPadDPad component, 
 *         it could be null, "forward", "backward", "left", "stop"
 */
uint8_t AiCamera::getDPad(char* buf, uint8_t region) {
  char value[10];
  getStrOf(buf, region, value, ';');
  uint8_t result;
  if ((String)value == (String)"forward") result = DPAD_FORWARD;
  else if ((String)value == (String)"backward") result = DPAD_BACKWARD;
  else if ((String)value == (String)"left") result = DPAD_LEFT;
  else if ((String)value == (String)"right") result = DPAD_RIGHT;
  else if ((String)value == (String)"stop") result = DPAD_STOP;
  return result;
}

/** 
 * @brief Interpret the value of the Throttle component from the buf string
 *         
 * @param buf string pointer to be interpreted  
 * @param region the key of component
 * 
 * @return the value of the Throttle component, 
 */
int16_t AiCamera::getThrottle(char* buf, uint8_t region) {
  int16_t value = getIntOf(buf, region);
  return value;
}

/** 
 * @brief Interpret the value of the Speech component from the buf string
 *         
 * @param buf string pointer to be interpreted  
 * @param region the key of component
 * @param result char array pointer to hold the result
 * @return the value of the Joystick component 
 */
void AiCamera::getSpeech(char* buf, uint8_t region, char* result) {
  getStrOf(buf, region, result, ';');

}

/** 
 * @brief Fill the value of Meter display component into the buf to be sent
 *         
 * @param buf string pointer to be sent  
 * @param region the key of component
 * @param value the value to be filled
 */
void AiCamera::setMeter(char* buf, uint8_t region, double value) {
  setStrOf(buf, region, String(value));
}

/** 
 * @brief Fill the value of Radar display component into the buf to be sent
 *         
 * @param buf string pointer to be sent  
 * @param region the key of component
 * @param angle the orientation of the obstacle
 * @param distance the distance of the obstacle
 */
void AiCamera::setRadar(char* buf, uint8_t region, int16_t angle, double distance) {
  setStrOf(buf, region, String(angle) + "," + String(distance));
}

/** 
 * @brief Fill the value of 3-way grayscale display component into the buf to be sent
 *         
 * @param buf string pointer to be sent  
 * @param region the key of component
 * @param value1 
 * @param value2  
 * @param value3  
 */
void AiCamera::setGreyscale(char* buf, uint8_t region, uint16_t value1, uint16_t value2, uint16_t value3) {
  setStrOf(buf, region, String(value1) + "," + String(value2) + "," + String(value3));
}


void AiCamera::setValue(char* buf, uint8_t region, double value) {
  setStrOf(buf, region, String(value));
}


/** 
 * @brief subtract part of the string
 *         
 * @param buf string pointer to be subtract  
 * @param start start position of content to be subtracted
 * @param end end position of Content to be subtracted
 */
void AiCamera::subString(char* str, int16_t start, int16_t end) {
  uint8_t length = strlen(str);
  if (end == -1) {
    end = length;
  }
  for (uint8_t i = 0; i < end; i++) {
    if (i + start < end) {
      str[i] = str[i + start];
    } else {
      str[i] = '\0';
    }
  }
}

/** 
 * @brief Split the string by a cdivider,
 *         and return characters of the selected index
 *
 * @param buf string pointer to be split  
 * @param index which index do you wish to return
 * @param result char array pointer to hold the result
 * @param divider
 */
void AiCamera::getStrOf(char* str, uint8_t index, char* result, char divider) {
  uint8_t start, end;
  uint8_t length = strlen(str);
  uint8_t i, j;
  // Get start index
  if (index == 0) {
    start = 0;
  } else {
    for (start = 0, j = 1; start < length; start++) {
      if (str[start] == divider) {
        if (index == j) {
          start++;
          break;
        }
        j++;
      }
    }
  }
  // Get end index
  for (end = start, j = 0; end < length; end++) {
    if (str[end] == divider) {
      break;
    }
  }
  // Copy result
  for (i = start, j = 0; i < end; i++, j++) {
    result[j] = str[i];
  }
  result[j] = '\0';
}

/** 
 * @brief split by divider, filling the value to a position in the string
 *         
 * @param str string pointer to be operated  
 * @param index which index do you wish to return
 * @param value the value to be filled
 * @param divider
 */
void AiCamera::setStrOf(char* str, uint8_t index, String value, char divider=';') {
  uint8_t start, end;
  uint8_t length = strlen(str);
  uint8_t i, j;
  // Get start index
  if (index == 0) {
    start = 0;
  } else {
    for (start = 0, j = 1; start < length; start++) {
      if (str[start] == divider) {
        if (index == j) {
          start++;
          break;
        }
        j++;
      }
    }
  }
  // Get end index
  for (end = start, j = 0; end < length; end++) {
    if (str[end] == divider) {
      break;
    }
  }
  String strString = str;
  String strValue = strString.substring(0, start) + value + strString.substring(end);
  strcpy(str, strValue.c_str());
}

/** 
 * @brief Split the string by a cdivider,
 *         and return characters of the selected index.
 *         Further, the content is converted to int type.
 *
 * @param buf string pointer to be split  
 * @param index which index do you wish to return
 * @param divider
 */
int16_t AiCamera::getIntOf(char* str, uint8_t index, char divider=';') {
  int16_t result;
  char strResult[6];
  getStrOf(str, index, strResult, divider);
  result = String(strResult).toInt();
  return result;
}

bool AiCamera::getBoolOf(char* str, uint8_t index) {
  char strResult[5];
  getStrOf(str, index, strResult, ';');
  return String(strResult).toInt();
}

double AiCamera::getDoubleOf(char* str, uint8_t index) {
  double result;
  char strResult[20];
  getStrOf(str, index, strResult, ';');
  result = String(strResult).toDouble();
  return result;
}
