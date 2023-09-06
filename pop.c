#include "monty.h"

/**
 * pop - reverse the pile of stack
 *
 * @stack: pointer to the list
 * @line_number: pointer to the list
 *
 * Return: temp.
 */

void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}

	stack_t *tmp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(tmp);
}
