/* Converts a 24-hour time to 12-hour form */

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int hour, minute;
    bool pm = false;

    printf("Enter a 24-hour time: ");
    scanf("%d :%d", &hour, &minute);

    pm = (hour >= 12) ? true : false;

    if (hour > 12)
        hour -= 12;
    else if (hour == 0)
        hour = 12;

    printf("Equivalent 12-hour time: %.2d:%.2d ", hour, minute);
    printf(pm ? "PM\n" : "AM\n");

    return 0;
}