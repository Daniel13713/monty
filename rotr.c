#include "monty.h"

/**
 * rotr - rotates the stack to the top.
 *
 * @stack: double linked list
 * @line_number: Number to add (not used)
 * Return: Nothing
 */

void rotr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *first = NULL, *last = NULL;
	int value = 0;

	if (!stack || !(*stack))
	{
		return;
	}
	first = *stack;
	while (first->next)
	{
		first = first->next;
	}
	value = first->n;
	last = first->prev;
	last->next = NULL;
	last = last->prev;
	free(first);
	*stack = last;
	push(stack, value);
}
