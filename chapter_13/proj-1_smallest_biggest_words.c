/* Finds the smallest and largest in a series of words */

#include <stdio.h>
#include <string.h>

#define MAX 20

int main(void)
{
	char smallest_word[MAX+1] = "";
	char largest_word[MAX+1] = "";
	char input[MAX+1];

	do
	{
		printf("Enter word: ");
		scanf("%s", input);

		if (strlen(input) == 4)
			break;

		// check for smallest word
		if (strcmp(input, smallest_word) < 0 || strlen(smallest_word) == 0)
			strcpy(smallest_word, input);

		// check for largest word
		if (strcmp(input, largest_word) > 0)
			strcpy(largest_word, input);
	}
	while (1);

	printf("\nSmallest word: %s\n", smallest_word);
	printf("Largest word: %s\n", largest_word);

	return 0;
}
