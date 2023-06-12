/*
 * Approximates the value of the mathematical constant 'e'
 * 'e' can be expressed as an infinite series: e = 1 + 1/1! + 1/2! + 1/3! + ...
 * The programme continues adding terms until the current term becomes less
 * than 'limit' which is a small (floating-point) number entered by the user
 */

#include <stdio.h>

int main(void)
{
    int factorial;
    
    float limit, e = 1.0f;

    printf("Enter lowest limit for a term: ");
    scanf("%f", &limit);

    for (int i = 1; ; i++)
    {
        factorial = 0;

        for (int j = i; j > 0; j--)  // Calculate factorial
            factorial += j;

        if (1.0f / factorial < limit)
            break;

        e += 1.0f / factorial;
    }

    printf("Value of 'e': %f\n", e);
    
    return 0;
}