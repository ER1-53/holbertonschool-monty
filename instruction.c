#include "monty.h"

/**
 * instruction - Process instructions from a file using the Monty interpreter.
 *
 * @file_descriptor: File descriptor for the input file containing
 * Monty instructions.
 *
 * Return: 0 for success, 1 for errors.
 */

int instruction(FILE *file_descriptor)
{
	instruction_t instructions[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add}, {"nop", nop}, {NULL, NULL}};

	char *line = NULL, *tokenize = NULL;
	size_t len = 0;
	stack_t *stack_st = NULL;
	ssize_t read;
	unsigned int count = 0;
	int i = 0, sniffer = 0;

	while ((read = getline(&line, &len, file_descriptor)) != -1)
	{
		tokenize = strtok(line, " \n");
		count++;
		sniffer = 0;

		if (tokenize != NULL)
		{
			for (i = 0; instructions[i].opcode != NULL; i++)
			{
				if (strcmp(instructions[i].opcode, tokenize) == 0)
				{
					sniffer = 1;
					instructions[i].f(&stack_st, count);
					break;
				}
			}
			if (sniffer != 1)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", count, tokenize);
				monty_free(line, file_descriptor, stack_st);
				exit(EXIT_FAILURE);
			}
			monty_free(line, file_descriptor, stack_st);
		}
	}
	return (0);
}
