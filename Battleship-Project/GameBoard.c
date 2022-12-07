

#include <GameBoard.h>

uint8_t Locations[5]={9,37,65,93,121}; //locations to place images for both rows and columns
/*
 *        9,9 |   9,37 |   9,65 |   9,93 |   9,121
 *        ----------------------------------------
 *       37,9 |  37,37 |  37,65 |  37,93 |  37,121
 *       ----------------------------------------
 *       65,9 |  65,37 |  65,65 |  65,93 |  65,121
 *       ----------------------------------------
 *       93,9 |  93,37 |  93,65 |  93,93 |  93,121
 *       ----------------------------------------
 *      121,9 | 121,37 | 121,65 | 121,93 | 121,121
 *      9999999999999999999999999999999999999999999
 */


IMAGE_TYPE_t User_Board[5][5] =
{
    { // Upper Row
      {WATER},     // Upper Left
      {WATER},     // Upper Left Mid
      {WATER},     // Upper Center
      {WATER},     // Upper Right Mid
      {WATER}      // Upper Right
    },
    { // Upper Mid Row
      {WATER},     // Upper Mid Left
      {WATER},     // Upper Mid Left Mid
      {WATER},     // Upper Mid Center
      {WATER},     // Upper Mid Right Mid
      {WATER}      // Upper Mid Right
    },
    { // Middle Row
      {WATER},     // Center Left
      {WATER},     // Center Left Mid
      {WATER},     // Center Center
      {WATER},     // Center Right Mid
      {WATER}      // Center Right
    },
    { // Lower Mid Row
      {WATER},     // Lower Mid Left
      {WATER},     // Lower Mid Left Mid
      {WATER},     // Lower Mid Center
      {WATER},     // Lower Mid Right Mid
      {WATER}      // Lower Mid Right
    },
    { // Lower Row
      {WATER},     // Lower Left
      {WATER},     // Lower Left Mid
      {WATER},     // Lower Center
      {WATER},     // Lower Right Mid
      {WATER}      // Lower Right
    }
};

IMAGE_TYPE_t Enemy_Board[5][5] =
{
    { // Upper Row
      {QUESTION},     // Upper Left
      {QUESTION},     // Upper Left Mid
      {QUESTION},     // Upper Center
      {QUESTION},     // Upper Right Mid
      {QUESTION}      // Upper Right
    },
    { // Upper Mid Row
      {QUESTION},     // Upper Mid Left
      {QUESTION},     // Upper Mid Left Mid
      {QUESTION},     // Upper Mid Center
      {QUESTION},     // Upper Mid Right Mid
      {QUESTION}      // Upper Mid Right
    },
    { // Middle Row
      {QUESTION},     // Center Left
      {QUESTION},     // Center Left Mid
      {QUESTION},     // Center Center
      {QUESTION},     // Center Right Mid
      {QUESTION}      // Center Right
    },
    { // Lower Mid Row
      {QUESTION},     // Lower Mid Left
      {QUESTION},     // Lower Mid Left Mid
      {QUESTION},     // Lower Mid Center
      {QUESTION},     // Lower Mid Right Mid
      {QUESTION}      // Lower Mid Right
    },
    { // Lower Row
      {QUESTION},     // Lower Left
      {QUESTION},     // Lower Left Mid
      {QUESTION},     // Lower Center
      {QUESTION},     // Lower Right Mid
      {QUESTION}      // Lower Right
    }
};



