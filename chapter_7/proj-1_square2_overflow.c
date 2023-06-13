/* Experiment overflowing the integer types when squaring numbers */

#include <stdio.h>

int main(void)
{
    int n;
    char i;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
        printf("%10d%20d%20zu%20zu\n", i, i * i, sizeof (i), sizeof (i * i));

    return 0;
}