/* Finds the largest in a series of numbers entered by the user */

#include <stdio.h>

int main(void)
{
    float number, max = 0.0f;

    do {
        printf("Enter a number: ");
        scanf("%f", &number);

        if (number > max)
            max = number;
    } while (number > 0);

    printf("\nThe largest number entered was %f\n", max);

    return 0;
}