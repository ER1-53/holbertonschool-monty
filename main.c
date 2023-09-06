#include "monty.h"

global_t varglo;

/**
 * free_varglo - frees the global variables
 *
 * Return: no return
 */
void free_varglo(void)
{
	free_stackt(varglo.head);
	free(varglo.buffer);
	fclose(varglo.filed);
}

/**
 * start_varglo - initializes the global variables
 *
 * @filed: file descriptor
 * Return: no return
 */
void start_varglo(FILE *filed)
{
	varglo.lifo = 1;
	varglo.cont = 1;
	varglo.arg = NULL;
	varglo.head = NULL;
	varglo.filed = filed;
	varglo.buffer = NULL;
}

/**
 * check_input - checks if the file exists and if the file can
 * be opened
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *filed;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filed = fopen(argv[1], "r");

	if (filed == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (filed);
}

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
    void (*f)(stack_t **stack, unsigned int line_number);
	FILE *filed;
	size_t size = 256;
	ssize_t nlines = 0;
    char *lines[2] = {NULL, NULL};

	filed = check_input(argc, argv);
	start_varglo(filed);
	nlines = getline(&varglo.buffer, &size, filed);
	while (nlines != -1)
	{
		lines[0] = tokenize(varglo.buffer, " \t\n");
        if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", varglo.cont);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_varglo();
				exit(EXIT_FAILURE);
			}
		nlines = getline(&varglo.buffer, &size, filed);
		varglo.cont++;
        }
	}

	free_varglo();

	return (0);
}