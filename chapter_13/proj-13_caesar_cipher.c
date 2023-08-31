/* Encrypts a message using the Caesar cipher */

#include <ctype.h>
#include <stdio.h>

#define LENGTH 80
#define LIMIT 26  // Number of letters in the alphabet

void encrypt(char *message, int shift);

int main(void)
{
    char message[LENGTH];
    int key;

    printf("Enter message to be encrypted: ");
    fgets(message, LENGTH, stdin);

    printf("Enter shift amount (1-25): ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted message: %s", message);
    

    return 0;
}

void encrypt(char *message, int shift)
{
    while (*message != '\n')
    {
        if (isalpha(*message))
        {
            if (isupper(*message))
                *message = ((*message - 'A') + shift) % 26 + 'A';
            else
                *message = ((*message - 'a') + shift) % 26 + 'a';
        }

        message++;
    }

    // for (int i = 0; i < LENGTH; i++)
    // {
    //     if (plaintext[i] == '\n')
    //     {
    //         putchar('\n');
    //         break;
    //     }

    //     ch = plaintext[i];

    //     if (ch >= 'A' && ch <= 'Z')
    //         putchar(((ch - 'A') + key) % 26 + 'A');
    //     else if (ch >= 'a' && ch <= 'z')
    //         putchar(((ch - 'a') + key) % 26 + 'a');
    //     else
    //         putchar(ch);
    // }
}
