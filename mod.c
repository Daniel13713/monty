#include "monty.h"

/**
 * mod - calucluate the module od the first
 * tow values at the top of a double linked list
 *
 * @stack: double linked list
 * @line_number: Number to add (not used)
 * Return: Nothing
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *first = NULL, *second = NULL;
	size_t len = 0;
	int add_number = 0;

	len = stack_len(*stack);
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		status = EXIT_FAILURE;
		return;
	}
	first = *stack;
	second = first->next;
	if (first->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		status = EXIT_FAILURE;
		return;
	}
	add_number = second->n % first->n;
	second->n = add_number;
	pop(stack, line_number);
	second->prev = NULL;
	*stack = second;
}
