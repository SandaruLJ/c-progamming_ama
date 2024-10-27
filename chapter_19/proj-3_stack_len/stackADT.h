#ifndef STACKADT_H
#define STACKADT_H

#include <stdbool.h>

typedef char Item;

typedef struct stack_type *Stack;

Stack create();
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
int length(Stack s);
void push(Stack s, Item i);
Item pop(Stack s);

#endif

