/*
 * Prints a table of squares up to a given number 'n'
 * The programme pauses after every 24 squares and displays the message
 * "Press Enter to continue..." and waits for user input to continue
 */

#include <stdio.h>

int main(void)
{
    int i, n;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        if (i % 24 == 1)
        {
            printf("\nPress Enter to continue...");
            
            while (getchar() != '\n')
                ;
            
            printf("\n");
        }

        printf("%10d%10d\n", i, i * i);
    }

    return 0;
}