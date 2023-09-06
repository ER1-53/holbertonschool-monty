#include "monty.h"

/**
 * isNumber - check if a string represents a number
 *
 * @tok: pointer to the string
 *
 * Return:
 * -1 if the string is empty
 * 0 if the string is not a number
 * 1 if the string is a number
 */
int isNumber(char *tok)
{
	char *ptr = tok;

	if (*tok == '\0')
		return -1;

	if (*ptr == '-')
		ptr++;

	while (*ptr != '\0')
	{
		if (*ptr < '0' || *ptr > '9')
			return 0; // It's not a number
		ptr++;
	}

	return 1; // It's a number
}

