#include "monty.h"

/**
 * pall - Prints all the elements in the stack.
 *
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty bytecode file (not used here).
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n); /* Affiche la valeur de l'élément actuel */
		current = current->next; /* Déplace le pointeur vers l'élément suivant */
	}
	return;

}
