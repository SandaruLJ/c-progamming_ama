/*
 * Calculates the average word length for a sentence.
 * For simplicity, punctuation marks are considered to be part of a word.
 */

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    float avg;
    int letter_sum = 0, num_of_words = 0;
    char input;
    bool inside_word = false;

    printf("Enter a sentence: ");

    while ((input = getchar()) != '\n')
    {
        if (input != ' ')
        {
            if (!inside_word)  // Increment word count when starting new one
            {
                inside_word = true;
                num_of_words++;
            }
            
            letter_sum++;
        }
        else
        {
            inside_word = false;
        }
    }
    
    avg = (float) letter_sum / num_of_words;

    printf("Average word length: %.1f\n", avg);

    return 0;
}