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
    int real_len = 0;

    for (char *p = message; p < message + len; p++)
    {
        char ch = tolower(getchar());

        if (ch == '\n')
            break;

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

bool check_palindrome(int len, char message[len])
{
    for (char *p = message; p < message + len; p++)
        if (!(*p == *(message + (len - 1) - (p - message))))
            return false;

    return true;
}
