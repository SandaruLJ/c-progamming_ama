/*
 * Simulates a game of craps, which is played with two dice.
 *
 * On the first roll, the player wins if the sum of the dice is 7 or 11.
 * The player loses if the sum is 2, 3, or 12. Any other roll is called
 * the "point". On each subsequent roll, the player wins if they roll the
 * point again. The player loses by rolling 7. Any other roll is ignored
 * and the game continues.
*/

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int roll_dice(void);
bool play_game(void);

int main(void)
{
    int wins = 0, losses = 0;
    bool play_again = true;
    char input;

    do
    {
        if (play_game())
        {
            printf("You win!\n");
            wins++;
        }
        else
        {
            printf("You lose!\n");
            losses++;
        }

        printf("\nPlay again: ");
        scanf(" %c", &input);
        
        if (toupper(input) != 'Y')
            play_again = false;
        
        printf("\n");
    }
    while (play_again);

    printf("Wins: %d  Losses: %d\n", wins, losses);

    return 0;
}

bool play_game(void)
{
    int point, roll;

    point = roll_dice();
    
    printf("You rolled: %d\n", point);

    if (point == 7 || point == 11)
        return true;
    else if (point == 2 || point == 3 || point == 12)
        return false;

    printf("Your point is %d\n", point);

    do
    {
        roll = roll_dice();
        
        printf("You rolled: %d\n", roll);

        if (roll == 7)
            return false;
    }
    while (roll != point);

    return true;
}

int roll_dice()
{
    srand((unsigned) time(NULL));
    sleep(1);  // just so that the output of 'time' is different on each call

    return (rand() % 12) + 1;
}
