/*
 * Prompts the user for a number and then displays it using characters
 * to simulate the effect of a seven-segment display.
 */

#include <ctype.h>
#include <stdio.h>

#define MAX_DIGITS 10
#define NUM_DIGITS 10
#define NUM_SEGMENTS 7
#define NUM_CHAR_ROWS 4
#define NUM_CHAR_WIDTH 4

/* prototypes */
void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

/* external variables */
char digits[NUM_CHAR_ROWS][NUM_DIGITS * NUM_CHAR_WIDTH];
int segments_array[NUM_DIGITS][NUM_SEGMENTS] = {
    {1, 1, 1, 1, 1, 1},
    {[1] = 1, [2] = 1},
    {1, 1, 0, 1, 1, 0, 1},
    {1, 1, 1, 1, 0, 0, 1},
    {0, 1, 1, 0, 0, 1, 1},
    {1, 0, 1, 1, 0, 1, 1},
    {1, 0, 1, 1, 1, 1, 1},
    {1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1}
};

int main(void)
{
    // intialize digits array
    clear_digits_array();

    // get number input
    printf("Enter a number: ");

    char input;
    int position = 0;    
    do
    {
        input = getchar();

        // if input is a digit, store it in the digits array
        if (isdigit(input))
            process_digit(input - '0', position++);
    }
    while (input != '\n');

    // display digits array
    print_digits_array();

    return 0;
}

/* store blank characters into all elements of the 'digits' array */
void clear_digits_array(void)
{
    for (int row = 0; row < NUM_CHAR_ROWS; row++)
        for (int col = 0; col < NUM_DIGITS * NUM_CHAR_WIDTH; col++)
            digits[row][col] = ' ';
}

/* 
 * store the seven-segment representation of digits into a specified
 * position in the 'digits' array
 */
void process_digit(int digit, int position)
{
    // printf("Digit: %d, position: %d\n", digit, position);
    // char row_chars = {'_', '|', '_', '_'}
    for (int row = 0; row < NUM_CHAR_ROWS; row++)
    {
        // adjust position for character width
        int grid_position = position * NUM_CHAR_WIDTH;
        
        for (int col = grid_position; col < grid_position + NUM_CHAR_WIDTH; col++)
        {
            // compute current character column
            int char_col = col - grid_position;

            // segment 0 (top)
            if (row == 0 && char_col == 1)
            {
                if (segments_array[digit][0])
                    digits[row][col] = '_';
            }
            // segment 5 (top left)
            else if (row == 1 && char_col == 0)
            {
                if (segments_array[digit][5])
                    digits[row][col] = '|';
            }
            // segment 6 (center)
            else if (row == 1 && char_col == 1)
            {
                if (segments_array[digit][6])
                    digits[row][col] = '_';
            }
            // segment 1 (top right)
            else if (row == 1 && char_col == 2)
            {
                if (segments_array[digit][1])
                    digits[row][col] = '|';
            }
            // segment 4 (bottom left)
            else if (row == 2 && char_col == 0)
            {
                if (segments_array[digit][4])
                    digits[row][col] = '|';
            }
            // segment 3 (bottom)
            else if (row == 2 && char_col == 1)
            {
                if (segments_array[digit][3])
                    digits[row][col] = '_';
            }
            // segment 2 (bottom right)
            else if (row == 2 && char_col == 2)
            {
                if (segments_array[digit][2])
                    digits[row][col] = '|';
            }
        }
    }
}

/* 
 * display the rows of the 'digits' array, each on a single line,
 * simulating a seven-segment display
 */
void print_digits_array(void)
{
    for (int row = 0; row < NUM_CHAR_ROWS; row++)
    {
        for (int col = 0; col < NUM_DIGITS * NUM_CHAR_WIDTH; col++)
            putchar(digits[row][col]);
        putchar('\n');
    }
}
