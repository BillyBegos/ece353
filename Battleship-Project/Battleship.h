

#ifndef __BATTLESHIP_H_
#define __BATTLESHIP_H_

#include <stdbool.h>
#include <GameBoard.h>
#include <lcd.h>
#include <Images.h>
#include <adc.h>
#include <timer32.h>




/*******************************************************************************
* Function Name: memory_init
********************************************************************************
* Summary: Initializes the game board to all ? marks
*******************************************************************************/
void battleship_init(void);

#endif /* __BATTLESHIP_H_ */
