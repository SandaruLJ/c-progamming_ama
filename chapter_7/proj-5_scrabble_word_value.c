/*
 * Computes the value of a word in SCRABBLE
 * Face values - 1: AEILNORSTU, 2: DG, 3: BCMP, 4: FHVWY, 5: K, 8: JX, 10: QZ
 */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char input;
    short sum = 0;

    printf("Enter a word: ");

    while (1) 
    {
        input = toupper(getchar());
        
        if (input < 65 || input > 90)
            break;

        if (input == 81 || input == 90)
            sum += 10;
        else if (input == 74 || input == 88)
            sum += 8;
        else if (input == 75)
            sum += 5;
        else if (input == 70 || input == 72 || (input >= 86 && input <= 89))
            sum += 4;
        else if (input == 66 || input == 67 || input == 77 || input == 80)
            sum += 3;
        else if (input == 68 || input == 71)
            sum += 2;
        else
            sum += 1;
    }

    printf("Scrabble value: %hd\n", sum);

    return 0;
}