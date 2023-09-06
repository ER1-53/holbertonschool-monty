#include "monty.h"

void monty_free(char *line, FILE *file_descriptor, stack_t *stack_st)
{
	free(line);
	fclose(file_descriptor);
	while (stack_st != NULL)
	{
		stack_t *temp = stack_st;
		stack_st = stack_st->next;
		free(temp);
	}
	return;
}
