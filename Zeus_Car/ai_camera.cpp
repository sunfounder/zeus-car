#include "ai_camera.h"
#include "car_control.h"
#include "rgb.h"

/**
 *  functions for manipulating string
 */
#define IsStartWith(str, prefix) (strncmp(str, prefix, strlen(prefix)) == 0)
#define StrAppend(str, suffix) \
  uint32_t len = strlen(str);  \
  str[len] = suffix;           \
  str[len + 1] = '\0'
#define StrClear(str) str[0] = 0

int32_t cmd_timeout = SERIAL_TIMEOUT;
int32_t ws_send_time = millis();
// int32_t ws_send_interval = 100;
int32_t ws_send_interval = 60;

/**
 * Declare global variables
 */
char name[25];
char type[25];

/**
 * Declare the receive callback function
 */
void (*__on_receive__)();

/**
 * @brief instantiate AiCamera Class, set name and type
 * @param _name set name
 * @param _type set type
 */
AiCamera::AiCamera(const char *_name, const char *_type)
{
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
void AiCamera::begin(const char *ssid, const char *password, const char *wifiMode, const char *wsPort)
{
#ifdef AI_CAM_DEBUG_CUSTOM
  DateSerial.begin(115200);
#endif
  char ip[25];
  char version[25];

  set_command_timeout(3000);
  this->get("RESET", version);
  DebugSerial.print(F("ESP32 firmware version "));
  DebugSerial.println(version);

  set_command_timeout(1000);
  this->set("NAME", name);
  this->set("TYPE", type);
  this->set("SSID", ssid);
  this->set("PSK", password);
  this->set("MODE", wifiMode);
  this->set("PORT", wsPort);

  set_command_timeout(5000);
  this->get("START", ip);
  delay(20);
  DebugSerial.print(F("WebServer started on ws://"));
  DebugSerial.print(ip);
  DebugSerial.print(F(":"));
  DebugSerial.println(wsPort);

  set_command_timeout(SERIAL_TIMEOUT);
}

/**
 * @brief Set callback function method
 *
 * @param func  callback function pointer
 */
void AiCamera::setOnReceived(void (*func)(char *, char *)) { __on_receive__ = func; }

/**
 * @brief Receive and process serial port data in a loop
 */
void AiCamera::loop()
{
  this->readInto(recvBuffer);
  if (strlen(recvBuffer) != 0)
  {
    // Serial.print("recv: ");Serial.println(recvBuffer);

    // ESP32-CAM reboot detection
    if (IsStartWith(recvBuffer, CAM_INIT))
    {
      Serial.println(F("ESP32-CAM reboot detected"));
      carStop();
      ws_connected = false;
    }
    // ESP32-CAM websocket connected
    else if (IsStartWith(recvBuffer, WS_CONNECT))
    {
      Serial.println(F("ESP32-CAM websocket connected"));
      ws_connected = true;
    }
    // ESP32-CAM websocket disconnected
    else if (IsStartWith(recvBuffer, WS_DISCONNECT))
    {
      Serial.println(F("ESP32-CAM websocket disconnected"));
      ws_connected = false;
    }
    // ESP32-CAM APP_STOP
    else if (IsStartWith(recvBuffer, APP_STOP))
    {
      if (ws_connected)
      {
        Serial.println(F("APP STOP"));
      }
      ws_connected = false;
    }
    // recv WS+ data
    else if (IsStartWith(recvBuffer, WS_HEADER))
    {
      // debug("RX:"); debug(recvBuffer);
      DateSerial.print("RX:");
      DateSerial.println(recvBuffer);
      ws_connected = true;
      this->subString(recvBuffer, strlen(WS_HEADER));
      if (__on_receive__ != NULL)
      {
        __on_receive__();
        // if (millis() - ws_send_time > ws_send_interval) {
        //   this->sendData();
        //   ws_send_time = millis();
        // }
      }
    }
    // send data
    // this->sendData();
    if (__on_receive__ != NULL)
    {
      if (millis() - ws_send_time > ws_send_interval)
      {
        this->sendData();
        ws_send_time = millis();
      }
    }
  }
}

/**
 * @brief Print the information received from esp32-CAm,
 *        according to the set of CAM_DEBUG_LEVEL
 *
 * @param msg Message to be detected
 */
void AiCamera::debug(char *msg)
{
#if (CAM_DEBUG_LEVEL == CAM_DEBUG_LEVEL_ALL) // all
  DebugSerial.print(CAM_DEBUG_HEAD_ALL);
  DebugSerial.println(msg);
#elif (CAM_DEBUG_LEVEL == CAM_DEBUG_LEVEL_ERROR) // error
  if (IsStartWith(msg, CAM_DEBUG_HEAD_ERROR))
  {
    DebugSerial.println(msg);
  }
#elif (CAM_DEBUG_LEVEL == CAM_DEBUG_LEVEL_INFO)  // info
  if (IsStartWith(msg, CAM_DEBUG_HEAD_ERROR))
  {
    DebugSerial.println(msg);
  }
  else if (IsStartWith(msg, CAM_DEBUG_HEAD_INFO))
  {
    DebugSerial.println(msg);
  }
#elif (CAM_DEBUG_LEVEL == CAM_DEBUG_LEVEL_DEBUG) // debug
  if (IsStartWith(msg, CAM_DEBUG_HEAD_ERROR))
  {
    DebugSerial.println(msg);
  }
  else if (IsStartWith(msg, CAM_DEBUG_HEAD_INFO))
  {
    DebugSerial.println(msg);
  }
  else if (IsStartWith(msg, CAM_DEBUG_HEAD_DEBUG))
  {
    DebugSerial.println(msg);
  }
#endif
}

/**
 * @brief Store the data read from the serial port into the buffer
 *
 * @param buffer  Pointer to the String value of the stored data
 */
void AiCamera::readInto(char *buffer)
{
  /* !!! attention buffer size*/
  bool finished = false;
  char inchar;
  StrClear(buffer);
  uint32_t count = 0;

  uint32_t char_time = millis();

  // recv Byte
  while (DateSerial.available())
  {
    count += 1;
    if (count > WS_BUFFER_SIZE)
    {
      finished = true;
      break;
    }
    inchar = (char)DateSerial.read();
    // Serial.print(inchar);
    if (inchar == '\n')
    {
      finished = true;
      // Serial.println(">");
      break;
    }
    else if (inchar == '\r')
    {
      continue;
    }
    else if ((int)inchar > 31 && (int)inchar < 127)
    {
      StrAppend(buffer, inchar);
      delay(1); // Wait for StrAppend
    }
  }

  // if recv debug info
  if (finished)
  {
    debug(buffer);
    if (IsStartWith(buffer, CAM_DEBUG_HEAD_DEBUG))
    {
#if (CAM_DEBUG_LEVEL == CAM_DEBUG_LEVEL_DEBUG) // all
      DebugSerial.print(CAM_DEBUG_HEAD_DEBUG);
      DebugSerial.println(buffer);
#endif
      StrClear(buffer);
    }
  }
}

/**
 * @brief Serial port sends data, automatically adds header (WS_HEADER)
 *
 * @param sendBuffer  Pointer to the character value of the data buffer to be sent
 */
void AiCamera::sendData()
{
  DateSerial.print(F(WS_HEADER));
  // send_doc["A"] = 0;
  serializeJson(send_doc, DateSerial);
  DateSerial.print("\n");
}

void AiCamera::set_command_timeout(uint32_t _timeout)
{
  cmd_timeout = _timeout;
}
/**
 * @brief Send command to ESP32-CAM with serial
 *
 * @param command command keyword
 * @param value
 * @param result returned information from serial
 */
void AiCamera::command(const char *command, const char *value, char *result, bool wait = true)
{
  bool is_ok = false;
  uint8_t retry_count = 0;
  uint8_t retry_max_count = 3;

  while (retry_count < retry_max_count)
  {
    if (retry_count == 0)
    {
      DateSerial.print(F("SET+"));
      DateSerial.print(command);
      DateSerial.println(value);
      DateSerial.print(F("..."));

      if (!wait)
        return; // if not waiting, return immediately
    }

    retry_count++;

    uint32_t st = millis();
    while ((millis() - st) < cmd_timeout)
    {
      this->readInto(recvBuffer);
      if (IsStartWith(recvBuffer, OK_FLAG))
      {
        is_ok = true;
        DateSerial.println(F(OK_FLAG));
        this->subString(recvBuffer, strlen(OK_FLAG) + 1); // Add 1 for Space
        // !!! Note that the reslut size here is too small and may be out of bounds,
        // causing unexpected data changes
        strcpy(result, recvBuffer);
        break;
      }
    }

    if (is_ok == true)
    {
      break;
    }
  }

  if (is_ok == false)
  {
    Serial.println(F("[FAIL]"));
    while (1)
      ;
  }
}

/**
 * @brief Use the comand() function to set up the ESP32-CAM
 *
 * @param command command keyword
 */
void AiCamera::set(const char *command, bool wait = true)
{
  char result[10];
  this->command(command, "", result, wait);
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
void AiCamera::set(const char *command, const char *value, bool wait = true)
{
  char result[10];
  this->command(command, value, result, wait);
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
void AiCamera::get(const char *command, char *result)
{
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
void AiCamera::get(const char *command, const char *value, char *result)
{
  this->command(command, value, result);
}

/**
 * @brief Interpret the value of the slider contorl component from the buf string
 *
 * @param buf string pointer to be interpreted
 * @param region the key of component
 * @return the value of the slider contorl component
 */
int16_t AiCamera::getSlider(uint8_t region)
{
  int16_t value = getIntOf(recvBuffer, region);
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
bool AiCamera::getButton(uint8_t region)
{
  bool value = getBoolOf(recvBuffer, region);
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
bool AiCamera::getSwitch(uint8_t region)
{
  bool value = getBoolOf(recvBuffer, region);
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
int16_t AiCamera::getJoystick(uint8_t region, uint8_t axis)
{
  char valueStr[20];
  int16_t x, y, angle, radius;
  getStrOf(recvBuffer, region, valueStr, ';');
  x = getIntOf(valueStr, 0, ',');
  y = getIntOf(valueStr, 1, ',');
  angle = atan2(x, y) * 180.0 / PI;
  radius = sqrt(y * y + x * x);
  switch (axis)
  {
  case JOYSTICK_X:
    return x;
  case JOYSTICK_Y:
    return y;
  case JOYSTICK_ANGLE:
    return angle;
  case JOYSTICK_RADIUS:
    return radius;
  default:
    return 0;
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
uint8_t AiCamera::getDPad(uint8_t region)
{
  char value[20];
  getStrOf(recvBuffer, region, value, ';');
  uint8_t result;
  if ((String)value == (String) "forward")
    result = DPAD_FORWARD;
  else if ((String)value == (String) "backward")
    result = DPAD_BACKWARD;
  else if ((String)value == (String) "left")
    result = DPAD_LEFT;
  else if ((String)value == (String) "right")
    result = DPAD_RIGHT;
  else if ((String)value == (String) "stop")
    result = DPAD_STOP;
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
int16_t AiCamera::getThrottle(uint8_t region)
{
  int16_t value = getIntOf(recvBuffer, region);
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
void AiCamera::getSpeech(uint8_t region, char *result)
{
  getStrOf(recvBuffer, region, result, ';');
}

/**
 * @brief Fill the value of Meter display component into the buf to be sent
 *
 * @param buf string pointer to be sent
 * @param region the key of component
 * @param value the value to be filled
 */
void AiCamera::setMeter(uint8_t region, double value)
{
  setStrOf(recvBuffer, region, String(value));
}

/**
 * @brief Fill the value of Radar display component into the buf to be sent
 *
 * @param buf string pointer to be sent
 * @param region the key of component
 * @param angle the orientation of the obstacle
 * @param distance the distance of the obstacle
 */
void AiCamera::setRadar(uint8_t region, int16_t angle, double distance)
{
  setStrOf(recvBuffer, region, String(angle) + "," + String(distance));
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
void AiCamera::setGreyscale(uint8_t region, uint16_t value1, uint16_t value2, uint16_t value3)
{
  setStrOf(recvBuffer, region, String(value1) + "," + String(value2) + "," + String(value3));
}

void AiCamera::setValue(uint8_t region, double value)
{
  setStrOf(recvBuffer, region, String(value));
}

/**
 * @brief subtract part of the string
 *
 * @param buf string pointer to be subtract
 * @param start start position of content to be subtracted
 * @param end end position of Content to be subtracted
 */
void AiCamera::subString(char *str, int16_t start, int16_t end)
{
  uint8_t length = strlen(str);
  if (end == -1)
  {
    end = length;
  }
  for (uint8_t i = 0; i < end; i++)
  {
    if (i + start < end)
    {
      str[i] = str[i + start];
    }
    else
    {
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
void AiCamera::getStrOf(char *str, uint8_t index, char *result, char divider)
{
  uint8_t start, end;
  uint8_t length = strlen(str);
  uint8_t i, j;

  // Get start index
  if (index == 0)
  {
    start = 0;
  }
  else
  {
    for (start = 0, j = 1; start < length; start++)
    {
      if (str[start] == divider)
      {
        if (index == j)
        {
          start++;
          break;
        }
        j++;
      }
    }
  }
  // Get end index
  for (end = start, j = 0; end < length; end++)
  {
    if (str[end] == divider)
    {
      break;
    }
  }
  // Copy result
  // if ((end - start + 2) > sizeof(result)) { // '\0' takes up one byte
  //   end = start + sizeof(result) -1;
  // }

  for (i = start, j = 0; i < end; i++, j++)
  {
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
void AiCamera::setStrOf(char *str, uint8_t index, String value, char divider = ';')
{
  uint8_t start, end;
  uint8_t length = strlen(str);
  uint8_t i, j;
  // Get start index
  if (index == 0)
  {
    start = 0;
  }
  else
  {
    for (start = 0, j = 1; start < length; start++)
    {
      if (str[start] == divider)
      {
        if (index == j)
        {
          start++;
          break;
        }
        j++;
      }
    }
  }
  // Get end index
  for (end = start, j = 0; end < length; end++)
  {
    if (str[end] == divider)
    {
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
int16_t AiCamera::getIntOf(char *str, uint8_t index, char divider = ';')
{
  int16_t result;
  char strResult[20];
  getStrOf(str, index, strResult, divider);
  result = String(strResult).toInt();
  return result;
}

bool AiCamera::getBoolOf(char *str, uint8_t index)
{
  char strResult[20];
  getStrOf(str, index, strResult, ';');
  return String(strResult).toInt();
}

double AiCamera::getDoubleOf(char *str, uint8_t index)
{
  double result;
  char strResult[20];
  getStrOf(str, index, strResult, ';');
  result = String(strResult).toDouble();
  return result;
}

/**
 * @brief Set ESP32-CAM lamp level
 *
 * @param level 0-10
 */
void AiCamera::lamp_on(uint8_t level)
{
  set("LAMP", (char *)String(level).c_str(), false);
}

void AiCamera::lamp_off(void)
{
  set("LAMP", "0", false);
}
