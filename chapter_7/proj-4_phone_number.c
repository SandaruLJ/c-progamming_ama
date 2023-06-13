/*
 * Translates an alphabetic phone number to numeric form
 * Any non-alphabetic character (digit or punctuation) is left unchanged
 */

#include <stdio.h>

int main(void)
{
    char input;

    printf("Enter phone number: ");

    do {
        input = getchar();

        if (input >= 65 && input <= 67)
            putchar('2');
        else if (input >= 68 && input <= 70)
            putchar('3');
        else if (input >= 71 && input <= 73)
            putchar('4');
        else if (input >= 74 && input <= 76)
            putchar('5');
        else if (input >= 77 && input <= 79)
            putchar('6');
        else if (input >= 80 && input <= 82)
            putchar('7');
        else if (input >= 83 && input <= 85)
            putchar('8');
        else if (input >= 86 && input <= 88)
            putchar('9');
        else
            putchar(input);
    } while (input != '\n');

    return 0;
}