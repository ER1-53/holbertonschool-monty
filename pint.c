#include "monty.h"

/**
 * pint - reverse the pile of stack
 *
 * @stack: pointer to the list
 * @line_number: pointer to the list
 *
 * Return: temp.
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}

	printf("%d\n", (*stack)->n);
}
