#include "qmc6309.h"

int16_t _calibrationData6309[6];

int16_t _x6309;
int16_t _y6309;
int16_t _z6309;

QMC6309::QMC6309() {
}

bool QMC6309::init() {
  Wire.begin();
  Wire.setWireTimeout(100000, true); // 100ms

  // Probe addresses: try 0x7C first, then 0x0C
  Wire.beginTransmission(QMC6309_ADDR_PRIMARY);
  if (Wire.endTransmission() == 0) {
    _addr = QMC6309_ADDR_PRIMARY;
  } else {
    Wire.beginTransmission(QMC6309_ADDR_SECONDARY);
    if (Wire.endTransmission() == 0) {
      _addr = QMC6309_ADDR_SECONDARY;
    } else {
      return false;
    }
  }

  // Soft reset
  this->_i2cWrite(QMC6309_REG_CONTROL_2, QMC6309_VAL_SOFT_RST_ON);
  delay(100);
  this->_i2cWrite(QMC6309_REG_CONTROL_2, QMC6309_VAL_SOFT_RST_OFF);

  // Configure CTL_2: SET_RESET_ON, 8G range, 200Hz ODR
  this->_i2cWrite(QMC6309_REG_CONTROL_2,
    QMC6309_VAL_MODE_SET_RESET_ON | QMC6309_VAL_RNG_8G | QMC6309_VAL_ODR_200HZ);

  // Configure CTL_1: NORMAL mode, OSR1=8, OSR2=8
  this->_i2cWrite(QMC6309_REG_CONTROL_1,
    QMC6309_VAL_MODE_NORMAL | QMC6309_VAL_OSR1_8 | QMC6309_VAL_OSR2_8);

  return true;
}

void QMC6309::read() {
  byte datas[6];
  bool result = this->_i2cReadInto(QMC6309_REG_DATA_START, 6, datas);
  if (result == false) return;

  _x6309 = (int16_t)((datas[1] << 8) | datas[0]);
  _y6309 = (int16_t)((datas[3] << 8) | datas[2]);
  _z6309 = (int16_t)((datas[5] << 8) | datas[4]);

  // calibrate:
  if (this->_calibrated) {
    int x_offset = (_calibrationData6309[0] + _calibrationData6309[1]) / 2;
    int y_offset = (_calibrationData6309[2] + _calibrationData6309[3]) / 2;
    int z_offset = (_calibrationData6309[4] + _calibrationData6309[5]) / 2;
    float x_avg = (_calibrationData6309[1] - _calibrationData6309[0]) / 2.0;
    float y_avg = (_calibrationData6309[3] - _calibrationData6309[2]) / 2.0;
    float z_avg = (_calibrationData6309[5] - _calibrationData6309[4]) / 2.0;

    float avg = (x_avg + y_avg + z_avg) / 3;

    float x_scale = avg / x_avg;
    float y_scale = avg / y_avg;
    float z_scale = avg / z_avg;

    _x6309 = (int16_t)((_x6309 - x_offset) * x_scale);
    _y6309 = (int16_t)((_y6309 - y_offset) * y_scale);
    _z6309 = (int16_t)((_z6309 - z_offset) * z_scale);
  }
}

int16_t QMC6309::getX() {return _x6309;}
int16_t QMC6309::getY() {return _y6309;}
int16_t QMC6309::getZ() {return _z6309;}

uint16_t QMC6309::getAzimuth() {
  int16_t azimuth = atan2(_y6309, _x6309) * RAD_TO_DEG;
  if (azimuth < 0) azimuth += 360;
  return azimuth;
}

void QMC6309::clearCalibration() {
  this->_calibrated = false;
}

void QMC6309::setCalibration(int xMin, int xMax, int yMin, int yMax, int zMin, int zMax) {
  this->_calibrated = true;
  _calibrationData6309[0] = xMin;
  _calibrationData6309[1] = xMax;
  _calibrationData6309[2] = yMin;
  _calibrationData6309[3] = yMax;
  _calibrationData6309[4] = zMin;
  _calibrationData6309[5] = zMax;
}

void QMC6309::_i2cWrite(byte reg, byte val) {
  Wire.beginTransmission(_addr);
  Wire.write(reg);
  Wire.write(val);
  Wire.endTransmission();
}

bool QMC6309::_i2cReadInto(byte reg, byte num, byte* dest) {
  Wire.beginTransmission(_addr);
  Wire.write(reg);
  uint8_t result = Wire.endTransmission(true);

  if (result != 0) {
    return false;
  }

  uint8_t rec_len = Wire.requestFrom(_addr, num, true);
  if (rec_len != num) {
    return false;
  }

  int m = millis();
  while(Wire.available() < num) {
    if (millis() - m > 200) {
      return false;
    }
  }

  for(int i = 0; i < num; i++) {
    dest[i] = Wire.read();
  }

  return true;
}
