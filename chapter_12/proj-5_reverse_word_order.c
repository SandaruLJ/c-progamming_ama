/* Reverses the words in a sentence */

#include <stdio.h>

#define SIZE 50

int main(void)
{
    char sentence[SIZE], input, term_char = '.';
    int length = 0;

    printf("Enter a sentence: ");
    for (char *p = sentence; p < sentence + SIZE; p++)
    {
        input = getchar();
        
        if (input == '.' || input == '?' || input == '!')
        {
            term_char = input;
            break;
        }
        
        *p = input;
        length++;
    }

    printf("Reversal of sentence: ");
    for (char *p = sentence + length - 1; p >= sentence; p--)
    {
        if (*p == ' ')
        {
            for (char *q = p + 1; (q <= sentence + length - 1) && *q != ' '; q++)
                putchar(*q);
            
            putchar(' ');
        }
        else if (p == sentence)
        {
            for (char *q = sentence; *q != ' '; q++)
                putchar(*q);
        }
    }

    printf("%c\n", term_char);

    return 0;
}