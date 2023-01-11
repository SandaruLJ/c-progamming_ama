/* This programme breaks down an ISBN entered by the user */

#include <stdio.h>

int main(void)
{
    int gs1, group, publisher, item_no, check;

    printf("Enter ISBN: ");
    scanf("%d-%d-%d-%d-%d", &gs1, &group, &publisher, &item_no, &check);

    printf("GS1 prefix: %d\n", gs1);
    printf("Group identifier: %d\n", group);
    printf("Publisher code: %d\n", publisher);
    printf("Item number: %d\n", item_no);
    printf("Check digit: %d\n", check);

    return 0;
}