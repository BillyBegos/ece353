/*
 * task_mkII_s1.c
 *
 *  Created on: Oct 14, 2020
 *      Author: Joe Krachey
 */

#include "task_mkII_s2.h"
#include "ece353_staff.h"

TaskHandle_t Task_mkII_s2_Handle = NULL;

/******************************************************************************
 * De-bounce switch S2.  If is has been pressed, change the tri-Color LED on
 * the MKII. Everytime S2 is pressed, the color should change in
 * the following order:
 *      RED->GREEN->BLUE->RED->GREEN....
 *****************************************************************************/
void task_mkII_s2(void *pvParameters)
{
    // Declare a uint8_t variable that will be used to de-bounce S2
    uint8_t debounce_state = 0x00;
    int state = 0;
    while(1)
    {

        // Shift the de-bounce variable to the left 
        debounce_state = debounce_state<<1;
        // If S2 is being pressed, set the LSBit of debounce_state to a 1;
        if(ece353_staff_MKII_S2()){
            debounce_state |= 0x01;
        }
        // If the de-bounce variable is equal to 0x7F, change the color of the tri-color LED.
        if(debounce_state == 0x7F){
            ece353_staff_MKII_RGB_LED(state==0, state==1, state==2);
            state = (state+1)%3;
        }
        // Delay for 10mS using vTaskDelay
        vTaskDelay(pdMS_TO_TICKS(10));
    }

}





