/* Tests whether two words are anagrams */

#include <stdio.h>
#include <ctype.h>

#define SIZE 26  // Alphabet size

int main(void)
{
    int letter_frequencies[SIZE] = {0};
    char ch;

    printf("Enter first word: ");
    while ((ch = getchar()) != '\n')
        if (isalpha(ch))
            letter_frequencies[toupper(ch) - 'A']++;

    printf("Enter second word: ");
    while ((ch = getchar()) != '\n')
        if (isalpha(ch))
            letter_frequencies[toupper(ch) - 'A']--;

    for (int i = 0; i < SIZE; i++)    
        if (letter_frequencies[i] != 0)
        {
            printf("The words are not anagrams.\n");
            return 0;
        }

    printf("The words are anagrams.\n");

    return 0;
}