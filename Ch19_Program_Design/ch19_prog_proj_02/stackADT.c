/*
 * stackADT.c
 *
 *  Created on: May 11, 2020
 *      Author: Mahmoud Hamdy
 */

// Stack ADT (Fixed-length array representation)

#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

#define STACK_SIZE 100

struct stack_type
{
	Item contents[STACK_SIZE];
	int top;
};

static void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Stack create(void)
{
	Stack s = malloc(sizeof(struct stack_type));

	if (s == NULL)
		terminate("Error in create: stack could not be created.");

	s->top = 0;

	return s;
}

void destroy(Stack s)
{
	free(s);
}

void make_empty(Stack s)
{
	s->top = 0;
}

bool is_empty(Stack s)
{
	return s->top == 0;
}

bool is_full(Stack s)
{
	return s->top == STACK_SIZE;
}

void push(Stack s, Item i)
{
	if (is_full(s))
		terminate("Expression is too complex");

	s->contents[s->top++] = i;
}

Item pop(Stack s)
{
	if (is_empty(s))
		terminate("Not enough operands in expression");

	return s->contents[--s->top];
}
