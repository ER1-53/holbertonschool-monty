#include "monty.h"

/**
 * sub - Subtract the top element of the stack from the second top element
 *
 * @stack: Pointer to the stack
 * @line_number: Line number in the Monty file
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int result = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = result;

}
