/*
 * Evaluates RPN expressions
 *
 * Examples (normal -> RPN): 1 + 2 -> 1 2 +; 1 + 2 * 3 -> 1 2 3 * +
 * 
 * Can be evaluated using a stack:
 *   1. When an operand is encountered, push it onto the stack.
 *   2. When an operator is encountered, pop its operands from the stack,
 *      perform the operation on them, and then push the result onto the stack.
 * 
 * If the stack overflows, display the message 'Expression is too complicated'
 * and terminate.
 * If the stack underflows (because of a expression such as 1 2 + +), display
 * the message 'Not enough operands in expression' and terminate.
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define NUM_OPERANDS 2

void evaluate(char ch);

int main(void)
{
    while (true)
    {
        printf("Enter an RPN expression: ");
        
        do
        {
            char ch;
            scanf(" %c", &ch);
            
            evaluate(ch);
        }
        while (top > 0);
    }

    return 0;
}

void evaluate(char ch)
{
    if (isdigit(ch))
            push(ch);
    else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        // get operands corresponding to the operation
        int operands[NUM_OPERANDS];
        for (int i = 0; i < NUM_OPERANDS; i++)
            operands[i] = pop() - '0';

        int result = 0;
        
        switch(ch)
        {
            case '+':
                result = operands[1] + operands[0];
                break;
            case '-':
                result = operands[1] - operands[0];
                break;
            case '*':
                result = operands[1] * operands[0];
                break;
            case '/':
                result = operands[1] / operands[0];
        }

        push((char) result + '0');
    }
    else if (ch == '=')
    {
        printf("Value of expression: %d\n", pop() - '0');
        make_empty();
    }
    else
        exit(EXIT_SUCCESS);
}
