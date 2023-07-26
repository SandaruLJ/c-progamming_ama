/*
 * Classifies a poker hand entered by the user
 * [the analyze_hand() can be done better, refer to knking.com's answer]
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define NUM_CARDS 5
#define NUM_CARD_ATTRS 2
#define RANK_IDX 0
#define SUIT_IDX 1

// external variables
int hand[NUM_CARDS][NUM_CARD_ATTRS];
bool straight, flush, four, three;
int pairs;  /* can be 0, 1, or 2 */

// prototypes
void read_cards(void);
void analyze_hand(void);
void print_result(void);

/************************************************************
 * main(): Calls read_cards, analyze_hand, and print_result *
 * 		   repeatedly										*
 ************************************************************/
int main(void)
{
	for (;;) {
		read_cards();
		analyze_hand();
		print_result();
	}
}

/************************************************************
 * read_cards(): Reads the cards into external variables;   *
 * 				 checks for bad cards and duplicate cards.  *
 ************************************************************/
void read_cards(void)
{
	// bool card_exists[NUM_RANKS][NUM_SUITS];
	char ch, rank_ch, suit_ch;
	int rank = -1, suit = -1;
	bool bad_card, card_exists;
	int cards_read = 0;

	while (cards_read < NUM_CARDS)
	{
		bad_card = false;
		card_exists = false;

		printf("Enter a card: ");

		rank_ch = tolower(getchar());
		switch (rank_ch)
		{
			case '0': exit(EXIT_SUCCESS);
			case '2': rank = 0; break;
			case '3': rank = 1; break;
			case '4': rank = 2; break;
			case '5': rank = 3; break;
			case '6': rank = 4; break;
			case '7': rank = 5; break;
			case '8': rank = 6; break;
			case '9': rank = 7; break;
			case 't': rank = 8; break;
			case 'j': rank = 9; break;
			case 'q': rank = 10; break;
			case 'k': rank = 11; break;
			case 'a': rank = 12; break;
			default : bad_card = true;
		}

		suit_ch = tolower(getchar());
		switch (suit_ch)
		{
			case 'c': suit = 0; break;
			case 'd': suit = 1; break;
			case 'h': suit = 2; break;
			case 's': suit = 3; break;
			default : bad_card = true;
		}

		while ((ch = getchar()) != '\n')
			if (ch != ' ') bad_card = true;

		// check if the same card was read previously
		for (int i = 0; i < cards_read; i++)
		{
			if (hand[i][RANK_IDX] == rank && hand[i][SUIT_IDX] == suit)
			{
				card_exists = true;
				break;
			}
		}

		if (bad_card)
			printf("Bad card; ignored.\n");
		else if (card_exists)
			printf("Duplicate card; ignored.\n");
		else
		{
			hand[cards_read][RANK_IDX] = rank;
			hand[cards_read][SUIT_IDX] = suit;
			cards_read++;
		}
	}
}

/**********************************************************
 * analyze_hand: Determines whether the hand contains a   *
 *               straight, a flush, four-of-a-kind,       *
 * 				 and/or three-of-a-kind; determines the   *
 *				 number of pairs; stores the results into *
 * 				 external variables.					  *
 **********************************************************/
void analyze_hand(void)
{
	int rank_sum, max_same_ranks, num_same_ranks;
	bool same_rank;

	straight = false;
	flush = false;
	four = false;
	three = false;
	pairs = 0;

	/* check for flush */
	for (int card = 0, suit = -1; card < NUM_CARDS; card++)
	{
		flush = true;

		// set the first suit encountered
		if (suit == -1)
		{
			suit = hand[card][SUIT_IDX];
			continue;
		}
		
		// if any different suit encountered, the hand is not flush
		if (hand[card][SUIT_IDX] != suit)
		{
			flush = false;
			break;
		}
	}

	/* check for straight */
	rank_sum = 0;
	same_rank = false;
	for (int card = 0; card < NUM_CARDS; card++)
	{
		// check if same rank was read previously
		for (int prev_card = 0; prev_card < card; prev_card++)
		{
			if (hand[card][RANK_IDX] == hand[prev_card][RANK_IDX])
			{
				same_rank = true;
				break;
			}
		}

		rank_sum += hand[card][RANK_IDX];
	}

	// if, and only if the sum of the ranks (unique) is a multiple of 5,
	// they are consecutive, resulting in a straight hand.
	if (rank_sum % 5 == 0 && !same_rank)
	{
		straight = true;
		return;
	}

	/* check for 4-of-a-kind, 3-of-a-kind, and pairs */
	num_same_ranks = 0;
	max_same_ranks = 0;
	same_rank = true;
	for (int card = 0, rank = -1; card < NUM_CARDS; card++)
	{
		// set the rank encountered first
		if (rank == -1)
		{
			rank = hand[card][RANK_IDX];
			num_same_ranks = 1;
			continue;
		}

		// check for cards with the same rank
		for (int prev_card = 0; prev_card < card; prev_card++)
		{
			if (hand[card][RANK_IDX] == hand[prev_card][RANK_IDX])
				num_same_ranks++;
			else
				same_rank = false;
		}
		
		if (!same_rank)
		{
			if (num_same_ranks > max_same_ranks)
				max_same_ranks = num_same_ranks;

			// count pairs
			if (num_same_ranks == 2)
				pairs++;

			// set new rank to look for matches from this point on
			rank = hand[card][RANK_IDX];
			num_same_ranks = 1;
		}
	}

	if (max_same_ranks == 4) four = true;
	else if (max_same_ranks == 3) three = true;
}

/**********************************************************
 * print_result: Notifies the user of the result, using	  *
 *				 the external variables set by 			  *
 * 				 analyze_hand.							  *
 **********************************************************/
void print_result(void)
{
	if (straight & flush) printf("Straight flush");
	else if (four)		  printf("Four of a kind");
	else if (three &&
			 pairs == 1)  printf("Full house");
	else if (flush)		  printf("Flush");
	else if (straight)	  printf("Straight");
	else if (three)		  printf("Three of a kind");
	else if (pairs == 2)  printf("Two pairs");
	else if (pairs == 1)  printf("Pair");
	else				  printf("High card");

	printf("\n\n");
}
