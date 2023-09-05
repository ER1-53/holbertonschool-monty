#include "monty.h"

/**
 *add_dnodeint - add a new node at the beginning of a dlistint_t
 *@head: current place to a list
 *@n: int to add to the list
 *Return: the address of the new element
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *news;

	news = malloc(sizeof(stack_t));

	if (!news)
	{
		dprintf(2, "Error: malloc failed\n");
		free_varglo();
		exit(EXIT_FAILURE);
    }
	news->n = n;	
	if (*head == NULL)
	{
		news->next = *head;
		news->prev = NULL;
		*head = news;
		return (*head);
	}
	(*head)->prev = news;
	news->next = (*head);
	news->prev = NULL;
	*head = news;
	return (*head);
}	

/**
 *add_dnodeint_end - add node at the end
 *@head: a pointer to the adrress of the head
 *{@n: the integer for the new node
 *Return:the address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *news;
	stack_t *last = NULL;

	if (head == NULL)
		return (NULL);
	news = malloc(sizeof(stack_t));
	if (!news)
	{
		dprintf(2, "Error: malloc failed\n");
		free_varglo();
		exit(EXIT_FAILURE);
	}
	news->n = n;
	
	if (*head == NULL)
	{
		news->next = *head;
		news->prev = NULL;
		*head = news;
		return (*head);
	}
	last = *head;
	while (last->next)
		last = last->next;
	news->next = last->next;
	news->prev = last;
	last->next = news;
	return (last->next);
}


/**
 * free_stack_t - frees a linked list
 * @head: stack_t list to be freed
 */
void free_stackt(stack_t *head)
{
	stack_t *news;

	while ((news = head) != NULL)
	{
		head = head->next;
		free(news);
	}
}
