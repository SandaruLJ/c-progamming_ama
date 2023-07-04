/*
 * Asks the user to enter a series of integers, then sorts them using
 * selection sort.
 * 
 * Procedure: Search the array to find the largest element, then move it
 * to the last position of the array.
 * Do this recursively to sort the first n - 1 elements of the array.
*/

#include <stdio.h>

#define SIZE (sizeof(integers) / sizeof(integers[0]))

void selection_sort(int n, int integers[n]);

int main(void)
{
    int integers[10];

    printf("Enter a series of integers (%d): ", (int) SIZE);

    for (int i = 0; i < (int) SIZE; i++)
    {
        scanf("%d", &integers[i]);
    }

    selection_sort(SIZE, integers);

    printf("Sorted:");
    for (int i = 0; i < (int) SIZE; i++)
    {
        printf(" %d", integers[i]);
    }
    printf("\n");
}

void selection_sort(int n, int integers[n])
{
    int temp, max = integers[0], max_idx = 0;

    for (int i = 0; i < n; i++)
    {
        if (integers[i] > max)
        {
            max = integers[i];
            max_idx = i;
        }
    }

    temp = integers[n - 1];
    integers[n - 1] = integers[max_idx];
    integers[max_idx] = temp;

    if (n > 1)
        selection_sort(n - 1, integers);
}
