/* Encrypts a message using the Caesar cipher */

#include <stdio.h>

#define LENGTH 80
#define LIMIT 26  // Number of letters in the alphabet

int main(void)
{
    char plaintext[LENGTH], ch;
    int key;

    printf("Enter message to be encrypted: ");
    for (int i = 0; i < LENGTH; i++)
        if ((plaintext[i] = getchar()) == '\n')
            break;

    printf("Enter shift amount (1-25): ");
    scanf("%d", &key);

    printf("Encrypted message: ");
    for (int i = 0; i < LENGTH; i++)
    {
        if (plaintext[i] == '\n')
        {
            putchar('\n');
            break;
        }

        ch = plaintext[i];

        if (ch >= 'A' && ch <= 'Z')
            putchar(((ch - 'A') + key) % 26 + 'A');
        else if (ch >= 'a' && ch <= 'z')
            putchar(((ch - 'a') + key) % 26 + 'a');
        else
            putchar(ch);
    }

    return 0;
}