/* Indicates which date comes earlier on the calendar */

#include <stdio.h>

int main(void)
{
    int month, day, year, entered_date, earliest_date;
    int earliest_month = 0, earliest_day = 0, earliest_year = 0;

    while (1)
    {
        printf("Enter a date (mm/dd/yy): ");
        scanf("%d /%d /%2d", &month, &day, &year);

        entered_date = year * 365 + month * 30 + day;
        
        if (entered_date == 0)
            break;
        
        earliest_date = earliest_year * 365 + earliest_month * 30 + earliest_day;

        if (earliest_date == 0 || entered_date < earliest_date)
        {
            earliest_year = year;
            earliest_month = month;
            earliest_day = day;
        }
    }
    
    printf("%d/%d/%.2d is the earliest date\n", earliest_month, earliest_day, earliest_year);

    return 0;
}