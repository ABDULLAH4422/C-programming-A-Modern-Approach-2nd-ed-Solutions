/*
 * stack.c
 *
 *  Created on: May 9, 2020
 *      Author: Mahmoud Hamdy
 */

// Stack type (Linked-list representation)

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define PUBLIC /* empty */
#define PRIVATE static

PRIVATE void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

#ifdef Q4_B_SOL1

PUBLIC void make_empty(Stack *s)
{
	while (!is_empty(s))
		pop(s);
}

PUBLIC bool is_empty(const Stack *s)
{
	return s->top == NULL;
}

PUBLIC bool is_full(const Stack *s)
{
	return false;
}

PUBLIC void push(Stack *s, int i)
{
	struct node *new_node = malloc(sizeof(struct node));

	if (new_node == NULL)
		terminate("Error in push: stack is full.");

	new_node->data = i;
	new_node->next = s->top;
	s->top = new_node;
}

PUBLIC int pop(Stack *s)
{
	if (is_empty(s))
		terminate("Error in pop: stack is empty.");

	struct node *old_top = s->top;
	int i = s->top->data;
	s->top = s->top->next;
	free(old_top);

	return i;
}

#elif Q4_B_SOL2

PUBLIC void make_empty(Stack *s)
{
	while (!is_empty(s))
		pop(s);
}

PUBLIC bool is_empty(const Stack *s)
{
	return *s == NULL;
}

PUBLIC bool is_full(const Stack *s)
{
	return false;
}

PUBLIC void push(Stack *s, int i)
{
	struct node* new_node = malloc(sizeof(struct node));

	if (new_node == NULL)
		terminate("Error in push: stack is full.");

	new_node->data = i;
	new_node->next = *s;
	*s = new_node;
}

PUBLIC int pop(Stack *s)
{
	if (is_empty(s))
		terminate("Error in pop: stack is empty.");

	struct node *old_top = *s;
	int i = (*s)->data;
	*s = (*s)->next;
	free(old_top);

	return i;
}

#endif /* Q4_B_SOL */
