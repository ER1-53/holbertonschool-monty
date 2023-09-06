#include "monty.h"


/**
 * push - doubly linked list representation of a stack (or queue) e
 *
 * Description: open file and read
 *
 * @stack: it' the refer to the struct
 * @count: it's number of turn
 *
 * Return: new node
 */

void push(stack_t **stack, unsigned int count)
{
	stack_t *new_node;
	char *tok = strtok(NULL, " \n");

	/**/

	if (tok == NULL || isNumber(tok) != 1 )
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(tok);/* get integer of tok 2nd arg*/
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
	return;
}
