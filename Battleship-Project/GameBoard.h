

#ifndef GAMEBOARD_H_
#define GAMEBOARD_H_

#include <stdint.h>
#include <stdbool.h>

#define SCREEN_X            132
#define SCREEN_Y            132

#define SCREEN_CENTER_COL    ((SCREEN_X/2)-1)
#define SCREEN_CENTER_ROW    ((SCREEN_Y/2)-1)

#define LINE_WIDTH          4
#define LINE_LENGTH         (SCREEN_X - 1)

#define SQUARE_SIZE         20

#define PADDING             2

#define LEFT_COL                      9
#define LEFT_MID_COL                  37
#define CENTER_COL                    65
#define RIGHT_MID_COL                 93
#define RIGHT_COL                     121

#define UPPER_ROW                     9
#define UPPER_MID_ROW                 37
#define CENTER_ROW                    65
#define LOWER_MID_ROW                 93
#define LOWER_ROW                     121

#define UPPER_HORIZONTAL_LINE_Y     (SCREEN_CENTER_ROW - (2*SQUARE_SIZE) - LINE_WIDTH/2)
#define UPPER_MID_HORIZONTAL_LINE_Y (SCREEN_CENTER_ROW - (SQUARE_SIZE/2) - PADDING - LINE_WIDTH/2)
#define LOWER_MID_HORIZONTAL_LINE_Y (SCREEN_CENTER_ROW + (SQUARE_SIZE/2) + PADDING + LINE_WIDTH/2)
#define LOWER_HORIZONTAL_LINE_Y     (SCREEN_CENTER_ROW + (2*SQUARE_SIZE) + LINE_WIDTH/2)

#define LEFT_HORIZONTAL_LINE_X      (SCREEN_CENTER_COL - (2*SQUARE_SIZE) - LINE_WIDTH/2)
#define LEFT_MID_HORIZONTAL_LINE_X  (SCREEN_CENTER_COL - (SQUARE_SIZE/2) - PADDING - LINE_WIDTH/2)
#define RIGHT_MID_HORIZONTAL_LINE_X (SCREEN_CENTER_COL + (SQUARE_SIZE/2) + PADDING + LINE_WIDTH/2)
#define RIGHT_HORIZONTAL_LINE_X     (SCREEN_CENTER_COL + (2*SQUARE_SIZE) + LINE_WIDTH/2)




typedef enum{
  WATER,
  SHIP,
  QUESTION,
} IMAGE_TYPE_t;

extern uint8_t Locations[5];
extern IMAGE_TYPE_t User_Board[5][5];
extern IMAGE_TYPE_t Enemy_Board[5][5];

#endif /* GAMEBOARD_H_ */
