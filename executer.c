#include "monty.h"

/**
 * executer - function that choose the function to execute it
 *
 * @stack: linked list
 * @name: name of the function in the file
 * @value: number in he file
 * @lnumber: number of the line in the file
 *
 * Return: nothing
 */

void executer(stack_t **stack, char *name, char *value, int lnumber)
{
	int counter = 0;

	for (; instructions[counter].opcode; counter++)
	{
		if (strcmp(name, instructions[counter].opcode) == 0)
		{
			if (strcmp(name, instructions[0].opcode) != 0)
			{
				instructions[counter].f(stack, lnumber);
				return;
			}
			if (strcmp(name, instructions[0].opcode) == 0 && !_isnumber(value))
			{
				status = EXIT_FAILURE;
				fprintf(stderr, "L%d: usage: push integer\n", lnumber);
				return;
			}
			if (strcmp(name, instructions[0].opcode) == 0 && !value)
			{
				status = EXIT_FAILURE;
				fprintf(stderr, "L%d: usage: push integer\n", lnumber);
				return;
			}
			instructions[counter].f(stack, atoi(value));
			return;
		}
	}
	status = EXIT_FAILURE;
	fprintf(stderr, "L%d: unknown instruction %s\n", lnumber, name);
}
