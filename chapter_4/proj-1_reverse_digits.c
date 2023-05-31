#include <stdio.h>

int main(void)
{
    int number, digit1, digit2;

    printf("Enter a two-digit number: ");
    scanf("%d", &number);

    digit2 = number % 10;
    digit1 = number / 10;

    printf("The reversal is: %d%d\n", digit2, digit1);

    return 0;
}