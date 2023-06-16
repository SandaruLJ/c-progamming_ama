/*
 * Uses Newton's methhod to compute the square root
 * of a positive floating-point number.
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    double x, old_y, y = 1.0;

    printf("Enter a positive number: ");
    scanf("%lf", &x);

    do
    {
        old_y = y;
        y = (y + (x / y)) / 2;
    }
    while (fabs(y - old_y) >= .00001 * y);

    printf("Square root: %.5f\n", y);

    return 0;
}