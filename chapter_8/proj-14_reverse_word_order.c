/* Reverses the words in a sentence */

#include <stdio.h>

#define SIZE 50

int main(void)
{
    char sentence[SIZE], input, term_char = '.';
    int length = 0;

    printf("Enter a sentence: ");
    for (int i = 0; i < SIZE; i++)
    {
        input = getchar();
        
        if (input == '.' || input == '?' || input == '!')
        {
            term_char = input;
            break;
        }
        
        sentence[i] = input;
        length++;
    }

    printf("Reversal of sentence: ");
    for (int i = length - 1; i >= 0; i--)
    {
        if (sentence[i] == ' ')
        {
            for (int j = i + 1; (j <= length - 1) && sentence[j] != ' '; j++)
                putchar(sentence[j]);
            
            putchar(' ');
        }
        else if (i == 0)
        {
            for (int j = 0; sentence[j] != ' '; j++)
                putchar(sentence[j]);
        }
    }

    printf("%c\n", term_char);

    return 0;
}