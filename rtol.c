#include "monty.h"

/**
 * rotl - rotates the stack to the top.
 *
 * @stack: double linked list
 * @line_number: Number to add (not used)
 * Return: Nothing
 */

void rotl(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *first = NULL;
	int value = 0;

	if (!stack || !(*stack))
	{
		return;
	}
	first = *stack;
	value = first->n;
	pop(stack, line_number);
	add_dnodeint_end(stack, value);
}
