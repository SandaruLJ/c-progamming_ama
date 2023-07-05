/* Computes the value of the polynomial: 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 */

#include <stdio.h>
#include <math.h>

double compute_polynomial(double x);

int main(void)
{
    double x;

    printf("Enter value for x: ");
    scanf("%lf", &x);

    printf("Value of the polynomial: %f\n", compute_polynomial(x));

    return 0;
}

double compute_polynomial(double x)
{
    return 3 * pow(x, 5) + 2 * pow(x, 4) - 5 * pow(x, 3) - pow(x, 2) + 7 * x - 6;
}
