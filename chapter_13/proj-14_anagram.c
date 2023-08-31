/* Tests whether two words are anagrams */

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 30
#define SIZE 26  // Alphabet size

bool are_anagrams(const char *word1, const char *word2);

int main(void)
{
    char word1[MAX_LEN], word2[MAX_LEN];

    printf("Enter first word: ");
    fgets(word1, MAX_LEN, stdin);
    
    printf("Enter second word: ");
    fgets(word2, MAX_LEN, stdin);
    
    bool anagrams = are_anagrams(word1, word2);
    printf(anagrams ? "The words are anagrams.\n"
                        : "The words are not anagrams.\n");

    return 0;
}

bool are_anagrams(const char *word1, const char *word2)
{
    int letter_frequencies[SIZE] = {0};

    while (*word1 != '\n')
    {
        if (isalpha(*word1))
            letter_frequencies[toupper(*word1) - 'A']++;
        word1++;
    }

    while (*word2 != '\n')
    {
        if (isalpha(*word2))
            letter_frequencies[toupper(*word2) - 'A']--;
        word2++;
    }

    for (int i = 0; i < SIZE; i++)    
        if (letter_frequencies[i] != 0)
            return false;
    return true;
}
