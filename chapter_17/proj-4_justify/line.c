#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

struct line
{
    char *word;
    struct line *next;
};

struct line *line, *last_word;
unsigned int line_len = 0;
unsigned int num_words = 0;

void clear_line(void)
{
    struct line *curr = line, *next;

    if (curr == NULL)
        return;

    next = curr->next;
    while (next)
    {
        if (curr->word)
            free(curr->word);
        free(curr);

        curr = next;
        next = curr->next;
    }
    free(curr);

    line = NULL;
    last_word = NULL;
    line_len = 0;
    num_words = 0;
}

void add_word(const char *word)
{
    struct line *node = malloc(sizeof(struct line));
    char *content = malloc(strlen(word));
    strcpy(content, word);
    node->word = content;

    if (last_word)
        last_word->next = node;
    else
        line = node;
    last_word = node;

    line_len += strlen(word);
    num_words++;
}

int space_remaining(void)
{
    int spaces_between = (num_words ? num_words - 1 : 0);
    return MAX_LINE_LEN - (line_len + spaces_between);
}

void write_line(void)
{
    int extra_spaces, spaces_to_insert;
    int spaces_between = (num_words ? num_words - 1 : 0);

    extra_spaces = MAX_LINE_LEN - (line_len + spaces_between);

    struct line *node = line;
    while (true)
    {
        printf("%s", node->word); 

        if (num_words == 1)
            break;
        
        spaces_to_insert = extra_spaces / (num_words - 1);
        for (int j = 1; j <= spaces_to_insert + 1; j++)
            putchar(' ');
        extra_spaces -= spaces_to_insert;
        num_words--;

        node = node->next;
    }
    putchar('\n');
}

void flush_line(void)
{
    if (line_len > 0)
    {
        struct line *node = line;
        while (node)
        {
            printf("%s", node->word); 
            node = node->next;
            if (node)
                putchar(' ');
        }
        putchar('\n');
    }
}
