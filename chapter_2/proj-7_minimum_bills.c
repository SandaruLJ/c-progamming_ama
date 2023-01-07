/* 
 * This programme takes a dollar amount and shows how to pay it
 * using the smallest number of $20, $10, $5 and $1 bills.
 */

#include <stdio.h>

#define TWENTY 20
#define TEN 10
#define FIVE 5

int main(void)
{
    int amount, bills_20, bills_10, bills_5;

    printf("Enter a dollar amount: ");
    scanf("%d", &amount);

    // 'amount' is divided (integer division) by the value of the bill to get
    // the maximum number of bills to fill the amount without exceeding it.
    // Then 'amount' is reduced by the total value of those bills.
    bills_20 = amount / TWENTY;
    amount -= TWENTY * bills_20;
    
    bills_10 = amount / TEN;
    amount -= TEN * bills_10;
    
    bills_5 = amount / FIVE;
    amount -= FIVE * bills_5;
    
    printf("\n$20 bills: %d\n$10 bills: %d\n $5 bills: %d\n $1 bills: %d\n",
        bills_20, bills_10, bills_5, amount);

    return 0;
}