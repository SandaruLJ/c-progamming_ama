/* Prints a one-month reminder list */

#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50	/* maximum number of reminders */
#define MSG_LEN 60		/* max length of reminder message */

int read_line(char str[], int n);
void get_day(char day[], const char reminder[]);

int main(void)
{
	char reminders[MAX_REMIND][MSG_LEN+3];
	char day_str[3], msg_str[MSG_LEN+1];
	char time_str[7], reminder_day[3];
	int day, hour, min, i, j, num_remind = 0;

	for (;;)
	{
		if (num_remind == MAX_REMIND)
		{
			printf("-- No space left --\n");
			break;
		}

		printf("Enter day, time and reminder: ");
		
		scanf("%2d", &day);
		if (day == 0)
			break;
		sprintf(day_str, "%2d", day);

		// get time in 24-hour format
		scanf("%2d:%2d", &hour, &min);
		sprintf(time_str, " %.2d:%.2d", hour, min);

		read_line(msg_str, MSG_LEN);

		for (i = 0; i < num_remind; i++) 
			if (strcmp(day_str, reminders[i]) < 0)
				break;
		
		// get day from reminder
		if (num_remind > 0)
			get_day(reminder_day, reminders[i]);

		// sort by time, if the day is same
		if (strcmp(day_str, reminder_day) == 0)
		{
			for (; i < num_remind; i++)
			{
				char *time = reminders[i] + 2;
				if (*time == ' ')
					time++;
				
				if (strcmp(time_str + 1, time) < 0)
					break;

				// stay within the same day
				if (i + 1 < num_remind && strcmp(day_str, reminders[i + 1]) > 0)
					break;
			}
		}

		for (j = num_remind; j > i; j--)
			strcpy(reminders[j], reminders[j-1]);

		strcpy(reminders[i], day_str);
		strcat(reminders[i], time_str);
		strcat(reminders[i], msg_str);

		num_remind++;
	}

	printf("\nDay  Time Reminder\n");
	for (i = 0; i < num_remind; i++)
		printf(" %s\n", reminders[i]);

	return 0;
}

int read_line(char str[], int n)
{
	int ch, i = 0;

	while ((ch = getchar()) != '\n')
		if (i < n)
			str[i++] = ch;
	str[i] = '\0';
	return i; 
}

void get_day(char day[], const char reminder[])
{
	int i;
	for (i = 0; i < 2; i++)
		day[i] = reminder[i];
	day[i] = '\0';
}
