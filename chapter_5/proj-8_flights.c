/*
 * Displays the departure and arrival times for the flight
 * whose departure time is closest to that entered by the user (24-hour form)
 * [INCOMPLETE]
 */

#include <stdio.h>
#include <stdlib.h>

#define T0800 8 * 60
#define T0943 9 * 60 + 43
#define T1119 11 * 60 + 19
#define T1247 12 * 60 + 47
#define T1400 14 * 60
#define T1545 15 * 60 + 45
#define T1900 19 * 60
#define T2145 21 * 60 + 45

int main(void)
{
    int hours, minutes, total_minutes, difference, closest_time;

    printf("Enter a 24-hour time: ");
    scanf("%d :%d", &hours, &minutes);

    total_minutes = hours * 60 + minutes;
    difference = abs(total_minutes - T0800);
    closest_time = T0800;

    if (abs(total_minutes - T0943) < difference)
    {
        closest_time = T0943;
        difference = total_minutes - closest_time;
    }
    if (abs(total_minutes - T1119) < difference)
    {
        closest_time = T1119;
        difference = total_minutes - closest_time;
    }
    if (abs(total_minutes - T1247) < difference)
    {
        closest_time = T1247;
        difference = total_minutes - closest_time;
    }
    if (abs(total_minutes - T1400) < difference)
    {
        closest_time = T1400;
        difference = total_minutes - closest_time;
    }
    if (abs(total_minutes - T1545) < difference)
    {
        closest_time = T1545;
        difference = total_minutes - closest_time;
    }
    if (abs(total_minutes - T1900) < difference)
    {
        closest_time = T1900;
        difference = total_minutes - closest_time;
    }
    if (abs(total_minutes - T2145) < difference)
    {
        closest_time = T2145;
        difference = total_minutes - closest_time;
    }

    switch (closest_time)
    {
        case T0943:
            printf("Closest departure time is 09:43 a.m., arriving at 11:52 a.m.\n");
            break;
        case T1119:
            printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.\n");
            break;
        case T1247:
            printf("Closest departure time is 12:47 p.m., arriving at 3:00 p.m.\n");
            break;
        case T1400:
            printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.\n");
            break;
        case T1545:
            printf("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.\n");
            break;
        case T1900:
            printf("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.\n");
            break;
        case T2145:
            printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.\n");
            break;
        default:
            printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
            break;
    }

    return 0;
}