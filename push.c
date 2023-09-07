#include "monty.h"


/**
 * push - Pushes an integer onto the stack.
 *
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty bytecode file.
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *tok = strtok(NULL, " \n");
	int value = 0;
	/* Vérifie si l'argument tok est présent et est un nombre */
	if (tok == NULL || isNumber(tok) != 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
/* Alloue de la mémoire pour un nouveau nœud de pile */
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	value = atoi(tok); /* Convertit la chaîne tok en entier */
	new_node->n = value; /* Stocke la valeur dans le nœud de pile */

	/* Initialise les pointeurs prev et next du nouveau nœud */
	new_node->prev = NULL;

	if (*stack == NULL)
	{
		new_node->next = NULL;
		*stack = new_node; /* Met à jour la tête de la pile */
	}
	else
	{
	new_node->next = *stack;
	(*stack)->prev = new_node;
	*stack = new_node; /* Met à jour la tête de la pile */
	}
}
