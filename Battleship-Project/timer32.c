/*
 * timer32.c
 *
 *  Created on: Jun 22, 2022
 *      Author: Caitlin Niemann
 */

#include <timer32.h>

/******************************************************************************
 * Student Defined Timer32 Global Variables
 *****************************************************************************/
volatile bool ALERT_SW2_Pressed = false; //indicates when button 1 on MKII has been pressed
volatile bool ALERT_1S_Passed = false; //indicates when 1 second passed on Timer32_2

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
void HW1_T32_1_Interrupt_50mS(void){

    uint16_t ms = 50; //50 mS

    //ticks = desired period / core clock period
    //50e-3/(1/24E6) = (24e6*50)/1000
    uint32_t ticks =((SystemCoreClock * ms)/1000)-1;

    //stop the timer
    TIMER32_1->CONTROL = 0;

    //set the load register
    TIMER32_1->LOAD = ticks;

    // enable the Timer32 Interrupt in NVIC (always need to do this)
    __enable_irq();
    NVIC_EnableIRQ(T32_INT1_IRQn);  //enable the Timer32 IRQ

    // Start the Timer32 and enable interrupt
    TIMER32_1->CONTROL =
            TIMER32_CONTROL_ENABLE | //turn timer on
            TIMER32_CONTROL_MODE |   //periodic mode
            TIMER32_CONTROL_SIZE |  //32 bit
            TIMER32_CONTROL_IE;     // enable interrupts on interrupt side
}

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
void HW1_T32_2_Interrupt_1S(void){

    uint32_t ticks =SystemCoreClock -1; //one sec

    //stop the timer
    TIMER32_2->CONTROL = 0;

    //set the timer to be a 32-bit, one-shot mode
    TIMER32_2->CONTROL = TIMER32_CONTROL_ONESHOT | TIMER32_CONTROL_SIZE;

    // enable the timer interrupt on peripheral side
    TIMER32_2->CONTROL |= TIMER32_CONTROL_IE;

    //set the load register (set the period)
    TIMER32_2->LOAD = ticks;

    // enable the Timer32 Interrupt in NVIC
    __enable_irq();
    NVIC_EnableIRQ(T32_INT2_IRQn);  //enable the Timer32 IRQ
    NVIC_SetPriority(T32_INT2_IRQn, 0); //set as top priority

    //start the timer
    TIMER32_2->CONTROL |= TIMER32_CONTROL_ENABLE;

}

//*****************************************************************************
//                         Interrupt Service Routines
//*****************************************************************************

void T32_INT1_IRQHandler(void){

    //Start the ADC conversions of joystick x and y directions
    ADC14->CTL0 |= ADC14_CTL0_SC | ADC14_CTL0_ENC; // enable and start sample and conversion

    //Debounce the SW2 on the MKII to prevent the application from interpreting a
    //single button press as multiple button presses

    static uint8_t button_state = 0x00; //keeps track of button bounces between each interrupt period

    //check if Button2 has been pressed (0 input equals pressed)
    bool button_pressed =  ((P3->IN & BIT5) == 0); //updates the current state of the button

    button_state = button_state << 1 ; //shift over the past updates of button presses

    //add a 1 to the tracker of bounces if current state is pressed, 0 otherwise through shift above
    if(button_pressed){
        button_state |= 0x01;
    }

    //means the button bounced 4 times in a row thus the button was pressed only once
    if(button_state == 0xF){ //button state = 1111
        ALERT_SW2_Pressed = true; //update global variable that indicates button was pressed
    }

    //Clear the Timer interrupt
    TIMER32_1->INTCLR = BIT0;

}

void T32_INT2_IRQHandler(void){

    //update global variable that indicates 1 second passed
    ALERT_1S_Passed = true;

    //Clear the Timer interrupt
    TIMER32_2->INTCLR = BIT0;

}
