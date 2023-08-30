/*
 * Takes a first name and last name entered by the user and displays
 * the last name, a comma, and the first initial, followed by a period.
 */

#include <stdio.h>
#include <string.h>

#define MAX 100

void reverse_name(char *name);

int main(void)
{
    char name[MAX];

    printf("Enter a first and last name: ");
    fgets(name, MAX, stdin);

    reverse_name(name);
    printf("%s\n", name);

    return 0;
}

void reverse_name(char *name)
{
    char *p = name;

    // discard preceding white space (if any)
    while (*p == ' ')
        p++;

    // printf("Reversed: %s\n", p);

    char first_initial[2];
    first_initial[0] = *p;
    first_initial[1] = '\0';

    // skip the rest of the first name
    while (*p++ != ' ')
        ;

    // advance to the last name
    while (*p == ' ')
        p++;

    // put last name in the beginning of the string
    char *last_name_start = p;
    while (*p != ' ' && *p != '\n')
        p++;
    *p = '\0';
    
    strcpy(name, last_name_start);
    strcat(name, " ");
    strcat(name, first_initial);
    strcat(name, ".");
}
