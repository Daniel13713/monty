#include "monty.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * pstr - multiply the first tow values at the top of a double linked list
 *
 * @stack: double linked list
 * @line_number: Number to add (not used)
 * Return: Nothing
 */

void pstr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *first = NULL;
	int value = 0;

	if (!stack || !(*stack))
	{
		printf("\n");
		return;
	}
	first = *stack;
	while (first != NULL)
	{
		value = first->n;
		if (value <= 0 || value > 127)
		{
			break;
		}
		printf("%c", value);
		first = first->next;
	}
	printf("\n");
}
