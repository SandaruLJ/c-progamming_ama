/*
 * Computes the value of a word in SCRABBLE
 * Face values - 1: AEILNORSTU, 2: DG, 3: BCMP, 4: FHVWY, 5: K, 8: JX, 10: QZ
 */

#include <stdio.h>
#include <ctype.h>

#define MAX 50

int compute_scrabble_value(const char *word);

int main(void)
{
    char input[MAX];

    printf("Enter a word: ");
    scanf("%s", input);

    int value = compute_scrabble_value(input);
    printf("Scrabble value: %hd\n", value);

    return 0;
}

int compute_scrabble_value(const char *word)
{
    int sum = 0;

    while (*word)
    {
        char ch = toupper(*word);
        
        if (ch < 'A' || ch > 'Z')
            break;

        switch (ch)
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

        word++;
    }

    return sum;
}
