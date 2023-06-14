/* Counts the number of vowels in a sentence */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char input;
    short vowels_sum = 0;

    printf("Enter a sentence: ");

    do {
        input = toupper(getchar());

        if (input == 'A' || input == 'E' || input == 'I' || input == 'O' || input == 'U')
            vowels_sum++;
    } while (input != '\n');

    printf("Your sentence contains %d vowels.\n", vowels_sum);

    return 0;
}