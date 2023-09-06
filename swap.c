#include "monty.h"

/**
 * swap - reverse the pile of stack
 *
 * @stack: pointer to the list
 * @line_number: pointer to the list
 *
 * Return: temp.
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
