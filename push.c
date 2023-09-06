#include "monty.h"


/**
 * push - reverse the pile of stack
 *
 * @stack: pointer to the list
 * @line_number: pointer to the list
 *
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *tok = strtok(NULL, " \n");
	int value = 0;

	/**/

	if (tok == NULL || isNumber(tok) != 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	value = atoi(tok);
	new_node->n = value;/* get integer of tok 2nd arg*/
	new_node->prev = NULL;

	if (*stack == NULL)
	{
		new_node->next = NULL;
		*stack = new_node;
	}
	else
	{
	new_node->next = *stack;
	(*stack)->prev = new_node;
	}

	*stack = new_node;

}
