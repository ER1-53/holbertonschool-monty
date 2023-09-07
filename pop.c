#include "monty.h"

/**
 * pop - Removes the top element of the stack.
 *
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty bytecode file.
 */

void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *tmp = *stack; /* Stocke le pointeur vers le premier élément */
	*stack = (*stack)->next; /* Met à jour la tête de la pile */
	/* Met à jour le pointeur prev du nouveau premier élément */
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(tmp); /* Libère la mémoire du premier élément supprimé */
}
