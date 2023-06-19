/*
 * Reads a message entered by the user and translates it into B1FF-speak.
 * B1IFF-speak conversion: convert message to upper-case letters,
 * substitute digits for certain letters (A->4, B->8, E->3, I->1, O->0, S->5),
 * and append 10 or so exclamation marks.
 */

#include <stdio.h>
#include <ctype.h>

#define LENGTH 100

int main(void)
{
    char message[LENGTH];

    printf("Enter message: ");
    for (int i = 0; i < LENGTH; i++)
    {
        message[i] = getchar();
        if (message[i] == '\n')
            break;
    }

    printf("In B1FF-speak: ");
    for (int i = 0; i < LENGTH; i++)
    {
        message[i] = toupper(message[i]);

        if (message[i] == '\n')
            break;

        switch (message[i])
        {
            case 'A': message[i] = '4'; break;
            case 'B': message[i] = '8'; break;
            case 'E': message[i] = '3'; break;
            case 'I': message[i] = '1'; break;
            case 'O': message[i] = '0'; break;
            case 'S': message[i] = '5'; break;
        }

        putchar(message[i]);
    }
    printf("!!!!!!!!!!\n");

    return 0;
}