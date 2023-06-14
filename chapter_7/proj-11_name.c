/*
 * Takes a first name and last name entered by the user and displays
 * the last name, a comma, and the first initial, followed by a period.
 */

#include <stdio.h>

int main(void)
{
    char first_initial, input;

    printf("Enter a first and last name: ");
    
    // Get first initial and discard the rest of the first name
    scanf(" %c", &first_initial);
    while (getchar() != ' ')
        ;

    // Print last name
    while ((input = getchar()) != '\n')
        if (input != ' ')
            putchar(input);

    // Print first initial
    printf(", %c.\n", first_initial);

    return 0;
}