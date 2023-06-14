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
        
        if (input < 'A' || input > 'Z')
            break;

        switch (input)
        {
            case 'Q': case 'Z':
                sum += 10; break;
            case 'J': case 'X':
                sum += 8; break;
            case 'K':
                sum += 5; break;
            case 'F': case 'H': case 'V': case 'W': case 'Y':
                sum += 4; break;
            case 'B': case 'C': case 'M': case 'P':
                sum += 3; break;
            case 'D': case 'G':
                sum += 2; break;
            default:
                sum++; break;
        }
    }

    printf("Scrabble value: %hd\n", sum);

    return 0;
}