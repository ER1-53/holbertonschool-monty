#include "monty.h"

/**
 * instruction - Function to process Monty instructions from a file.
 */
void instruction(FILE *file_descriptor)
{
    char *line = NULL, *tokenize = NULL;
    size_t len = 0;
    ssize_t read;
    stack_t *stack_st = NULL;
    unsigned int count = 0;
    int sniffer = 0;

	 instruction_t instructions[] = {
        {"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop},
        {"swap", swap}, {"add", add}, {"nop", nop}, {NULL, NULL}
    };

    while ((read = getline(&line, &len, file_descriptor)) != -1)
    {
        tokenize = strtok(line, " \n");
        count++;
        sniffer = 0;

        if (tokenize != NULL)
        {
            for (int i = 0; instructions[i].opcode != NULL; i++)
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
}

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
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	} 
	 FILE *file_descriptor = fopen(argv[1], "r");
    if (file_descriptor == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    instruction(file_descriptor);

    return (0);
}
	