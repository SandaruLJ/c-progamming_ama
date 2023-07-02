/*
 * Prints an n x n magic square in which the sums of
 * rows, columns, and diagonals are all the same.
 */

#include <stdio.h>

int main(void)
{
    int n, row, col;

    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");
    scanf("%d", &n);

    int square[n][n];

    // initialize square to 0s
    for (row = 0; row < n; row++)
        for (col = 0; col < n; col++)
            square[row][col] = 0;

    // start storing from the middle of row 0
    row = 0;
    col = n / 2;
    
    // populate the magic square
    for (int num = 1; num <= n * n; num++)
    {
        if (square[row][col])
        {
            row = (row + 2) % n;
            col = (col - 1 < 0) ? n - 1 : col - 1;
        }

        square[row][col] = num;
        row = (row - 1 < 0) ? n - 1 : row - 1;
        col = (col + 1) % n;
    }

    // print the magic square
    for (row = 0; row < n; row++)
    {
        for (col = 0; col < n; col++)
            printf("%4d", square[row][col]);
        printf("\n");
    }

    return 0;
}