#include "monty.h"

/**
 * mul - multiply the first tow values at the top of a double linked list
 *
 * @stack: double linked list
 * @line_number: Number to add (not used)
 * Return: Nothing
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *first = NULL, *second = NULL;
	size_t len = 0;
	int add_number = 0;

	len = stack_len(*stack);
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		status = EXIT_FAILURE;
		return;
	}
	first = *stack;
	second = first->next;
	add_number = second->n * first->n;
	second->n = add_number;
	pop(stack, line_number);
	second->prev = NULL;
	*stack = second;
}
