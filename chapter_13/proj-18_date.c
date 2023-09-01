/*
 * Accepts a date from the user in the form 'mm/dd/yyyy' and then displays it
 * in the form 'month dd, yyyy', where 'month' is the name of the month
 */

#include <stdio.h>
#include <string.h>

#define MAX 50

void transform_date(char *date, int day, int month, int year);

int main(void)
{
	int day, month, year;

	printf("Enter a date (mm/dd/yyyy): ");
	scanf("%2d /%2d /%4d", &month, &day, &year);

	char date[MAX];
	transform_date(date, day, month, year);

	printf("You entered the date %s\n", date);

	return 0;
}

void transform_date(char *date, int day, int month, int year)
{
	char *months[] = {"January", "February", "March", "April", "May", "June", "July",
					"August", "September", "October", "November", "December"};

	char day_str[3], year_str[5];
	sprintf(day_str, "%d", day);
	sprintf(year_str, "%d", year);
	
	strcpy(date, months[month - 1]);
	strcat(date, " ");
	strcat(date, day_str);
	strcat(date, ", ");
	strcat(date, year_str);
}
