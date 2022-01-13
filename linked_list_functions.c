#include "monty.h"

/**
 * print_dlistint - print a double linked list
 *
 * @h: double linked list
 * Return: size of h
 */

size_t print_dlistint(const stack_t *h)
{
	size_t i = 0;

	if (h != NULL)
	{
		while (h != NULL)
		{
			printf("%d\n", h->n);
			i++;
			h = h->next;
		}
	}
	return (i);
}

/**
 * free_stack - free double linked list
 *
 * @head: double linked list
 * Return: nothing
 */

void free_stack(stack_t *head)
{
	stack_t *current = NULL, *next_node = NULL;

	current = head;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}

/**
 * stack_len - calculate a size of a double linked list
 *
 * @h: double linked list
 * Return: size of h
 */

size_t stack_len(const stack_t *h)
{
	size_t size = 0;

	while (h)
	{
		h = h->next;
		size++;
	}
	return (size);
}

/**
 * _isnumber - checks if a string is a number
 * @str: provided string
 *
 * Return: 1 if the string is a number, else, 0.
 */
int _isnumber(char *str)
{
	int i = 0;

	if (!str)
		return (0);
	if (str[i] == '-')
	{
		i++;
	}
	for (; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
	}
	return (1);
}
