#include "monty.h"


/**
 * monty_free - check if a string represents a number e
 *
 * @line: pointer to the string
 * @file_descriptor: pointer to the string
 * @stack_st: pointer to the string
 *
 * Return: void
 */

void monty_free(char *line, FILE *file_descriptor, stack_t *stack_st)
{
	stack_t *temp;

	free(line);
	fclose(file_descriptor);

	while (stack_st != NULL)
	{
		temp = stack_st;
		stack_st = stack_st->next;
		free(temp);
	}
}
