/* Reverses the words in a sentence */

#include <stdio.h>

#define MAX_WORDS 30
#define MAX_WORD_LEN 20

int main(void)
{
    char sentence[MAX_WORDS][MAX_WORD_LEN], input, term_char = '.';
    int word_count = 0;

    printf("Enter a sentence: ");
    for (int i = 0; ; i++)
    {
        input = getchar();
        
        if (input == '.' || input == '?' || input == '!')
        {
            term_char = input;
            sentence[word_count][i] = '\0';
            word_count++;
            break;
        }
        
        if (input == ' ')
        {
            sentence[word_count][i] = '\0';
            word_count++;
            i = -1;
        }
        else
            sentence[word_count][i] = input;
    }

    printf("Reversal of sentence: ");
    for (int i = word_count - 1; i >= 0; i--)
    {
        printf("%s", sentence[i]);
        if (i)
            putchar(' ');
    }

    printf("%c\n", term_char);

    return 0;
}