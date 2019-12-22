/*
 * ch13_prog_proj_11.c
 *
 *  Created on: Dec 22, 2019
 *      Author: SuperMoudy
 */

// Programming Project 11: Average word length for a sentence

#include <stdio.h>
#define SENT_LEN 100

double compute_average_word_length(char *sentence);
void read_sentence(char *sentence, int sent_len);

int main(void)
{
	char sentence[SENT_LEN];
	float avg;

	printf("Enter a sentence: ");
	fflush(stdout);
	fflush(stdin);
	read_sentence(sentence, SENT_LEN);

	avg = compute_average_word_length(sentence);

	printf("Average word length: %.1f\n", avg);

	return 0;
}

double compute_average_word_length(char *sentence)
{
	int total_len = 0, word_len = 0, word_count = 0;
	float avg;

	while(*sentence)
	{
		if(*sentence++ == ' ')
		{
			total_len += word_len;
			word_count++;
			word_len = 0;
		}
		else
		{
			word_len++;
		}
	}

	word_count++;
	total_len += word_len;

	avg = ((float) total_len) / word_count;

	return avg;
}


void read_sentence(char *sentence, int sent_len)
{
	int count = 0;
	while((*sentence++ = getchar()) != '\n' && count++ < sent_len);
	*--sentence = '\0';

	if(count > sent_len)
		while(getchar() != '\n');
}
