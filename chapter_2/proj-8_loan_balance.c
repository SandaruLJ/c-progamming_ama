/*
 * This programme calculates the remaining balance on a loan
 * after the first, second, and third monthly payments.
 */

#include <stdio.h>

#define HUNDRED 100
#define MONTHS 12

int main(void)
{
    float loan_amount, interest_rate, monthly_payment;

    printf("Enter amount of loan: ");
    scanf("%f", &loan_amount);
    printf("Enter interest rate: ");
    scanf("%f", &interest_rate);
    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);

    loan_amount += loan_amount * ((interest_rate / HUNDRED) / MONTHS) - monthly_payment;
    printf("\nBalance remaining after first payment: $%.2f\n", loan_amount);

    loan_amount += loan_amount * ((interest_rate / HUNDRED) / MONTHS) - monthly_payment;
    printf("Balance remaining after second payment: $%.2f\n", loan_amount);

    loan_amount += loan_amount * ((interest_rate / HUNDRED) / MONTHS) - monthly_payment;
    printf("Balance remaining after third payment: $%.2f\n", loan_amount);

    return 0;
}