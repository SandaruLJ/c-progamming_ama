/*
 * Translates an alphabetic phone number to numeric form
 * Any non-alphabetic character (digit or punctuation) is left unchanged
 */

#include <stdio.h>

#define SIZE 15 

int main(void)
{
    char number[SIZE];

    printf("Enter phone number: ");

    for (int i = 0; i < SIZE; i++)
        if ((number[i] = getchar()) == '\n')
            break;

    printf("In numeric form: ");

    for (int i = 0; i < SIZE; i++)
    {
        if (number[i] >= 'A' && number[i] <= 'C')
            putchar('2');
        else if (number[i] >= 'D' && number[i] <= 'F')
            putchar('3');
        else if (number[i] >= 'G' && number[i] <= 'I')
            putchar('4');
        else if (number[i] >= 'J' && number[i] <= 'L')
            putchar('5');
        else if (number[i] >= 'M' && number[i] <= 'O')
            putchar('6');
        else if (number[i] >= 'P' && number[i] <= 'S')
            putchar('7');
        else if (number[i] >= 'T' && number[i] <= 'V')
            putchar('8');
        else if (number[i] >= 'W' && number[i] <= 'Y')
            putchar('9');
        else
            putchar(number[i]);

        if (number[i] == '\n')
            break;
    }

    return 0;
}