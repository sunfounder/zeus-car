#include "compass.h"
#include <EEPROM.h>
#include "qmc6310.h"
#include "qmc6309.h"

#define CHIP_NONE 0
#define CHIP_6310 1
#define CHIP_6309 2

QMC6310 _compass6310;
QMC6309 _compass6309;
uint8_t _chip_type = CHIP_NONE;

int16_t heading;
int calibrationData[6];
#if (AVERAGE_FILTER)
int16_t filterBuffer[AVERAGE_FILTER_SIZE];
uint8_t filterBufferIndex = 0;
int32_t filterBufferSum = 0;
#endif
uint32_t calibrate_c;
uint32_t calibrate_t;
bool calibrateChanged;
bool calibrateDone = true;


/**
 * @brief Clear value of compass Calibration
 *
 */
void compassClearCalibration() {
  for (uint8_t i = 0; i < 6; i++) {
    calibrationData[i] = 0;
    EEPROM.write(EEPROM_CALIBRATION_ADDRESS + 2 * i, 0);
    EEPROM.write(EEPROM_CALIBRATION_ADDRESS + 2 * i + 1, 0);
  }
  if (_chip_type == CHIP_6309) {
    _compass6309.clearCalibration();
  } else {
    _compass6310.clearCalibration();
  }
}

/**
 * @brief Save value of compass Calibration
 *
 */
void compassSaveCalibration() {
  for (int i = 0; i < 6; i++) {
    uint16_t data = calibrationData[i] + 0xFF;
    uint8_t highByte = data >> 8;
    uint8_t lowByte = data & 0xFF;
    EEPROM.write(EEPROM_CALIBRATION_ADDRESS + 2 * i, highByte);
    EEPROM.write(EEPROM_CALIBRATION_ADDRESS + 2 * i + 1, lowByte);
  }
  if (_chip_type == CHIP_6309) {
    _compass6309.setCalibration(
      calibrationData[0],
      calibrationData[1],
      calibrationData[2],
      calibrationData[3],
      calibrationData[4],
      calibrationData[5]
    );
  } else {
    _compass6310.setCalibration(
      calibrationData[0],
      calibrationData[1],
      calibrationData[2],
      calibrationData[3],
      calibrationData[4],
      calibrationData[5]
    );
  }
}

/**
 * @brief Read value of compass Calibration
 *
 */
void compassReadCalibration() {
  uint8_t highByte, lowByte;
  for (uint8_t i = 0; i < 6; i++) {
    highByte = EEPROM.read(EEPROM_CALIBRATION_ADDRESS + 2 * i);
    lowByte = EEPROM.read(EEPROM_CALIBRATION_ADDRESS + 2 * i + 1);
    long data = (highByte << 8) | lowByte;
    calibrationData[i] = data - 0xFF;
  }

  if (_chip_type == CHIP_6309) {
    _compass6309.setCalibration(
      calibrationData[0],
      calibrationData[1],
      calibrationData[2],
      calibrationData[3],
      calibrationData[4],
      calibrationData[5]
    );
  } else {
    _compass6310.setCalibration(
      calibrationData[0],
      calibrationData[1],
      calibrationData[2],
      calibrationData[3],
      calibrationData[4],
      calibrationData[5]
    );
  }
}


/**
 * @brief Is compass Calibrate Done ?
 *
 * @return  - true
 *          - false
 *
 */
bool compassCalibrateDone() {
  return calibrateDone;
}

/**
 * @brief Start calibrate compass
 *
 */
void compassCalibrateStart() {
  compassClearCalibration();
  calibrate_c = millis();
  calibrate_t = calibrate_c;
  calibrateChanged = false;
  calibrateDone = false;

  if (_chip_type == CHIP_6309) {
    _compass6309.read();
    calibrationData[0] = _compass6309.getX();
    calibrationData[1] = _compass6309.getX();
    calibrationData[2] = _compass6309.getY();
    calibrationData[3] = _compass6309.getY();
    calibrationData[4] = _compass6309.getZ();
    calibrationData[5] = _compass6309.getZ();
  } else {
    _compass6310.read();
    calibrationData[0] = _compass6310.getX();
    calibrationData[1] = _compass6310.getX();
    calibrationData[2] = _compass6310.getY();
    calibrationData[3] = _compass6310.getY();
    calibrationData[4] = _compass6310.getZ();
    calibrationData[5] = _compass6310.getZ();
  }
}

/**
 * @brief The loop of  compass calibration
 *
 */
bool compassCalibrateLoop() {
  if (calibrateDone) {
    return false;
  }
  calibrateChanged = false;

  int x, y, z;
  if (_chip_type == CHIP_6309) {
    _compass6309.read();
    x = _compass6309.getX();
    y = _compass6309.getY();
    z = _compass6309.getZ();
  } else {
    _compass6310.read();
    x = _compass6310.getX();
    y = _compass6310.getY();
    z = _compass6310.getZ();
  }

  if (x < calibrationData[0]) {
    calibrationData[0] = x;
    calibrateChanged = true;
  } else if (x > calibrationData[1]) {
    calibrationData[1] = x;
    calibrateChanged = true;
  }

  if (y < calibrationData[2]) {
    calibrationData[2] = y;
    calibrateChanged = true;
  } else if (y > calibrationData[3]) {
    calibrationData[3] = y;
    calibrateChanged = true;
  }

  if (z < calibrationData[4]) {
    calibrationData[4] = z;
    calibrateChanged = true;
  } else if (z > calibrationData[5]) {
    calibrationData[5] = z;
    calibrateChanged = true;
  }

  if (calibrateChanged) {
    calibrate_c = millis();
  }
  calibrate_t = millis();
  if (calibrate_t - calibrate_c > CALIBRATION_TIME) {
    compassSaveCalibration();
    calibrateDone = true;
  }
  return calibrateChanged;
}

/**
 * @brief Read the average filtered value of compass angle
 *
 * @return int16_t average angle
 */
int16_t compassReadAngle() {
  if (_chip_type == CHIP_6309) {
    _compass6309.read();
  } else {
    _compass6310.read();
  }
  int16_t value = compassGetAzimuth();

  #if (AVERAGE_FILTER)
    filterBufferSum = filterBufferSum - filterBuffer[filterBufferIndex] + value;
    filterBuffer[filterBufferIndex] = value;
    filterBufferIndex++;
    if (filterBufferIndex >= AVERAGE_FILTER_SIZE) filterBufferIndex = 0;
    value = filterBufferSum / AVERAGE_FILTER_SIZE;
  #endif

  return value;
}

/**
 * @brief Calculate the angle from the values in the x, y direction of the compass sensor
 *
 * @return int16_t angle
 */
int16_t compassGetAzimuth() {
  if (_chip_type == CHIP_6309) {
    _compass6309.read();
    int16_t y = _compass6309.getY();
    int16_t z = _compass6309.getZ();
    int heading = atan2(y, -z) * RAD_TO_DEG;
    return heading;
  } else {
    _compass6310.read();
    int16_t y = _compass6310.getY();
    int16_t z = _compass6310.getZ();
    int heading = atan2(y, -z) * RAD_TO_DEG;
    return heading;
  }
}

/**
 * @brief Compass init — auto-detect QMC6310 or QMC6309
 *
 */
void compassBegin() {
  // Auto-detect: try QMC6310 at 0x1C first, then QMC6309 at 0x7C / 0x0C
  Wire.begin();
  Wire.beginTransmission(0x1C);
  if (Wire.endTransmission() == 0) {
    _chip_type = CHIP_6310;
    _compass6310.init();
  } else {
    Wire.beginTransmission(0x7C);
    if (Wire.endTransmission() == 0) {
      _chip_type = CHIP_6309;
      _compass6309.init();
    } else {
      Wire.beginTransmission(0x0C);
      if (Wire.endTransmission() == 0) {
        _chip_type = CHIP_6309;
        _compass6309.init();
      }
    }
  }

  compassReadCalibration();
  for (uint8_t i = 0; i < AVERAGE_FILTER_SIZE; i++) {
    compassReadAngle();
  }
}
