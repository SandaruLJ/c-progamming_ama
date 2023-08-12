/* Reads a message, then prints the reversal of it */

#include <stdio.h>

#define MAX_LENGTH 100

int read_msg(char message[], int len);
void reverse_msg(char message[], int len);

int main(void)
{
    char message[MAX_LENGTH];

    printf("Enter a message: ");
    int len = read_msg(message, MAX_LENGTH);

    printf("Reversal is: ");
    reverse_msg(message, len);
    printf("\n");

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

void reverse_msg(char message[], int len)
{
    for (char *p = message + len - 1; p >= message; p--)
        putchar(*p);
}
