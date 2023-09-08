#include "monty.h"

/**
 * _div - Divide the second top element of the stack by the top element
 *
 * @stack: Pointer to the stack
 * @line_number: Line number in the Monty file
 */

void _div(stack_t **stack, unsigned int line_number)
{
	int result = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = result;




}
