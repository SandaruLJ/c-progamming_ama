/* Indicates which of two dates comes earlier on the calendar */

#include <stdio.h>
#include <stdbool.h>

struct date
{
    int year, month, day;
};

int compare_dates(struct date d1, struct date d2);

int main(void)
{
    struct date d1, d2;

    printf("Enter first date (mm/dd/yy): ");
    scanf("%d /%d /%2d", &d1.month, &d1.day, &d1.year);
    printf("Enter second date (mm/dd/yy): ");
    scanf("%d /%d /%2d", &d2.month, &d2.day, &d2.year);

    int result = compare_dates(d1, d2);
    if (result == -1)
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", d1.day, d1.month, d1.year, d2.day, d2.month, d2.year);
    else if (result == 1)
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", d2.day, d2.month, d2.year, d1.day, d1.month, d1.year);
    else
        printf("The dates are the same\n");

    return 0;
}

int compare_dates(struct date d1, struct date d2)
{
    if (d2.year < d1.year || d2.month < d1.month || d2.day < d1.day)
        return 1;
    else if (d1.year < d2.year || d1.month < d2.month || d1.day < d2.day)
        return -1;
    return 0;
}
