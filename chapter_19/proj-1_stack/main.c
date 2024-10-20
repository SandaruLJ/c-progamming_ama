/* Checks if a series of parentheses and/or braces are properly nested */

#include <stdio.h>
#include <stdbool.h>
#include "stackADT.h"

#define STACK_SIZE 100

/* external variables */
bool nested_properly = true;

int main(void)
{
    Stack s = create(STACK_SIZE);
    char c;

    printf("Enter parentheses and/or braces: ");

    while (nested_properly)
    {
        c = getchar();
        
        if (c == '(' || c == '{')
            push(s, c);
        else if ((c == ')' && pop(s) != '(') || (c == '}' && pop(s) != '{'))
            nested_properly = false;
        else if (c == '\n')
        {
            if (!is_empty(s))
                nested_properly = false;
            break;
        }
    }

    if (nested_properly)
        printf("Parentheses/braces are nested properly.\n");
    else
        printf("Parentheses/braces are NOT nested properly.\n");

    destroy(s);

    return 0;
}

