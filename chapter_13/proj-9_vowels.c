/* Counts the number of vowels in a sentence */

#include <stdio.h>
#include <ctype.h>

#define MAX 100

int compute_vowel_count(const char *sentence);

int main(void)
{
    char input[MAX];

    printf("Enter a sentence: ");
    fgets(input, MAX, stdin);

    int count = compute_vowel_count(input);
    printf("Your sentence contains %d vowels.\n", count);

    return 0;
}

int compute_vowel_count(const char *sentence)
{
    int sum = 0;

    while (*sentence != '\n')
    {
        char ch = toupper(*sentence);

        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            sum++;

        sentence++;
    }

    return sum;
}
