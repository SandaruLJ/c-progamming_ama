/* 
 * This programme takes an input and calculates the value of below polynomial:
 * 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6
 */

#include <stdio.h>

int main(void)
{
    int x;

    printf("Enter a value for x: ");
    scanf("%d", &x);

    printf("Value of the polynomial: %.2f\n", 3.0 * x * x * x * x * x
        + 2.0 * x * x * x * x - 5.0 * x * x * x - x * x + 7.0 * x - 6.0);

    return 0;
}
