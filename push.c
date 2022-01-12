#include "monty.h"

/**
 * push - add a new node
 *
 * @stack: double linked list
 * @line_number: integer to add
 * Return: Nothing
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL, *temp = NULL;

	if (stack)
	{
		new = malloc(sizeof(stack_t));
		if (!new)
		{
			free(new);
			return;
		}
		temp = *stack;
		new->prev = NULL;
		new->next = temp;
		new->n = line_number;
		if (new->next)
		{
			temp->prev = new;
		}
		*stack = new;
	}
}
