#include "monty.h"

/**
 * main - Entry point for the Monty interpreter.
 *
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Return: 0 for success.
 */

int main(int argc, char *argv[])
{
	FILE *file_descriptor;
	char *line = NULL, *tokenize = NULL;
	size_t len = 0;
	stack_t *stack_st = NULL;
	ssize_t read;
	unsigned int count = 0;
	int i = 0, sniffer = 0;

	instruction_t instructions[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add}, {"nop", nop}, {NULL, NULL}};

	if (argc != 2)/* on verfie si il y a 2 arg ./prog fils.m */
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	} /* on ouvre le fichier en index argv[1] et le lit */
	file_descriptor = fopen(argv[1], "r");
	if (file_descriptor == NULL)
	{/* si il ne s'ouvre pas ou ne contient rien */
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file_descriptor)) != -1)
	{/* line = le contenue; file_des = le stream du fichier; len = nbCaractere*/
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
		}
	}
	monty_free(line, file_descriptor, stack_st);
	return (0);
}
