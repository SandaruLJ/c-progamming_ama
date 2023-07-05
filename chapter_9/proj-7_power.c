/* Calculates power by using an optimized algorithm */

#include <stdio.h>

int power(int x, int n);

int main(void)
{
    int x, n;

    printf("Enter a number followed by an exponent: ");
    scanf("%d%d", &x, &n);

    printf("Result: %d\n", power(x, n));

    return 0;
}

int power(int x, int n)
{
    if (n == 0)
        return 1;
    else
    {
        if (n % 2 == 0)
            return power(x, n / 2) * power(x, n / 2);
        else
            return x * power(x, n - 1);
    }
}
