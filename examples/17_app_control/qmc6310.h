#ifndef __QMC6310_H__
#define __QMC6310_H__

#include <Wire.h>
#include <Arduino.h>

/** @name Define I2C address of QMC6310 compass sensor */
#define QMC6310_ADDR 0x1C

/** @name Define register address of QMC6310 compass sensor */
//@{
#define QMC6310_REG_DATA_START 0x01
#define QMC6310_REG_STATUS     0x09
#define QMC6310_REG_CONTROL_1  0x0A
#define QMC6310_REG_CONTROL_2  0x0B
//@}

/** @name Define the register parameter configuration of the sensor */
//@{
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
//@}

/** A class.  Class of QMC6310 compass sensor */
class QMC6310{
  public:
    /** Construct a new QMC6310 object */
    QMC6310();

    /** Initialize QMC6310 */
    void init();

    /** Read values of QMC6310 */
    void read();

    /** Get x-axis values of QMC6310 */
    int16_t getX();

    /** Get y-axis values of QMC6310 */
    int16_t getY();

    /** Get z-axis values of QMC6310 */
    int16_t getZ();

    /** Get azimuth of QMC6310 */
    uint16_t getAzimuth();

    /** Set calibration values */
    void setCalibration(int16_t xMin, int16_t xMax, int16_t yMin, int16_t yMax, int16_t zMin, int16_t zMax);
    
    /** clear calibration values */
    void clearCalibration();

  private:
    /** i2c wite 
     * 
     * @param reg byte, register address
     * @param val byte, value to write 
     * 
    */
    void _i2cWrite(byte reg, byte val);

    /** i2c read data 
     * 
     * @param reg byte, register address
     * @param num number of bytes to read
     * @param dest pointer to store read data
     * 
     * @return Whether the execution is successful
     *         - true succeed
     *         - flase failed
    */
    bool _i2cReadInto(byte reg, byte num, byte* dest);
    
    /** whether calibration is in progress */
    bool _calibrated = false;
};

#endif // __QMC6310_H__
