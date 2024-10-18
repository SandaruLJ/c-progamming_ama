#include <stdio.h>
#include <stdlib.h>
#include "ex4.h"

struct node
{
    Item data;
    struct node *prev;
};

struct stack_type
{
    struct node *top;
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

    s->top = NULL;

    return s;
}

void stack_destroy(Stack s)
{
    stack_make_empty(s);
    free(s);
}

void stack_push(Stack s, Item i)
{
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        terminate("Error in stack_push(): could not allocate memory");

    new_node->data = i;
    new_node->prev = s->top;
    s->top = new_node;
}

Item stack_pop(Stack s)
{
    if (stack_is_empty(s))
        terminate("Error in stack_pop(): stack is empty");

    struct node *old_top = s->top;
    Item val = old_top->data;
    s->top = old_top->prev;

    free(old_top);

    return val;
}

void stack_make_empty(Stack s)
{
    while (!stack_is_empty(s))
        stack_pop(s);
}

bool stack_is_empty(Stack s)
{
    return s->top == NULL;
}

bool stack_is_full(Stack s)
{
    return false;
}

