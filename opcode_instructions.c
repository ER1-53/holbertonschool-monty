#include "monty.h"

/**
 * push - pushes an element to the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void push(stack_t **doubly, unsigned int cline)
{
	int n, j;

	if (!varglo.arg)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "usage: push integer\n");
		free_varglo();
		exit(EXIT_FAILURE);
	}

	for (j = 0; varglo.arg[j] != '\0'; j++)
	{
		if (!isdigit(varglo.arg[j]) && varglo.arg[j] != '-')
		{
			dprintf(2, "L%u: ", cline);
			dprintf(2, "usage: push integer\n");
			free_varglo();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(varglo.arg);

	if (varglo.lifo == 1)
		add_dnodeint(doubly, n);
	else
		add_dnodeint_end(doubly, n);
}

/**
 * pall - prints all values on the stack
 *
 * @doubly: head of the linked list
 * @cline: line numbers
 * Return: no return
 */
void pall(stack_t **doubly, unsigned int cline)
{
	stack_t *last;
	(void)cline;

	last = *doubly;

	while (last)
	{
		printf("%d\n", last->n);
		last = last->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void pint(stack_t **doubly, unsigned int cline)
{
	(void)cline;

	if (*doubly == NULL)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "can't pint, stack empty\n");
		free_varglo();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*doubly)->n);
}

/**
 * pop - removes the top element of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void pop(stack_t **doubly, unsigned int cline)
{
	stack_t *last;

	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", cline);
		free_varglo();
		exit(EXIT_FAILURE);
	}
	last = *doubly;
	*doubly = (*doubly)->next;
	free(last);
}

/**
 * swap - swaps the top two elements of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void swap(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *last = NULL;

	last = *doubly;

	for (; last != NULL; last = last->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", cline);
		free_varglo();
		exit(EXIT_FAILURE);
	}

	last = *doubly;
	*doubly = (*doubly)->next;
	last->next = (*doubly)->next;
	last->prev = *doubly;
	(*doubly)->next = last;
	(*doubly)->prev = NULL;
}

/**
 * add - adds the top two elements of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void add(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *last = NULL;

	last = *doubly;

	for (; last != NULL; last = last->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", cline);
		free_varglo();
		exit(EXIT_FAILURE);
	}

	last = (*doubly)->next;
	last->n += (*doubly)->n;
	pop(doubly, cline);
}
/**
 * nop - doesn't do anythinhg
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void nop(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;
}
