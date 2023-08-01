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

#define STACK_SIZE 100
#define NUM_OPERANDS 2

/* prototypes */
void evaluate(char ch);
void push(char ch);
char pop(void);
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void stack_overflow(void);
void stack_underflow(void);

/* external variables */
char stack[STACK_SIZE];
int top = 0;

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

void push(char ch)
{
    if (is_full())
        stack_overflow();
    else
        stack[top++] = ch;
}

char pop(void)
{
    if (is_empty())
        stack_underflow();
    else
        return stack[--top];
}

void stack_overflow(void)
{
    printf("Expression is too complex\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
    printf("Not enough operands in expression\n");
    exit(EXIT_FAILURE);
}
