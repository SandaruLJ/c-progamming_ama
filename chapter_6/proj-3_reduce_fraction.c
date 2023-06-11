/* Reduces a fraction to lowest terms */

#include <stdio.h>

int main(void)
{
    int num, denom, m, n, remainder, gcd;

    printf("Enter a fraction: ");
    scanf("%d /%d", &num, &denom);

    // Find GCD
    m = num, n = denom;

    while (n != 0)
    {
        remainder = m % n;
        m = n;
        n = remainder;
    }

    gcd = m;

    // Reduce fraction
    num /= gcd, denom /= gcd;

    printf("In lowest terms: %d/%d\n", num, denom);

    return 0;
}