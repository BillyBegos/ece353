/*
 * ps2.c
 *
 *  Created on: Jun 22, 2022
 *      Author: Caitlin Niemann
 */

#include <adc.h>

/******************************************************************************
 * Student Defined ADC14 Global Variables
 *****************************************************************************/
volatile uint32_t PS2_X_DIR = 2048; //Joystick's X direction, centered to start
volatile uint32_t PS2_Y_DIR = 2048; //Joystick's Y direction, centered to start

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
void HW1_ADC14_PS2_XY(void)
{
    // Joy X to J1.2 to A15 at P6.0
    //Configure P6.0 (A15) the x direction as an analog input pin
    P6->SEL0 |= BIT0; //SEL 0 is a 1  and SEL 1 is a 1 for ADC
    P6->SEL1 |= BIT0;

    //  Joy Y to J3.26 to A9 at P4.4
    //Configure P4.4 (A9) the y direction as an analog input pin
    P4->SEL0 |= BIT4; //SEL 0 is a 1 and SEL 1 is a 1 for ADC
    P4->SEL1 |= BIT4;

    //Configure the ADC14 Control Registers to sample 16 times in pulsed sample mode
    ADC14->CTL0 = ADC14_CTL0_SHP; //signal is the output of sampling timer
    ADC14->CTL0 |= ADC14_CTL0_SHT02; //16 sample and hold time
    ADC14->CTL0 |= ADC14_CTL0_CONSEQ_1; //sequence of channels conversion mode select

    //Configure ADC to return 12-bit values
    ADC14->CTL1 = ADC14_CTL1_RES_2;

    //Configure Memory Control register so that we associate the
    // analog 15 channel with MEM[0] and analog 9 channel with MEM[1]
    ADC14->MCTL[0] = ADC14_MCTLN_INCH_15; //connect the memory to the peripheral A15
    ADC14->MCTL[1] = ADC14_MCTLN_INCH_9 | ADC14_MCTLN_EOS; //connect the memory to the peripheral A9, end of sequence

    //Enable interrupts after the value is written to MEM[0] and MEM[1]
    ADC14->IER0 = ADC14_IER0_IE0; //enable interrupts on peripheral side
    ADC14->IER0 |= ADC14_IER0_IE1; //enable interrupts on peripheral side

    //enable ADC interrupt in the NVIC
    __enable_irq();
    NVIC_EnableIRQ(ADC14_IRQn); //enable interrupt on the NVIC side

    //turn on the ADC
    ADC14->CTL0 |= ADC14_CTL0_ON;
}




//*****************************************************************************
//                         Interrupt Service Routines
//*****************************************************************************

void ADC14_IRQHandler(void)
{
    /* ADD CODE for the ADC14 Handler */
    // ISR should update a global variable used to indicate the location of the joystick.

    //Read the X value
    PS2_X_DIR = ADC14->MEM[0]; //reading the register clears the flag on the interrupt
    //Read the Y value
    PS2_Y_DIR = ADC14->MEM[1]; //reading the register clears the flag on the interrupt
}

