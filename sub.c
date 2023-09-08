#include "monty.h"

void sub(stack_t **stack, unsigned int line_number)
{
	int result = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->n - (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = result;

}
