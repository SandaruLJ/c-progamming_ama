/* Indicates which of two dates comes earlier on the calendar */

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int month_1, day_1, year_1, month_2, day_2, year_2;
    bool first_date_earlier = false;

    printf("Enter first date (mm/dd/yy): ");
    scanf("%d /%d /%2d", &month_1, &day_1, &year_1);
    printf("Enter second date (mm/dd/yy): ");
    scanf("%d /%d /%2d", &month_2, &day_2, &year_2);

    if (year_1 * 365 + month_1 * 30 + day_1 < year_2 * 365 + month_2 * 30 + day_2)
        first_date_earlier = true;
    
    if (first_date_earlier)
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", day_1, month_1, year_1, day_2, month_2, year_2);
    else
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", day_2, month_2, year_2, day_1, month_1, year_1);

    return 0;
}