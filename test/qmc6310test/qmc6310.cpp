#include "qmc6310.h"

QMC6310::QMC6310() {
  this->_x = 0;
  this->_y = 0;
  this->_z = 0;
}

void QMC6310::init() {
	Wire.begin();
  // According to the datasheet, 7.1 Define the sign for X Y and Z axis
  this->_i2cWrite(0x29, 0x06);
  this->_i2cWrite(QMC6310_REG_CONTROL_2, QMC6310_VAL_RNG_8G);
  this->_i2cWrite(QMC6310_REG_CONTROL_1, QMC6310_VAL_MODE_NORMAL | QMC6310_VAL_ODR_200HZ | QMC6310_VAL_OSR1_8 | QMC6310_VAL_OSR2_8);
}

void QMC6310::read() {
  byte datas[6];
  this->_i2cReadInto(QMC6310_REG_DATA_START, 6, datas);
  this->_x = (int16_t)((datas[1] << 8) | datas[0]);
  this->_y = (int16_t)((datas[3] << 8) | datas[2]);
  this->_z = (int16_t)((datas[5] << 8) | datas[4]);

  // calibrate:
  if (this->_calibrated) {
    int x_offset = (this->_calibrationData[0] + this->_calibrationData[1]) / 2;
    int y_offset = (this->_calibrationData[2] + this->_calibrationData[3]) / 2;
    int z_offset = (this->_calibrationData[4] + this->_calibrationData[5]) / 2;
    float x_avg = (this->_calibrationData[1] - this->_calibrationData[0]) / 2.0;
    float y_avg = (this->_calibrationData[3] - this->_calibrationData[2]) / 2.0;
    float z_avg = (this->_calibrationData[5] - this->_calibrationData[4]) / 2.0;

    float avg = (x_avg + y_avg + z_avg) / 3;

    float x_scale = avg / x_avg; 
    float y_scale = avg / y_avg;
    float z_scale = avg / z_avg;

    this->_x = (int)((this->_x - x_offset) * x_scale);
    this->_y = (int)((this->_y - y_offset) * y_scale);
    this->_z = (int)((this->_z - z_offset) * z_scale);
  }
}

int QMC6310::getX() {return this->_x;}
int QMC6310::getY() {return this->_y;}
int QMC6310::getZ() {return this->_z;}

int QMC6310::getAzimuth() {
	// int azimuth = atan2(this->_y, this->_x) * 180.0 / PI;
	int azimuth = atan2(this->_x, this->_y) * 180.0 / PI;
  if (azimuth < 0) azimuth += 360;
	return azimuth;
}

void QMC6310::setCalibration(int xMin, int xMax, int yMin, int yMax, int zMin, int zMax) {
  this->_calibrated = true;
  this->_calibrationData[0] = xMin;
  this->_calibrationData[1] = xMax;
  this->_calibrationData[2] = yMin;
  this->_calibrationData[3] = yMax;
  this->_calibrationData[4] = zMin;
  this->_calibrationData[5] = zMax;
}

void QMC6310::_i2cWrite(byte reg, byte val) {
  Wire.beginTransmission(QMC6310_ADDR);
  Wire.write(reg);
  Wire.write(val);
  Wire.endTransmission();
}

void QMC6310::_i2cReadInto(byte reg, byte num, byte* dest) {
  Wire.beginTransmission(QMC6310_ADDR);
  Wire.write(reg);
  Wire.endTransmission();
  Wire.requestFrom(QMC6310_ADDR, num);
  while(Wire.available() < num);
  for(int i = 0; i < num; i++) {
    dest[i] = Wire.read();
  }
}