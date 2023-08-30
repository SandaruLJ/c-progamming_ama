/* Prints the English word for a two-digit number */

#include <stdio.h>

int main(void)
{
    char *tens_digit_strs[] = {"twenty", "thirty", "fourty", "fifty", "sixty",
                             "seventy", "eighty", "ninety"};
    char *ones_digit_strs[] = {"zero", "one", "two", "three", "four", "five", "six",
                             "seven", "eight", "nine"};
    char *ones_digit_strs_special[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
                                     "sixteen", "seventeen", "eighteen", "nineteen"};

    int tens_digit, ones_digit;

    printf("Enter a two-digit number: ");
    scanf("%1d%1d", &tens_digit, &ones_digit);

    // Ten's digit
    // Two-digit values except 11-19
    if (tens_digit > 1)
        printf("%s", tens_digit_strs[tens_digit - 2]);

    // Special cases (10-19)
    if (tens_digit == 1)
        printf("%s", ones_digit_strs_special[ones_digit]);
    else
    {
        if (tens_digit && ones_digit)
            printf("-");

        if (ones_digit)
            printf("%s", ones_digit_strs[ones_digit]);
        else if (!tens_digit)
            printf("%s", ones_digit_strs[0]);
    }

    printf("\n");

    return 0;
}