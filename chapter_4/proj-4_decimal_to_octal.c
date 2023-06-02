/* Displays the user input integer in octal */

#include <stdio.h>
#define DIVIDER 8  // Divider for converting to octal 

int main(void)
{
    int number, d1, d2, d3, d4, d5;

    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &number);

    d5 = number % DIVIDER;
    number /= DIVIDER;
    d4 = number % DIVIDER;
    number /= DIVIDER;
    d3 = number % DIVIDER;
    number /= DIVIDER;
    d2 = number % DIVIDER;
    number /= DIVIDER;
    d1 = number % DIVIDER;
    number /= DIVIDER;

    printf("In octal, your number is: %d%d%d%d%d\n", d1, d2, d3, d4, d5);

    return 0;
}