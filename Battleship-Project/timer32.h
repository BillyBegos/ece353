/*
 * timer32.h
 *
 *  Created on: Jun 22, 2022
 *      Author: Caitlin Niemann
 */

#ifndef TIMER32_H_
#define TIMER32_H_

#include <stdint.h>
#include <stdbool.h>
#include <msp.h>

/******************************************************************************
 * Student Defined Timer32 Macros
 *****************************************************************************/

/******************************************************************************
 * Student Defined Timer32 Extern Global Variables
 *****************************************************************************/
extern volatile bool ALERT_SW2_Pressed; //indicates when button 1 on MKII has been pressed
extern volatile bool ALERT_1S_Passed; //indicates when 1 second passed on Timer32_2


/******************************************************************************
 * T32_1 Initialization Function
 *
 * Configures Timer32_1 to generate an interrupt every 50ms as a periodic,
 * 32-bit timer
 *
 * Parameters:
 *      None
 * Returns
 *      None
 *****************************************************************************/
void HW1_T32_1_Interrupt_50mS(void);


/******************************************************************************
 * T32_2 Initialization Function
 *
 * Configures Timer32_2 to generate an interrupt after 1sec as a one-shot,
 * 32-bit timer
 *
 * Parameters:
 *      None
 * Returns
 *      None
 ****************************************************************************/
void HW1_T32_2_Interrupt_1S(void);


#endif /* TIMER32_H_ */
