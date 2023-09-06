#include "monty.h"

/**
 * pall - reverse the pile of stack
 *
 * @stack: pointer to the list
 * @line_number: pointer to the list
 *
 * Return: temp.
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	return;

}
