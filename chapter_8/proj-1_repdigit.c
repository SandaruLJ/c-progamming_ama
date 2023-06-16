/* Checks and shows which digits (if any) were repeated in an entered number */

#include <stdio.h>

int main(void)
{
    int digit, digit_seen[10] = {0};
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0)
    {
        digit = n % 10;
        digit_seen[digit]++;
        n /= 10;
    }

    printf("Repeated digit(s):");

    for (int i = 0; i < 10; i++)
        if (digit_seen[i] > 1)
            printf(" %d", i);

    printf("\n");

    return 0;
}