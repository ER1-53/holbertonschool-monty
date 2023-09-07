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
	char *line = NULL;
	stack_t *stack_st = NULL;


	if (argc != 2) /* on verfie si il y a 2 arg ./prog fils.m */
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
	instruction(file_descriptor);

	monty_free(line, file_descriptor, stack_st);
	return (0);
}
