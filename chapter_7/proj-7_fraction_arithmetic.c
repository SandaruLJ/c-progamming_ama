/*
 * Allows user to add, subtract, multiply or divide two fractions
 * (by entering either +, - , *, or / between the fractions)
 * NOTE: Result is not simplified
 */

#include <stdio.h>

int main(void)
{
    int num1, denom1, num2, denom2, result_num, result_denom;
    char operation;

    printf("Enter two fractions separated by an operator (+, -, *, /): ");
    scanf("%d /%d %c %d /%d", &num1, &denom1, &operation, &num2, &denom2);

    switch (operation)
    {
        case '+':
            result_num = (num1 * denom2) + (num2 * denom1);
            result_denom = denom1 * denom2;
            break;
        case '-':
            result_num = (num1 * denom2) - (num2 * denom1);
            result_denom = denom1 * denom2;
            break;
        case '*':
            result_num = num1 * num2;
            result_denom = denom1 * denom2;
            break;
        case '/':
            result_num = num1 * denom2;
            result_denom = denom1 * num2;
            break;
        default:
            result_num = 0;
            result_denom = 0;
            printf("Invalid operation!\n");
            break;
    }
    

    printf("The result is %d/%d\n", result_num, result_denom);

    return 0;
}