#include "compass.h"
#include <EEPROM.h>

// #include <QMC5883LCompass.h>
// QMC5883LCompass _compass;
#include "qmc6310.h"
QMC6310 _compass;

uint16_t heading;
int calibrationData[6];
#if (AVERAGE_FILTER)
int16_t filterBuffer[AVERAGE_FILTER_SIZE];
uint8_t filterBufferIndex = 0;
#endif
uint32_t calibrate_c;
uint32_t calibrate_t;
bool calibrateChanged;
bool calibrateDone = true;


void compassClearCalibration() {
  for (uint8_t i = 0; i < 6; i++) {
    calibrationData[i] = 0;
    EEPROM.write(EEPROM_CALIBRATION_ADDRESS + 2 * i, 0);
    EEPROM.write(EEPROM_CALIBRATION_ADDRESS + 2 * i + 1, 0);
  }
  _compass.clearCalibration();
}

void compassSaveCalibration() {
  // Serial.println("Saving calibration data...");
  for (int i = 0; i < 6; i++) {
    uint16_t data = calibrationData[i] + 0xFF;
    uint8_t highByte = data >> 8;
    uint8_t lowByte = data & 0xFF;
    EEPROM.write(EEPROM_CALIBRATION_ADDRESS + 2 * i, highByte);
    EEPROM.write(EEPROM_CALIBRATION_ADDRESS + 2 * i + 1, lowByte);
  }
  _compass.setCalibration(
    calibrationData[0], 
    calibrationData[1], 
    calibrationData[2], 
    calibrationData[3], 
    calibrationData[4], 
    calibrationData[5]
  );
}

void compassReadCalibration() {
  uint8_t highByte, lowByte;
  // Serial.println("Reading calibrationData value from EEPROM");
  for (uint8_t i = 0; i < 6; i++) {
    highByte = EEPROM.read(EEPROM_CALIBRATION_ADDRESS + 2 * i);
    lowByte = EEPROM.read(EEPROM_CALIBRATION_ADDRESS + 2 * i + 1);
    long data = (highByte << 8) | lowByte;
    calibrationData[i] = data - 0xFF;
  }
  // Serial.print("calibrationData data(");
  // Serial.print(calibrationData[0]);
  // Serial.print(", ");
  // Serial.print(calibrationData[1]);
  // Serial.print(", ");
  // Serial.print(calibrationData[2]);
  // Serial.print(", ");
  // Serial.print(calibrationData[3]);
  // Serial.print(", ");
  // Serial.print(calibrationData[4]);
  // Serial.print(", ");
  // Serial.print(calibrationData[5]);
  // Serial.println(");");
  _compass.setCalibration(
    calibrationData[0],
    calibrationData[1],
    calibrationData[2],
    calibrationData[3],
    calibrationData[4],
    calibrationData[5]
  );
}

bool compassCalibrateDone() {
  return calibrateDone;
}

void compassCalibrateStart() {
  compassClearCalibration();
  calibrate_c = millis();
  calibrate_t = calibrate_c;
  calibrateChanged = false;
  calibrateDone = false;
  _compass.read();
  calibrationData[0] = _compass.getX();
  calibrationData[1] = _compass.getX();
  calibrationData[2] = _compass.getY();
  calibrationData[3] = _compass.getY();
  calibrationData[4] = _compass.getZ();
  calibrationData[5] = _compass.getZ();
}

bool compassCalibrateLoop() {
  // Serial.println("Compass Reading...");
  if (calibrateDone) {
    return;
  }
  calibrateChanged = false;
  _compass.read();
  int x = _compass.getX();
  int y = _compass.getY();
  int z = _compass.getZ();

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
    // Serial.println("Calibrate Data Updated... Keep moving your sensor around.");
    calibrate_c = millis();
  }
  calibrate_t = millis();
  if (calibrate_t - calibrate_c > CALIBRATION_TIME) {
    // Serial.println("Calibratiion finished!");
    // Serial.print("calibration data(");
    // Serial.print(calibrationData[0]);
    // Serial.print(", ");
    // Serial.print(calibrationData[1]);
    // Serial.print(", ");
    // Serial.print(calibrationData[2]);
    // Serial.print(", ");
    // Serial.print(calibrationData[3]);
    // Serial.print(", ");
    // Serial.print(calibrationData[4]);
    // Serial.print(", ");
    // Serial.print(calibrationData[5]);
    // Serial.println(");");

    compassSaveCalibration();
    calibrateDone = true;
  }
  return calibrateChanged;
}

#if (AVERAGE_FILTER)
void compassFilterBufferAppend(uint16_t value) {
  filterBuffer[filterBufferIndex] = value;
  filterBufferIndex++;
  if (filterBufferIndex >= AVERAGE_FILTER_SIZE) {
    filterBufferIndex = 0;
  }
}
#endif

int16_t compassReadAngle() {
  _compass.read();
  #if (AVERAGE_FILTER)
  uint16_t heading = compassGetAzimuth();
  compassFilterBufferAppend(heading);
  uint16_t sum = 0;
  for (uint8_t i = 0; i < AVERAGE_FILTER_SIZE; i++) {
    sum += filterBuffer[i];
  }
  return sum / AVERAGE_FILTER_SIZE;
  #else
  return compassGetAzimuth();
  #endif
}

int16_t compassGetAzimuth() {
  _compass.read();
  int16_t y = _compass.getY();
  int16_t z = _compass.getZ();
  int heading = atan2(y, -z) * RAD_TO_DEG;
  return heading;
}

void compassBegin() {
  _compass.init();
  compassReadCalibration();
  // Serial.println("Compass read calibration done");
  for (uint8_t i = 0; i < AVERAGE_FILTER_SIZE; i++) {
    compassReadAngle();
  }
}
