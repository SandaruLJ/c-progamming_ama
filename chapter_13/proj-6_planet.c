/* Checks planet names */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define NUM_PLANETS 9

void capitalize(char *string);

int main(int argc, char *argv[])
{
	char *planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter",
					   "Saturn", "Uranus", "Neptune", "Pluto"};
    
    int i, j;

    for (i = 1; i < argc; i++)
    {
    	// transform input so that they conform with the planets array
    	capitalize(argv[i]);

    	for (j = 0; j < NUM_PLANETS; j++)
    		if (strcmp(argv[i], planets[j]) == 0)
    		{
    			printf("%s is planet %d\n", argv[i], j + 1);
    			break;
    		}
    	if (j == NUM_PLANETS)
    		printf("%s is not a planet\n", argv[i]);
    }

	return 0;
}

void capitalize(char *string)
{
	if (*string)
		*string++ = toupper(*string);

	while (*string)
		*string++ = tolower(*string);
}
