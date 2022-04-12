#include "compass.h"
#include <QMC5883LCompass.h>
#include <EEPROM.h>

uint16_t heading;
int calibrationData[6];
#if (AVERAGE_FILTER)
uint16_t filterBuffer[AVERAGE_FILTER_SIZE];
uint8_t filterBufferIndex = 0;
#endif
uint32_t calibrate_c;
uint32_t calibrate_t;
bool calibrateChanged;
bool calibrateDone = true;

QMC5883LCompass qmc5883l;

void compassClearCalibration() {
  for (uint8_t i = 0; i < 6; i++) {
    calibrationData[i] = 0;
    EEPROM.write(EEPROM_CALIBRATION_ADDRESS + 2 * i, 0);
    EEPROM.write(EEPROM_CALIBRATION_ADDRESS + 2 * i + 1, 0);
  }
  // qmc5883l.setCalibration(0, 0, 0, 0, 0, 0);
}

void compassSaveCalibration() {
  Serial.println("Saving calibration data...");
  for (int i = 0; i < 6; i++) {
    uint16_t data = calibrationData[i] + 0xFF;
    uint8_t highByte = data >> 8;
    uint8_t lowByte = data & 0xFF;
    // Serial.print("Index: ");
    // Serial.print(i);
    // Serial.print(" HighByte: ");
    // Serial.print(highByte);
    // Serial.print(" LowByte: ");
    // Serial.println(lowByte);
    EEPROM.write(EEPROM_CALIBRATION_ADDRESS + 2 * i, highByte);
    EEPROM.write(EEPROM_CALIBRATION_ADDRESS + 2 * i + 1, lowByte);
  }
  qmc5883l.setCalibration(
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
  qmc5883l.setCalibration(
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
}

void compassCalibrateLoop() {
  // Serial.println("Compass Reading...");
  if (calibrateDone) {
    return;
  }
  calibrateChanged = false;
  qmc5883l.read();
  int x = qmc5883l.getX();
  int y = qmc5883l.getY();
  int z = qmc5883l.getZ();
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
    Serial.println("Calibrate Data Updated... Keep moving your sensor around.");
    calibrate_c = millis();
  }
  calibrate_t = millis();
  if (calibrate_t - calibrate_c > CALIBRATION_TIME) {
    Serial.println("Calibratiion finished!");
    Serial.print("calibration data(");
    Serial.print(calibrationData[0]);
    Serial.print(", ");
    Serial.print(calibrationData[1]);
    Serial.print(", ");
    Serial.print(calibrationData[2]);
    Serial.print(", ");
    Serial.print(calibrationData[3]);
    Serial.print(", ");
    Serial.print(calibrationData[4]);
    Serial.print(", ");
    Serial.print(calibrationData[5]);
    Serial.println(");");

    compassSaveCalibration();
    calibrateDone = true;
  }
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

uint16_t compassReadAngle() {
  qmc5883l.read();
  #if (AVERAGE_FILTER)
  uint16_t heading = qmc5883l.getAzimuth();
  compassFilterBufferAppend(heading);
  uint16_t sum = 0;
  for (uint8_t i = 0; i < AVERAGE_FILTER_SIZE; i++) {
    sum += filterBuffer[i];
  }
  return sum / AVERAGE_FILTER_SIZE;
  #else
  return qmc5883l.getAzimuth();
  #endif
}

void compassBegin() {
  qmc5883l.init();
  // qmc5883l.setCalibration(-1120, 843, -1302, 747, 0, 492);
  // delay(2000);
  compassReadCalibration();
  // Serial.println("Compass read calibration done");
  for (uint8_t i = 0; i < AVERAGE_FILTER_SIZE; i++) {
    compassReadAngle();
    // delay(10);
  }
}
