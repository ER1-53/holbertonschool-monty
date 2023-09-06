#include "monty.h"

/**
 * print_dlistint - print a list e
 *
 * @h: pointer to the list
 *
 * Return: temp.
 */

void pall(stack_t **stack, unsigned int count)
{
	stack_t *current = *stack;

	(void)count;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}

}
