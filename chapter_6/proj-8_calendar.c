/* Prints a one-month calendar */

#include <stdio.h>

int main(void)
{
    int days, starting_day;

    printf("Enter number of days in month: ");
    scanf("%d", &days);
    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d", &starting_day);

    printf("\n");

    // Print blanks until starting day
    for (int i = 1; i < starting_day; i++)
    {
        printf("  ");

        if (i < starting_day)
            printf(" ");
    }

    // Print days
    for (int i = 1; i <= days; i ++)
    {
        printf("%2d", i);

        // Print new-line on last day of week; space otherwise
        if ((i + starting_day - 1) % 7 == 0)
            printf("\n");
        else
            printf(" ");
    }

    printf("\n");

    return 0;
}