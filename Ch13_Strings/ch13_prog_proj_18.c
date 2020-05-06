/*
 * ch13_prog_proj_18.c
 *
 *  Created on: Dec 22, 2019
 *      Author: SuperMoudy
 */

// Programming Project 18: Date Format

#include <stdio.h>
#include <string.h>

int main(void)
{
	int dd, mm, yyyy;
	char *months[] =
	{
			"January", "February", "March", "April", "May", "June",
			"July", "August", "September", "October", "November", "December"
	};

	printf("Enter a data (mm/dd/yyyy): ");
	scanf("%d / %d / %d", &mm, &dd, &yyyy);

	printf("You entered the data %s %d, %d", months[mm - 1], dd, yyyy);

	return 0;
}
