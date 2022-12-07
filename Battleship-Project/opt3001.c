/*
 * opt3001.c
 *
 */

#include "opt3001.h"

/******************************************************************************
 * Initialize the light sensor on the MKII.  This function assumes
 * that the I2C interface has already been configured to operate at 100KHz.
 ******************************************************************************/
void opt3001_init(void)
{
    int i;

    // Reset the device using the CONFIG register and powers up (auto Full scale mode)
    i2c_write_16(0x44, 0x01, 0xC810);

    // delay
    for(i = 0; i < 50000; i++){};

    // Program the CONFIG register to begin contimuos conversions mode
    i2c_write_16(0x44, 0x01, 1<<10);
}

/******************************************************************************
 * Returns the current light in Lux.
 ******************************************************************************/
float opt3001_read_lux(void)
{
    uint16_t input;
    uint16_t Einput;
    uint16_t Rinput;

    // Read the light sensor
    input = i2c_read_16(0x44, 0x00);

    Rinput=input;
    Einput=input;

    Rinput=Rinput & 0x0F;
    Einput=(Einput & 0xF0)>>12;

    // Return the data in lux.  (See opt3001 Data Sheet)
    // You will need to modify the line below to return this value
    float lux;

    lux = (0.01 * (2^Einput)) * Rinput;

    return lux;
}

