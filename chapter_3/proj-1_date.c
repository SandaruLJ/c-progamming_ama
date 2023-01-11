/*
 * This programme accepts a date from the user and then displays it
 * Input format: mm/dd/yyyy, Output format: yyyymmdd
*/

#include <stdio.h>

int main(void)
{
    int year, month, day;

    printf("Etner a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);

    printf("%d%.2d%.2d\n", year, month, day);

    return 0;
}