/* Calculates the remaining balance on a loan after a number of payments */

#include <stdio.h>

int main(void)
{
    float loan_amount, interest_rate, monthly_payment;
    int total_payments;

    printf("Enter amount of loan: ");
    scanf("%f", &loan_amount);
    printf("Enter interest rate: ");
    scanf("%f", &interest_rate);
    printf("Enter monthly payment:");
    scanf("%f", &monthly_payment);
    printf("Enter number of payments: ");
    scanf("%d", &total_payments);

    printf("\n");

    for (int i = 1; i <= total_payments; i++)
    {
        loan_amount += loan_amount * (interest_rate / 100 / 12);
        loan_amount -= monthly_payment;
        
        printf("Balance remaining after %d payment(s): $%.2f\n", i, loan_amount);
    }

    return 0;
}