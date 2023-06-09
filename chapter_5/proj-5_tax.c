/* Displays the tax due according to amount of taxable income */

#include <stdio.h>

int main(void)
{
    float income, tax;

    printf("Enter amount of taxable income: ");
    scanf("%f", &income);

    if (income < 750.00f)
        tax = income * .01;
    else if (income <= 2250.00f)
        tax = 7.50f + ((income - 750) * .02);
    else if (income <= 3750.00f)
        tax = 37.50f + ((income - 2250) * .03);
    else if (income <= 5250.00f)
        tax = 82.50f + ((income - 3750) * .04);
    else if (income <= 7000.00f)
        tax = 142.50f + ((income - 5250) * .05);
    else
        tax = 230.00f + ((income - 7000) * .06);

    printf("Tax due: $%.2f\n", tax);


    return 0;
}