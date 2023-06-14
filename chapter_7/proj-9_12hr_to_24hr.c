/* Converts and displays a 12-hour time in 24-hour form */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int hours, minutes;
    char indicator;

    printf("Enter a 12-hour time: ");
    scanf("%d :%d %c", &hours, &minutes, &indicator);

    indicator = toupper(indicator);

    if (indicator == 'P')
    {
        if (hours != 12)
            hours += 12;
    }
    else
    {
        if (hours == 12)
            hours = 0;
    }

    printf("Equivalent 24-hour time: %.2d:%.2d\n", hours, minutes);

    return 0;
}