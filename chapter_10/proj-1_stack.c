/* Checks if a series of parentheses and/or braces are properly nested */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

/* external variables */
char contents[STACK_SIZE];
int top = 0;
bool nested_properly = true;

/* prototypes */
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char c);
char pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void)
{
    char c;

    printf("Enter parentheses and/or braces: ");

    while (nested_properly)
    {
        c = getchar();
        
        if (c == '(' || c == '{')
        {
            push(c);
        }
        else if ((c == ')' && pop() != '(') || (c == '}' && pop() != '{'))
        {
            nested_properly = false;
        }
        else if (c == '\n')
        {
            if (!is_empty())
            {
                nested_properly = false;
            }

            break;
        }
    }

    if (nested_properly)
    {
        printf("Parentheses/braces are nested properly.\n");
    }
    else
    {
        printf("Parentheses/braces are NOT nested properly.\n");
    }

    return 0;
}


void make_empty(void)
{
    top = 0;
}


bool is_empty(void)
{
    return top == 0;
}


bool is_full(void)
{
    return top == STACK_SIZE;
}


void push(char c)
{
    if (is_full())
        stack_overflow();
    
    contents[top++] = c;
}


char pop(void)
{
    if (is_empty())
        stack_underflow();
    
    return contents[--top];
}


void stack_overflow(void)
{
    printf("Stack overflow.\n");
    exit(EXIT_FAILURE);
}


void stack_underflow(void)
{
    nested_properly = false;
}
