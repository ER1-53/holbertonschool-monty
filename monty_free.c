#include "monty.h"


/**
 * monty_free - Frees memory and resources used in the Monty program.
 *
 * @line: Pointer to a string (not used here).
 * @file_descriptor: Pointer to a file stream.
 * @stack_st: Pointer to the stack.
 *
 * This function is responsible for freeing dynamically allocated memory
 * and resources used by the Monty program. It takes care of freeing the
 * line buffer, closing the file descriptor, and deallocating the stack.
 *
 * Return: void
 */

void monty_free(char *line, FILE *file_descriptor, stack_t *stack_st)
{
	stack_t *temp;
	if (line)
    	free(line);
	if (file_descriptor)
		fclose(file_descriptor);

	while (stack_st != NULL)
	{
		temp = stack_st;
		stack_st = stack_st->next;
		free(temp);
	}
}
