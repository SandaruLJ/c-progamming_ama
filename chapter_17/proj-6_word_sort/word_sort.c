#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readline.h"

#define WORD_LEN 20
#define MAX_WORDS 10

void enter_words(void);
void print_words(void);
void free_words(void);
int compar(const void *str1, const void *str2);

char *words[MAX_WORDS];
int word_count;

int main(void)
{
    word_count = 0;

    enter_words();
    qsort(words, word_count, sizeof(char *), compar);
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

int compar(const void *str1, const void *str2)
{
    return strcmp(*(const char **) str1, *(const char **) str2);
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
