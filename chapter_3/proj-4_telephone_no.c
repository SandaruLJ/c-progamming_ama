/*
 * This programme prompts the user to enter a telephone number "(xxx) xxx-xxxx"
 * and then displays it in the form "xxx.xxx.xxxx"
 */

#include <stdio.h>

int main(void)
{
    int area_code, prefix, subscriber;

    printf("Enter phone number [(xxx) xxx-xxxx]: ");
    scanf("(%d)%d-%d", &area_code, &prefix, &subscriber);

    printf("You entered %d.%d.%d\n", area_code, prefix, subscriber);

    return 0;
}