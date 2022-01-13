#include "monty.h"

/**
 * pchar - multiply the first tow values at the top of a double linked list
 *
 * @stack: double linked list
 * @line_number: Number to add (not used)
 * Return: Nothing
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *first = NULL;
	int value = 0;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		status = EXIT_FAILURE;
		return;
	}
	first = *stack;
	value = first->n;
	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		status = EXIT_FAILURE;
		return;
	}
	printf("%c\n", value);
}
