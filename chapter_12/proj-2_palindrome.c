/* Reads a message, then checks whether it's a palindrome */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_LENGTH 100

int read_msg(int len, char message[len]);
bool check_palindrome(int len, char message[len]);

int main(void)
{
    char message[MAX_LENGTH];

    printf("Enter a message: ");
    int len = read_msg(MAX_LENGTH, message);

    if (check_palindrome(len, message))
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");

    return 0;
}

int read_msg(int len, char message[len])
{
    int idx = 0;

    for (; idx < len; idx++)
    {
        char ch = tolower(getchar());

        if (ch == '\n')
            break;

        if (isalpha(ch))
            message[idx] = ch;
        else
            idx--;
    }

    return idx;
}

bool check_palindrome(int len, char message[len])
{
    for (int i = 0; i < len; i++)
        if (!(message[i] == message[(len - 1) - i]))
            return false;

    return true;
}
