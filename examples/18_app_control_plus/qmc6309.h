#ifndef __QMC6309_H__
#define __QMC6309_H__

#include <Wire.h>
#include <Arduino.h>

/** @name Define I2C addresses of QMC6309 compass sensor */
#define QMC6309_ADDR_PRIMARY   0x7C
#define QMC6309_ADDR_SECONDARY 0x0C

/** @name Define register addresses of QMC6309 compass sensor */
//@{
#define QMC6309_REG_CHIP_ID    0x00
#define QMC6309_REG_DATA_START 0x01
#define QMC6309_REG_STATUS     0x09
#define QMC6309_REG_CONTROL_1  0x0A
#define QMC6309_REG_CONTROL_2  0x0B
#define QMC6309_REG_CONTROL_3  0x0C
//@}

/** @name Define CTL_1 register parameters (QMC6309 bit layout) */
//@{
#define QMC6309_VAL_MODE_SUSPEND    0b00
#define QMC6309_VAL_MODE_NORMAL     0b01
#define QMC6309_VAL_MODE_SINGLE     0b10
#define QMC6309_VAL_MODE_CONTINUOUS 0b11

#define QMC6309_VAL_OSR1_8    (0b00 << 3)
#define QMC6309_VAL_OSR1_4    (0b01 << 3)
#define QMC6309_VAL_OSR1_2    (0b10 << 3)
#define QMC6309_VAL_OSR1_1    (0b11 << 3)

#define QMC6309_VAL_OSR2_1    (0b000 << 5)
#define QMC6309_VAL_OSR2_2    (0b001 << 5)
#define QMC6309_VAL_OSR2_4    (0b010 << 5)
#define QMC6309_VAL_OSR2_8    (0b011 << 5)
#define QMC6309_VAL_OSR2_16   (0b100 << 5)
//@}

/** @name Define CTL_2 register parameters (QMC6309 bit layout) */
//@{
#define QMC6309_VAL_MODE_SET_RESET_ON    0b00
#define QMC6309_VAL_MODE_SET_ON          0b01
#define QMC6309_VAL_MODE_SET_RESET_OFF   0b10

#define QMC6309_VAL_RNG_32G  (0b00 << 2)
#define QMC6309_VAL_RNG_16G  (0b01 << 2)
#define QMC6309_VAL_RNG_8G   (0b10 << 2)

#define QMC6309_VAL_ODR_1HZ   (0b000 << 4)
#define QMC6309_VAL_ODR_10HZ  (0b001 << 4)
#define QMC6309_VAL_ODR_50HZ  (0b010 << 4)
#define QMC6309_VAL_ODR_100HZ (0b011 << 4)
#define QMC6309_VAL_ODR_200HZ (0b100 << 4)

#define QMC6309_VAL_SOFT_RST_ON  (1 << 7)
#define QMC6309_VAL_SOFT_RST_OFF 0
//@}

/** @name Define CTL_3 register parameters */
//@{
#define QMC6309_VAL_SELF_TEST_ON  (1 << 7)
#define QMC6309_VAL_SELF_TEST_OFF 0
//@}

/** A class. Class of QMC6309 compass sensor */
class QMC6309{
  public:
    /** Construct a new QMC6309 object */
    QMC6309();

    /** Initialize QMC6309. Tries 0x7C then 0x0C. */
    bool init();

    /** Read values of QMC6309 */
    void read();

    /** Get x-axis values */
    int16_t getX();

    /** Get y-axis values */
    int16_t getY();

    /** Get z-axis values */
    int16_t getZ();

    /** Get azimuth */
    uint16_t getAzimuth();

    /** Set calibration values */
    void setCalibration(int16_t xMin, int16_t xMax, int16_t yMin, int16_t yMax, int16_t zMin, int16_t zMax);

    /** Clear calibration values */
    void clearCalibration();

  private:
    void _i2cWrite(byte reg, byte val);
    bool _i2cReadInto(byte reg, byte num, byte* dest);

    bool _calibrated = false;
    uint8_t _addr = 0;
};

#endif // __QMC6309_H__
