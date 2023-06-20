/*
 * Computes the value of a word in SCRABBLE
 * Face values - 1: AEILNORSTU, 2: DG, 3: BCMP, 4: FHVWY, 5: K, 8: JX, 10: QZ
 */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int sum = 0;
    char input;
    char values[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,
                       1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    printf("Enter a word: ");

    while (1)
    {
        input = toupper(getchar());
        
        if (input < 'A' || input > 'Z')
            break;

        sum += values[input - 'A'];
    }

    printf("Scrabble value: %hd\n", sum);

    return 0;
}