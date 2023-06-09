/* Converts a numerical grade into a letter using a switch */

#include <stdio.h>

int main(void)
{
    int marks, tens_digit;

    printf("Enter numerical grade: ");
    scanf("%d", &marks);

    tens_digit = marks / 10;

    if (marks < 0 || marks > 100)
    {
        printf("Error: invalid value given for marks!\n");
        return 1;
    }

    printf("Letter grade: ");

    switch (tens_digit)
    {
        case 10: case 9:
            printf("A");
            break;
        case 8:
            printf("B");
            break;
        case 7:
            printf("C");
            break;
        case 6:
            printf("D");
            break;
        default:
            printf("F");
            break;
    }

    printf("\n");

    return 0;
}