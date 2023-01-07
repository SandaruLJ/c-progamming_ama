/* 
 * This programme uses Horner's Rule for evaluating the project 5 polynomial:
 * ((((3x + 2)x - 5)x - 1)x + 7)x - 6
 */

#include <stdio.h>

int main(void)
{
    int x;

    printf("Enter a value for x: ");
    scanf("%d", &x);

    printf("Value of the polynomial: %.2f\n",
        ((((3.0 * x + 2.0) * x - 5.0) * x - 1.0) * x + 7.0) * x - 6.0);

    return 0;
}
