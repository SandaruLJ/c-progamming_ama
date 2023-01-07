/* This programme calculates the volume of a sphere with a 10-meter radius */

#include <stdio.h>

#define PI (22.0 / 7.0)
#define FRACTION (4.0f / 3.0f)

int main(void)
{
    int radius = 10;

    // Volume is calculated using: v = 4/3 * pi * r^3
    printf("Volume of a sphere with a %d-meter radius: %.2f\n",
        radius, FRACTION * PI * radius * radius * radius);

    return 0;
}