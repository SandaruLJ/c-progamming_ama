/*
 * Generates a "random walk" across a 10x10 array.
 * The array contains characters (all '.' initially).
 * The programme randomly walks from element to element, always going up, down,
 * left, or right by one element, each element visited being labelled with
 * letters 'A' through 'Z' in order.
 * If an element has already been labelled, or the move is going outside array,
 * the programme tries moving in another direction.
 * If all directions are blocked, the programme is terminated.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 10
#define DIRECTIONS 4

int main(void)
{
    char canvas[SIZE][SIZE], letter = 'A';
    int direction, attempts, row = 0, col = 0;
    bool blocked;

    // Initialize the array canvas
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            canvas[i][j] = '.';

    // Initialize random number generator
    srand((unsigned) time(NULL));

    // Perform the move
    while (letter <= 'Z')
    {
        attempts = 0;
        blocked = true;

        // Calculate direction
        direction = rand() % DIRECTIONS;

        while (blocked && attempts < DIRECTIONS)
        {
            attempts++;

            if (direction < DIRECTIONS - 1)
                direction++;       
            else
                direction = 0;
            
            switch (direction)
            {
                case 0:  // Up
                    if (row == 0 || canvas[row - 1][col] != '.')
                        continue;
                    row--;
                    break;
                case 1:  // Right
                    if (col == SIZE - 1 || canvas[row][col + 1] != '.')
                        continue;
                    col++;
                    break;
                case 2:  // Down
                    if (row == SIZE - 1 || canvas[row + 1][col] != '.')
                        continue;
                    row++;
                    break;
                case 3:  // Left
                    if (col == 0 || canvas[row][col - 1] != '.')
                        continue;
                    col--;
                    break;
            }

            blocked = false;
        }

        if (blocked && attempts == DIRECTIONS)
            break;

        // Place letter and increment it
        canvas[row][col] = letter++;
    }

    // Display the result
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            printf(" %c ", canvas[i][j]);
        printf("\n");
    }

    return 0;
}