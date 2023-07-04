/* Displays the tax due according to amount of taxable income */

#include <stdio.h>

float calc_tax(float income);

int main(void)
{
    float income;

    printf("Enter amount of taxable income: ");
    scanf("%f", &income);

    printf("Tax due: $%.2f\n", calc_tax(income));


    return 0;
}

float calc_tax(float income)
{
    if (income < 750.00f)
        return income * .01;
    else if (income <= 2250.00f)
        return 7.50f + ((income - 750) * .02);
    else if (income <= 3750.00f)
        return 37.50f + ((income - 2250) * .03);
    else if (income <= 5250.00f)
        return 82.50f + ((income - 3750) * .04);
    else if (income <= 7000.00f)
        return 142.50f + ((income - 5250) * .05);
    else
        return 230.00f + ((income - 7000) * .06);
}
