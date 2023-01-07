/* This programme adds 5% tax to a given amount */

#include <stdio.h>

#define TAX_PERCENTAGE (5.0f / 100.0f)

int main(void)
{
    float amount;

    printf("Enter an amount: ");
    scanf("%f", &amount);

    printf("With tax added: $%.2f\n", amount + (amount * TAX_PERCENTAGE) );

    return 0;
}