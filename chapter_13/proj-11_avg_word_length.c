/*
 * Calculates the average word length for a sentence.
 * For simplicity, punctuation marks are considered to be part of a word.
 */

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

double compute_average_word_length(const char *sentence);

int main(void)
{
    char input[MAX];

    printf("Enter a sentence: ");
    fgets(input, MAX, stdin);
    
    double avg = compute_average_word_length(input);
    printf("Average word length: %.1f\n", avg);

    return 0;
}

double compute_average_word_length(const char *sentence)
{
    int letter_sum = 0, num_of_words = 0;
    bool inside_word = false;

    while (*sentence != '\n')
    {
        if (*sentence != ' ')
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

        sentence++;
    }
    
    return (double) letter_sum / num_of_words;
}
