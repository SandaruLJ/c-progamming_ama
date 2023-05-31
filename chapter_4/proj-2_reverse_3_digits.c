#include <stdio.h>

int main(void)
{
    int number, digit1, digit2, digit3;

    printf("Enter a three-digit number: ");
    scanf("%d", &number);

    digit3 = number % 10;
    digit2 = number / 10 % 10;
    digit1 = number / 100;

    printf("The reversal is: %d%d%d\n", digit3, digit2, digit1);

    return 0;
}