/* Reads a 5x5 array of integers and then prints the row sums and column sums */

#include <stdio.h>

#define N 5

int main(void)
{
    int array[N][N], row_sum, col_sum;

    for (int row = 0; row < N; row++)
    {
        printf("Enter row %d: ", row + 1);

        for (int col = 0; col < N; col++)
            scanf("%d", &array[row][col]);
    }
    
    printf("\nRow totals:");
    for (int row = 0; row < N; row++)
    {
        row_sum = 0;
        for (int col = 0; col < N; col ++)
            row_sum += array[row][col];
        printf(" %d", row_sum);
    }

    printf("\nColumn totals:");
    for (int col = 0; col < N; col++)
    {
        col_sum = 0;
        for (int row = 0; row < N; row++)
            col_sum += array[row][col];
        printf(" %d", col_sum);
    }
    printf("\n");

    return 0;
}