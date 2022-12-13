#include "qmc6310.h"

int16_t _calibrationData[6];

int16_t _x;
int16_t _y;
int16_t _z;

QMC6310::QMC6310() {
}

void QMC6310::init() {
	Wire.begin();
  Wire.setWireTimeout(100000, true); // 100ms
  
  this->_i2cWrite(0x29, 0x06);
  this->_i2cWrite(QMC6310_REG_CONTROL_2, QMC6310_VAL_RNG_8G);
  this->_i2cWrite(QMC6310_REG_CONTROL_1, QMC6310_VAL_MODE_NORMAL | QMC6310_VAL_ODR_200HZ | QMC6310_VAL_OSR1_8 | QMC6310_VAL_OSR2_8);

}

void QMC6310::read() {
  byte datas[6];
  bool result = this->_i2cReadInto(QMC6310_REG_DATA_START, 6, datas);
  if (result == false) return;

  _x = (int16_t)((datas[1] << 8) | datas[0]);
  _y = (int16_t)((datas[3] << 8) | datas[2]);
  _z = (int16_t)((datas[5] << 8) | datas[4]);

  // calibrate:
  if (this->_calibrated) {
    int x_offset = (_calibrationData[0] + _calibrationData[1]) / 2;
    int y_offset = (_calibrationData[2] + _calibrationData[3]) / 2;
    int z_offset = (_calibrationData[4] + _calibrationData[5]) / 2;
    float x_avg = (_calibrationData[1] - _calibrationData[0]) / 2.0;
    float y_avg = (_calibrationData[3] - _calibrationData[2]) / 2.0;
    float z_avg = (_calibrationData[5] - _calibrationData[4]) / 2.0;

    float avg = (x_avg + y_avg + z_avg) / 3;

    float x_scale = avg / x_avg; 
    float y_scale = avg / y_avg;
    float z_scale = avg / z_avg;

    _x = (int16_t)((_x - x_offset) * x_scale);
    _y = (int16_t)((_y - y_offset) * y_scale);
    _z = (int16_t)((_z - z_offset) * z_scale);
  }
}

int16_t QMC6310::getX() {return _x;}
int16_t QMC6310::getY() {return _y;}
int16_t QMC6310::getZ() {return _z;}

uint16_t QMC6310::getAzimuth() {
	// int16_t azimuth = atan2(_y, _x) * 180.0 / PI;
	int16_t azimuth = atan2(_y, _x) * RAD_TO_DEG;
  if (azimuth < 0) azimuth += 360;
	return azimuth;
}

void QMC6310::clearCalibration() {
  this->_calibrated = false;
}

void QMC6310::setCalibration(int xMin, int xMax, int yMin, int yMax, int zMin, int zMax) {
  this->_calibrated = true;
  _calibrationData[0] = xMin;
  _calibrationData[1] = xMax;
  _calibrationData[2] = yMin;
  _calibrationData[3] = yMax;
  _calibrationData[4] = zMin;
  _calibrationData[5] = zMax;
}

void QMC6310::_i2cWrite(byte reg, byte val) {
  Wire.beginTransmission(QMC6310_ADDR);
  Wire.write(reg);
  Wire.write(val);
  Wire.endTransmission();
}

bool QMC6310::_i2cReadInto(byte reg, byte num, byte* dest) {
  Wire.beginTransmission(QMC6310_ADDR);
  Wire.write(reg);
  uint8_t result = Wire.endTransmission(true);
  /*
  Wire.endTransmission();
  0: success.
  1: data too long to fit in transmit buffer.
  2: received NACK on transmit of address.
  3: received NACK on transmit of data.
  4: other error.
  5: timeout
  */
  if (result != 0) {
    return false;
  }

  uint8_t rec_len = Wire.requestFrom(QMC6310_ADDR, num, true);
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
