/* Reads a message, then prints the reversal of it */

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int read_msg(char message[], int len);
void reverse(char *message);

int main(void)
{
    char message[MAX_LENGTH];

    printf("Enter a message: ");
    read_msg(message, MAX_LENGTH);

    printf("Reversal is: ");
    reverse(message);
    printf("%s\n", message);

    return 0;
}

int read_msg(char message[], int max_len)
{
    int len = 0;

    for (char *p = message; p < message + max_len; p++)
    {
        char ch = getchar();

        if (ch == '\n')
            break;

        *p = ch;
        len++;
    }

    return len;
}

void reverse(char *message)
{
    char *left = message;
    char *right = message + strlen(message) - 1;

    while (left < right)
    {
        char tmp = *left;
        *left = *right;
        *right = tmp;

        left++;
        right--;
    }   
}
