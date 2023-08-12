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
    int idx = 0;

    for (; idx < max_len; idx++)
    {
        char ch = getchar();

        if (ch == '\n')
            break;

        message[idx] = ch;
    }

    return idx;
}

void reverse_msg(char message[], int len)
{
    for (int i = len - 1; i >= 0; i--)
        putchar(message[i]);
}
