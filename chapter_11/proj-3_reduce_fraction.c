/* Reduces a fraction to lowest terms */

#include <stdio.h>

void reduce(int numerator, int denominator,
            int *reduced_numerator, int *reduced_denominator);

int main(void)
{
    int num, denom;

    printf("Enter a fraction: ");
    scanf("%d /%d", &num, &denom);

    reduce(num, denom, &num, &denom);

    printf("In lowest terms: %d/%d\n", num, denom);

    return 0;
}

void reduce(int numerator, int denominator,
            int *reduced_numerator, int *reduced_denominator)
{
    // Find GCD
    int remainder;
    int m = numerator, n = denominator;

    while (n != 0)
    {
        remainder = m % n;
        m = n;
        n = remainder;
    }
    
    int gcd = m;

    // Reduce fraction
    *reduced_numerator = numerator / gcd;
    *reduced_denominator = denominator / gcd;
}
