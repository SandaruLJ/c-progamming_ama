/*
 * Approximates the value of the mathematical constant 'e'
 * 'e' can be expressed as an infinite series: e = 1 + 1/1! + 1/2! + 1/3! + ...
 * Approximation is done by computing value of
 * 1 + 1/1! + 1/2! + 1/3 + ... + 1/n! where 'n' is an integer entered by user
 */

#include <stdio.h>

int main(void)
{
    int n, factorial;
    float e = 1.0f;

    printf("Enter value for 'n': ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        factorial = 0;

        for (int j = i; j > 0; j--)  // Calculate factorial
            factorial += j;

        e += 1.0f / factorial;
    }

    printf("Value of 'e': %f\n", e);
    
    return 0;
}