/* 
 * This programme takes a dollar amount and shows how to pay it
 * using the smallest number of $20, $10, $5 and $1 bills.
 */

#include <stdio.h>

#define TWENTY 20
#define TEN 10
#define FIVE 5

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main(void)
{
    int twenties, tens, fives, ones;

    printf("Enter a dollar amount: ");
    scanf("%d", &ones);
    
    pay_amount(ones, &twenties, &tens, &fives, &ones);

    printf("\n$20 bills: %d\n$10 bills: %d\n $5 bills: %d\n $1 bills: %d\n",
        twenties, tens, fives, ones);

    return 0;
}

/*
 * 'amount' is divided (integer division) by the value of the bill to get
 * the maximum number of bills to fill the amount without exceeding it.
 * Then 'amount' is reduced by the total value of those bills.
 */
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{
    *twenties = dollars / TWENTY;
    *ones -= TWENTY * *twenties;
    
    *tens = *ones / TEN;
    *ones -= TEN * *tens;
    
    *fives = *ones / FIVE;
    *ones -= FIVE * *fives;
}
