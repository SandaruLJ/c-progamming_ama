#include <stdio.h>
#include <stdlib.h>
#include "ex4.h"

#define MAX_SIZE 100

struct stack_type
{
    Item data[MAX_SIZE];
    int top;
};

static void terminate(char *msg)
{
    printf("%s\n", msg);
    exit(EXIT_FAILURE);
}

Stack stack_create()
{
    Stack s = malloc(sizeof(struct stack_type));
    if (s == NULL)
        terminate("Error in stack_create(): could not allocate memory");

    s->top = 0;

    return s;
}

void stack_destroy(Stack s)
{
    free(s);
}

void stack_push(Stack s, Item i)
{
    if (stack_is_full(s))
        terminate("Error in stack_push(): stack is full");

    s->data[s->top++] = i;
}

Item stack_pop(Stack s)
{
    if (stack_is_empty(s))
        terminate("Error in stack_pop(): stack is empty");

    return s->data[--s->top];
}

void stack_make_empty(Stack s)
{
    s->top = 0;
}

bool stack_is_empty(Stack s)
{
    return s->top == 0;
}

bool stack_is_full(Stack s)
{
    return s->top == MAX_SIZE;
}

