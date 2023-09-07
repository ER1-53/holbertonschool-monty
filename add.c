#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 *
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty bytecode file.
 */

void add(stack_t **stack, unsigned int line_number)
{
	int result = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->n + (*stack)->next->n;
	pop(stack, line_number); /* Retire le deuxième élément de la pile */
	(*stack)->n = result; /* Stocke le résultat dans le premier élément */
}
