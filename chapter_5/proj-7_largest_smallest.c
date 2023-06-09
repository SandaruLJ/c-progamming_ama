/* Finds the largest and smallest of four integers */

#include <stdio.h>

int main(void)
{
    int i1, i2, i3, i4, largest, smallest;

    printf("Enter four integers: ");
    scanf("%d%d%d%d", &i1, &i2, &i3, &i4);

    largest = i1;
    smallest = i1;

    if (i2 > i1 && i2 > i3 && i2 > i4)
        largest = i2;
    else if (i3 > i1 && i3 > i2 && i3 > i4)
        largest = i3;
    else if (i4 > i1 && i4 > i2 && i4 > i3)
        largest = i4;

    if (i2 < i1 && i2 < i3 && i2 < i4)
        smallest = i2;
    else if (i3 < i1 && i3 < i2 && i3 < i4)
        smallest = i3;
    else if (i4 < i1 && i4 < i2 && i4 < i3)
        smallest = i4;

    printf("Largest: %d\n", largest);
    printf("Smallest: %d\n", smallest);


    return 0;
}