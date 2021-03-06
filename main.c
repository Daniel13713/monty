#include "monty.h"

int status = 0;
/**
 * _open - open a file
 *
 * @argv: file
 * Return: open file
 */
FILE *_open(char *argv)
{
	FILE *file;

	file = fopen(argv, "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
	return (file);
}

/**
 * main - main function
 *
 * @argc: number of arguments
 * @argv: arguments
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	char *lines = NULL, *name = NULL, *value = NULL;
	int i = 0;
	FILE *file;
	stack_t *stack = NULL;
	size_t len = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = _open(argv[1]);

	while (getline(&lines, &len, file) != -1)
	{
		name = strtok(lines, " \t\n");
		if (!name || *name == '#')
		{
			i++;
			continue;
		}
		value = strtok(NULL, " \t\n");
		executer(&stack, name, value, i + 1);
		if (status == EXIT_FAILURE)
		{
			free(lines);
			free_stack(stack);
			fclose(file);
			exit(status);
		}
		i++;
	}
	free(lines);
	fclose(file);
	free_stack(stack);
	return (0);
}
