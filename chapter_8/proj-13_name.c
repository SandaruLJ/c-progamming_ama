/*
 * Takes a first name and last name entered by the user and displays
 * the last name, a comma, and the first initial, followed by a period.
 */

#include <stdio.h>

#define SIZE 20

int main(void)
{
    char first_initial, last_name[SIZE];

    printf("Enter a first and last name: ");
    
    // Get first initial and discard the rest of the first name
    scanf(" %c", &first_initial);
    while (getchar() != ' ')
        ;

    for (int i = 0; i < SIZE; i++)
    {
        last_name[i] = getchar();
        if (last_name[i] == '\n' || last_name[i] == ' ')
        break;
    }

    printf("You entered the name: ");

    for (int i = 0; i < SIZE; i++)
    {
        if (last_name[i] == '\n' || last_name[i] == ' ')
            break;
        putchar(last_name[i]);
    }

    printf(", %c.\n", first_initial);

    return 0;
}