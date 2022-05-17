#ifndef __QMC6310_H__
#define __QMC6310_H__

#include <Wire.h>
#include <Arduino.h>

#define QMC6310_ADDR 0x1C

#define QMC6310_REG_DATA_START 0x01
#define QMC6310_REG_STATUS     0x09
#define QMC6310_REG_CONTROL_1  0x0A
#define QMC6310_REG_CONTROL_2  0x0B

#define QMC6310_VAL_MODE_SUSPEND    0 << 0
#define QMC6310_VAL_MODE_NORMAL     1 << 0
#define QMC6310_VAL_MODE_SINGLE     2 << 0
#define QMC6310_VAL_MODE_CONTINUOUS 3 << 0

#define QMC6310_VAL_ODR_10HZ  0 << 2
#define QMC6310_VAL_ODR_50HZ  1 << 2
#define QMC6310_VAL_ODR_100HZ 2 << 2
#define QMC6310_VAL_ODR_200HZ 3 << 2

#define QMC6310_VAL_OSR1_8    0 << 4
#define QMC6310_VAL_OSR1_4    1 << 4
#define QMC6310_VAL_OSR1_2    2 << 4
#define QMC6310_VAL_OSR1_1    3 << 4

#define QMC6310_VAL_OSR2_1    0 << 6
#define QMC6310_VAL_OSR2_2    1 << 6
#define QMC6310_VAL_OSR2_4    2 << 6
#define QMC6310_VAL_OSR2_8    3 << 6

#define QMC6310_VAL_MODE_SET_RESET_ON    0 << 0
#define QMC6310_VAL_MODE_SET_ON          1 << 0
#define QMC6310_VAL_MODE_SET_RESET_OFF   2 << 0

#define QMC6310_VAL_RNG_30G  0 << 2
#define QMC6310_VAL_RNG_12G  1 << 2
#define QMC6310_VAL_RNG_8G   2 << 2
#define QMC6310_VAL_RNG_2G   3 << 2

#define QMC6310_VAL_SELF_TEST_ON  1 << 6
#define QMC6310_VAL_SELF_TEST_OFF 0 << 6

#define QMC6310_VAL_SOFT_RST_ON  1 << 7
#define QMC6310_VAL_SOFT_RST_OFF 0 << 7


class QMC6310{
  public:
    QMC6310();
    void init();
    void read();
    int16_t getX();
    int16_t getY();
    int16_t getZ();
    uint16_t getAzimuth();
    void setCalibration(int16_t xMin, int16_t xMax, int16_t yMin, int16_t yMax, int16_t zMin, int16_t zMax);
    void clearCalibration();
  private:
    void _i2cWrite(byte reg, byte val);
    void _i2cReadInto(byte reg, byte num, byte* dest);
    bool _calibrated = false;
};

#endif // __QMC6310_H__