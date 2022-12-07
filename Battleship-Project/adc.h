/*
 * ps2.h
 *
 *  Created on: Jun 22, 2022
 *      Author: Caitlin Niemann
 */

#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>
#include <stdbool.h>
#include <msp.h>

/******************************************************************************
 * Student Defined ADC14 Macros
 *****************************************************************************/

/******************************************************************************
 * Student Defined ADC14 Extern Global Variables
 *****************************************************************************/
extern volatile uint32_t PS2_X_DIR;
extern volatile uint32_t PS2_Y_DIR;

/******************************************************************************
 * ADC14 Initialization Function
 *
 * Configures ADC14 to sample and generate an interrupt
 * for the joystick's x and y directions
 *
 * Parameters
 *      None
 * Returns
 *      None
 ******************************************************************************/
void HW1_ADC14_PS2_XY(void);

#endif /* ADC_H_ */
