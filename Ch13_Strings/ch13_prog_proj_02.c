/*
 * ch13_prog_proj_02.c
 *
 *  Created on: Dec 17, 2019
 *      Author: SuperMoudy
 */

// Programming Project 2: One-month remainder list

#include <stdio.h>
#include <string.h>
#define MAX_REMIND 50 // maximum number of reminders
#define MSG_LEN 60    // max length of reminder message

int read_line(char str[], int n);

int main(void)
{
	char reminders[MAX_REMIND][MSG_LEN + 8];
	char msg_str[MSG_LEN + 1], time_str[12]; // mm/dd hh:mm\0
	int  month, day, i, j, num_remind = 0, hh, mm;

	for(;;)
	{
		if(num_remind == MAX_REMIND)
		{
			printf("-- No space left --\n");
			break;
		}

		printf("Enter day, 24-hour time, and reminder: ");
		fflush(stdout);
		fflush(stdin);
		scanf("%2d/%2d", &month, &day);
		if(day == 0 || month == 0)
		{
			break;
		}
		else if(day < 0 || day > 31 || month < 0 || month > 12)
		{
			printf("Invalid reminder (enter a valid day number)\n");
			while(getchar() != '\n');
			continue;
		}

		scanf("%2d:%2d", &hh, &mm);

		sprintf(time_str, "%02d/%02d %02d:%02d", month, day, hh, mm);
		read_line(msg_str, MSG_LEN);

		for(i = 0; i < num_remind; i++)
		{
			if(strcmp(time_str, reminders[i]) < 0)
				break;
		}

		for(j = num_remind; j > i; j--)
			strcpy(reminders[j], reminders[j - 1]);

		strcpy(reminders[i], time_str);
		strcat(reminders[i], msg_str);
		num_remind++;
	}

	printf("\nDay Reminder\n");
	for(i = 0; i < num_remind; i++)
		printf(" %s\n", reminders[i]);

	return 0;
}

int read_line(char str[], int n)
{
	int ch, i = 0;

	while((ch = getchar()) != '\n')
		if(i < n)
			str[i++] = ch;
	str[i] = '\0';

	return i;
}
