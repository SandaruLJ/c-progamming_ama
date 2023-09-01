/* Reads a message, then checks whether it's a palindrome */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int read_msg(int len, char message[len]);
bool is_palindrome(const char *message);

int main(void)
{
    char message[MAX_LENGTH];

    printf("Enter a message: ");
    read_msg(MAX_LENGTH, message);

    if (is_palindrome(message))
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");

    return 0;
}

int read_msg(int len, char message[len])
{
    int real_len = 0;

    for (char *p = message; p < message + len; p++)
    {
        char ch = tolower(getchar());

        if (ch == '\n')
        {
            *p = '\0';
            break;
        }

        if (isalpha(ch))
        {
            *p = ch;
            real_len++;
        }
        else
            p--;
    }

    return real_len;
}

bool is_palindrome(const char *message)
{
    const char *p = message;
    int len = strlen(message);

    while (*p)
    {
        if (!(*p == *(message + (len - 1) - (p - message))))
            return false;
        p++;
    }

    return true;
}
