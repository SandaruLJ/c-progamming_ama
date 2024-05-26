#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readline.h"

#define WORD_LEN 20
#define MAX_WORDS 10

void enter_words(void);
void sort_words(void);
void print_words(void);
void free_words(void);

char *words[MAX_WORDS];
int word_count;

int main(void)
{
    word_count = 0;

    enter_words();
    sort_words();
    print_words();
    free_words();

    return 0;
}

void enter_words(void)
{
    while (true)
    {
        printf("Enter word: ");
        char *word = malloc(WORD_LEN + 1);
        int len = read_line(word, WORD_LEN);

        if (len == 0)
            break;

        words[word_count++] = word;
    }
}

void sort_words(void)
{
    bool swapped = true;
    int sorted = 0;

    while (swapped)
    {
        swapped = false;

        for (int i = 0; i < (word_count - 1) - sorted; i++)
            if (strcmp(words[i], words[i + 1]) > 0)
            {
                char *tmp = words[i];
                words[i] = words[i + 1];
                words[i + 1] = tmp;

                swapped = true;
            }
        
        sorted++;
    }
}

void print_words(void)
{
    printf("\nIn sorted order: ");
    for (int i = 0; i < word_count; i++)
        printf("%s ", words[i]);
    printf("\n");
}

void free_words(void)
{
    for (int i = 0; i < word_count; i++)
        free(words[i]);
}
