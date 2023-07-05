/* Tests whether two words are anagrams */

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define SIZE 26  // Alphabet size

void read_word(int counts[SIZE]);
bool equal_array(int counts1[SIZE], int counts2[SIZE]);

int main(void)
{
    int counts1[SIZE] = {0}, counts2[SIZE] = {0};

    printf("Enter first word: ");
    read_word(counts1);
    printf("Enter second word: ");
    read_word(counts2);
    
    printf(equal_array(counts1, counts2) ? "The words are anagrams.\n"
                                         : "The words are NOT anagrams.\n");

    return 0;
}

void read_word(int counts[SIZE])
{
    char ch;

    while ((ch = getchar()) != '\n')
        if (isalpha(ch))
            counts[toupper(ch) - 'A']++;

}

bool equal_array(int counts1[SIZE], int counts2[SIZE])
{
    for (int i = 0; i < SIZE; i++)    
        if (counts1[i] != counts2[i])
            return false;
    
    return true;
}
