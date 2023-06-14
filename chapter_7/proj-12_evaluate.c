/*
 * Evaluates an expression.
 * The operands in the expression are floating-point numbers.
 * The operators are +, -, *, and /.
 * The expression is evaluated from left to right, no operator precedence.
 * 
 * NOTE: Currently incomplete as the input prompt is not terminated until
 *       additional input is entered after entering the expression once.
 */

#include <stdio.h>

int main(void)
{
    float operand = 0.0f, value = 0.0f;
    char operator;

    printf("Enter an expression: ");

    // Get first operand and add it as initial value;
    scanf("%f", &operand);
    if (operand)
        value += operand;
    
    // Get next operator and operand
    while (1) 
    {
        scanf("%c%f", &operator, &operand);
        
        if (operator == '\n')
            break;

        switch (operator)
        {
            case '+': value += operand; break;
            case '-': value -= operand; break;
            case '*': value *= operand; break;
            case '/': value /= operand; break;
        }
    }

    printf("Value of expression: %.1f\n", value);

    return 0;
}