/* Computes the factorial of a positive integer */

#include <stdio.h>

int main(void)
{
    int number;
    short factorial = 1;

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    for (int i = number; i > 0; i--)
        factorial *= i;

    printf("Factorial of %d: %hd\n", number, factorial);

    return 0;
}