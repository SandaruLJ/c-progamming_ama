/*
 * Prints an n x n magic square in which the sums of
 * rows, columns, and diagonals are all the same.
 */

#include <stdio.h>

void create_magic_square(int n, char magic_square[n][n]);
void print_magic_square(int n, char magic_square[n][n]);

int main(void)
{
    int n;

    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");
    scanf("%d", &n);

    char magic_square[n][n];

    create_magic_square(n, magic_square);
    print_magic_square(n, magic_square);

    return 0;
}

void create_magic_square(int n, char magic_square[n][n])
{
    int row, col;
    
    // initialize square to 0s
    for (row = 0; row < n; row++)
        for (col = 0; col < n; col++)
            magic_square[row][col] = 0;

    // start storing from the middle of row 0
    row = 0;
    col = n / 2;
    
    // populate the magic square
    for (int num = 1; num <= n * n; num++)
    {
        if (magic_square[row][col])
        {
            row = (row + 2) % n;
            col = (col - 1 < 0) ? n - 1 : col - 1;
        }

        magic_square[row][col] = num;
        row = (row - 1 < 0) ? n - 1 : row - 1;
        col = (col + 1) % n;
    }
}

void print_magic_square(int n, char magic_square[n][n])
{
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
            printf("%4d", magic_square[row][col]);
        printf("\n");
    }
}
