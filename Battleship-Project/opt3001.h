/*
 * opt3001.h
 *

 */

#ifndef OPT3001_H_
#define OPT3001_H_

#include "msp.h"
#include "i2c.h"
#include <stdint.h>
#include <stdbool.h>


/******************************************************************************
 * Initialize the tmp006 temperature sensor on the MKII.  This function assumes
 * that the I2C interface has already been configured to operate at 100KHz.
 ******************************************************************************/
void opt3001_init(void);

/******************************************************************************
 * Returns the current temperature in degrees C.
 ******************************************************************************/
float op3001_read_lux(void);

#endif /* OPT3001_H_ */
