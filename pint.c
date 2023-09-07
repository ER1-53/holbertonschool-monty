#include "monty.h"

/**
 * pint - Prints the value at the top of the stack.
 *
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty bytecode file.
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
/* afficher la valeur du premier élément de la pile */
	printf("%d\n", (*stack)->n);
}
