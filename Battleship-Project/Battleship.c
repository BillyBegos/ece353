

#include <Battleship.h>




/*******************************************************************************
* Function Name: memory_init
********************************************************************************
* Summary: Initializes the game board to all ? marks
*******************************************************************************/
void battleship_init(void)
{
    // MK2 SW1 configure as input
    P5->DIR &= ~BIT1;

    // MK2 SW2 configure as input
    P3->DIR &= ~BIT5;

    // configure the UART for printing to Putty
    serial_debug_init();

    //initialize the light sensore
    opt3001_init();

    //initiallize the accelerometer

    //Print to Terminal Information and Instructions
    printf("\n\r");
    printf("*********************************************\n\r");
    printf("* ECE 353 Project - Battleship \n\r");
    printf("* Created by Billy Begos and Caitlin Niemann\n\r");
    printf("*********************************************\n\r");
    printf("\n\r");

    printf("\n\r");
    printf("*********************************************\n\r");
    printf("* Battleship - How to Play \n\r");
    printf("*********************************************\n\r");
    printf("\n\r");
    printf("* Step 1: \n\r");

    // Initialize LCD
    lcd_init();

    // Clear the LCD screen adn make blue
    lcd_draw_rectangle(CENTER_COL,CENTER_ROW,LINE_LENGTH,LINE_LENGTH,LCD_COLOR_BLUE);

    // Draw board lines
    // Horizontal Lines
    lcd_draw_rectangle(SCREEN_CENTER_COL, UPPER_HORIZONTAL_LINE_Y, LINE_LENGTH,LINE_WIDTH,LCD_COLOR_BLACK);
    lcd_draw_rectangle(SCREEN_CENTER_COL, UPPER_MID_HORIZONTAL_LINE_Y, LINE_LENGTH,LINE_WIDTH,LCD_COLOR_BLACK);
    lcd_draw_rectangle(SCREEN_CENTER_COL,LOWER_MID_HORIZONTAL_LINE_Y, LINE_LENGTH,LINE_WIDTH,LCD_COLOR_BLACK);
    lcd_draw_rectangle(SCREEN_CENTER_COL,LOWER_HORIZONTAL_LINE_Y, LINE_LENGTH,LINE_WIDTH,LCD_COLOR_BLACK);

    //Vertical Lines
    lcd_draw_rectangle(LEFT_HORIZONTAL_LINE_X,SCREEN_CENTER_ROW, LINE_WIDTH, LINE_LENGTH,LCD_COLOR_BLACK);
    lcd_draw_rectangle(LEFT_MID_HORIZONTAL_LINE_X,SCREEN_CENTER_ROW, LINE_WIDTH, LINE_LENGTH,LCD_COLOR_BLACK);
    lcd_draw_rectangle(RIGHT_MID_HORIZONTAL_LINE_X,SCREEN_CENTER_ROW, LINE_WIDTH,LINE_LENGTH,LCD_COLOR_BLACK);
    lcd_draw_rectangle(RIGHT_HORIZONTAL_LINE_X,SCREEN_CENTER_ROW, LINE_WIDTH,LINE_LENGTH,LCD_COLOR_BLACK);


    // Draw all of the question marks for enemy board to start the game.

    // ********************* Upper Row, Left Col *****************************/
    lcd_draw_image(
        LEFT_COL,
        UPPER_ROW,
        questionWidthPixels,
        questionHeightPixels,
        questionBitmaps,
        LCD_COLOR_YELLOW,
        LCD_COLOR_BLUE
    );

    // ********************* Upper Row, Left Mid Col *****************************/
    lcd_draw_image(
        LEFT_MID_COL,
        UPPER_ROW,
        questionWidthPixels,
        questionHeightPixels,
        questionBitmaps,
        LCD_COLOR_YELLOW,
        LCD_COLOR_BLUE
    );
    // ********************* Upper Row, Center Col *****************************
    lcd_draw_image(
        CENTER_COL,
        UPPER_ROW,
        questionWidthPixels,
        questionHeightPixels,
        questionBitmaps,
        LCD_COLOR_YELLOW,
        LCD_COLOR_BLUE
    );

    // ********************* Upper Row, Right Mide Col *****************************
    lcd_draw_image(
        RIGHT_MID_COL,
        UPPER_ROW,
        questionWidthPixels,
        questionHeightPixels,
        questionBitmaps,
        LCD_COLOR_YELLOW,
        LCD_COLOR_BLUE
    );

    // ********************* Upper Row, Right Col *****************************
    lcd_draw_image(
        RIGHT_COL,
        UPPER_ROW,
        questionWidthPixels,
        questionHeightPixels,
        questionBitmaps,
        LCD_COLOR_YELLOW,
        LCD_COLOR_BLUE
    );

    //next row
    // ********************* Upper Mid Row, Left Col *****************************/
    lcd_draw_image(
        LEFT_COL,
        UPPER_MID_ROW,
        questionWidthPixels,
        questionHeightPixels,
        questionBitmaps,
        LCD_COLOR_YELLOW,
        LCD_COLOR_BLUE
    );

    // ********************* Upper Mid Row, Left Mid Col *****************************/
    lcd_draw_image(
        LEFT_MID_COL,
        UPPER_MID_ROW,
        questionWidthPixels,
        questionHeightPixels,
        questionBitmaps,
        LCD_COLOR_YELLOW,
        LCD_COLOR_BLUE
    );
    // ********************* Upper Mid Row, Center Col *****************************
    lcd_draw_image(
        CENTER_COL,
        UPPER_MID_ROW,
        questionWidthPixels,
        questionHeightPixels,
        questionBitmaps,
        LCD_COLOR_YELLOW,
        LCD_COLOR_BLUE
    );

    // ********************* Upper Mid Row, Right Mide Col *****************************
    lcd_draw_image(
        RIGHT_MID_COL,
        UPPER_MID_ROW,
        questionWidthPixels,
        questionHeightPixels,
        questionBitmaps,
        LCD_COLOR_YELLOW,
        LCD_COLOR_BLUE
    );

    // ********************* Upper Mid Row, Right Col *****************************
    lcd_draw_image(
        RIGHT_COL,
        UPPER_MID_ROW,
        questionWidthPixels,
        questionHeightPixels,
        questionBitmaps,
        LCD_COLOR_YELLOW,
        LCD_COLOR_BLUE
    );

    //center row
    // ********************* Center Row, Left Col *****************************/
    lcd_draw_image(
        LEFT_COL,
        CENTER_ROW,
        questionWidthPixels,
        questionHeightPixels,
        questionBitmaps,
        LCD_COLOR_YELLOW,
        LCD_COLOR_BLUE
    );

    // ********************* Center Row, Left Mid Col *****************************/
    lcd_draw_image(
        LEFT_MID_COL,
        CENTER_ROW,
        questionWidthPixels,
        questionHeightPixels,
        questionBitmaps,
        LCD_COLOR_YELLOW,
        LCD_COLOR_BLUE
    );

    // ********************* Center Row, Center Col *****************************
    // Invert the colors of the center square and draw a rectangle
    lcd_draw_rectangle(
        CENTER_COL,
        CENTER_ROW,
         SQUARE_SIZE,
         SQUARE_SIZE,
         LCD_COLOR_YELLOW
         );

    /* Draw the inverted image over the rectangle to indicate the active square*/
    lcd_draw_image(
        CENTER_COL,
        CENTER_ROW,
        targetWidthPixels,
        targetHeightPixels,
        targetBitmaps,
        LCD_COLOR_BLUE,
        LCD_COLOR_YELLOW
    );

    // ********************* Center Row, Right Mide Col *****************************
    lcd_draw_image(
        RIGHT_MID_COL,
        CENTER_ROW,
        questionWidthPixels,
        questionHeightPixels,
        questionBitmaps,
        LCD_COLOR_YELLOW,
        LCD_COLOR_BLUE
    );

    // ********************* Center Row, Right Col *****************************
    lcd_draw_image(
        RIGHT_COL,
        CENTER_ROW,
        questionWidthPixels,
        questionHeightPixels,
        questionBitmaps,
        LCD_COLOR_YELLOW,
        LCD_COLOR_BLUE
    );

    //next lower row
    // ********************* Lower Mid Row, Left Col *****************************/
    lcd_draw_image(
        LEFT_COL,
        LOWER_MID_ROW,
        questionWidthPixels,
        questionHeightPixels,
        questionBitmaps,
        LCD_COLOR_YELLOW,
        LCD_COLOR_BLUE
    );

    // ********************* Lower Mid Row, Left Mid Col *****************************/
    lcd_draw_image(
        LEFT_MID_COL,
        LOWER_MID_ROW,
        questionWidthPixels,
        questionHeightPixels,
        questionBitmaps,
        LCD_COLOR_YELLOW,
        LCD_COLOR_BLUE
    );
    // ********************* Lower Mid Row, Center Col *****************************
    lcd_draw_image(
        CENTER_COL,
        LOWER_MID_ROW,
        questionWidthPixels,
        questionHeightPixels,
        questionBitmaps,
        LCD_COLOR_YELLOW,
        LCD_COLOR_BLUE
    );

    // ********************* Lower Mid Row, Right Mide Col *****************************
    lcd_draw_image(
        RIGHT_MID_COL,
        LOWER_MID_ROW,
        questionWidthPixels,
        questionHeightPixels,
        questionBitmaps,
        LCD_COLOR_YELLOW,
        LCD_COLOR_BLUE
    );

    // ********************* Lower Mid Row, Right Col *****************************
    lcd_draw_image(
        RIGHT_COL,
        LOWER_MID_ROW,
        questionWidthPixels,
        questionHeightPixels,
        questionBitmaps,
        LCD_COLOR_YELLOW,
        LCD_COLOR_BLUE
    );

    //last row
    // ********************* Lower Row, Left Col *****************************/
        lcd_draw_image(
            LEFT_COL,
            LOWER_ROW,
            questionWidthPixels,
            questionHeightPixels,
            questionBitmaps,
            LCD_COLOR_YELLOW,
            LCD_COLOR_BLUE
        );

        // ********************* Lower Row, Left Mid Col *****************************/
        lcd_draw_image(
            LEFT_MID_COL,
            LOWER_ROW,
            questionWidthPixels,
            questionHeightPixels,
            questionBitmaps,
            LCD_COLOR_YELLOW,
            LCD_COLOR_BLUE
        );
        // ********************* Lower Row, Center Col *****************************
        lcd_draw_image(
            CENTER_COL,
            LOWER_ROW,
            questionWidthPixels,
            questionHeightPixels,
            questionBitmaps,
            LCD_COLOR_YELLOW,
            LCD_COLOR_BLUE
        );

        // ********************* Lower Row, Right Mide Col *****************************
        lcd_draw_image(
            RIGHT_MID_COL,
            LOWER_ROW,
            questionWidthPixels,
            questionHeightPixels,
            questionBitmaps,
            LCD_COLOR_YELLOW,
            LCD_COLOR_BLUE
        );

        // ********************* Lower Row, Right Col *****************************
        lcd_draw_image(
            RIGHT_COL,
            LOWER_ROW,
            questionWidthPixels,
            questionHeightPixels,
            questionBitmaps,
            LCD_COLOR_YELLOW,
            LCD_COLOR_BLUE
        );

}





