#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct globals - global structure to use in the functions
 * @lifo: is stack or queue
 * @cont: current line
 * @arg: second parameter inside the current line
 * @head: doubly linked list
 * @filed: file descriptor
 * @buffer: input text
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct globals
{
	int lifo;
	unsigned int cont;
	char  *arg;
	stack_t *head;
	FILE *filed;
	char *buffer;
} global_t;

extern global_t varglo;

/* doubly linked list functions */
stack_t *add_dnodeint_end(stack_t **head, const int n);
stack_t *add_dnodeint(stack_t **head, const int n);
void free_stackt(stack_t *head);

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **doubly, unsigned int cline);
void pop(stack_t **doubly, unsigned int cline);
void swap(stack_t **doubly, unsigned int cline);
void add(stack_t **doubly, unsigned int cline);
void nop(stack_t **doubly, unsigned int cline);
void start_varglo(FILE *filed);
int sch(char *s, char c);
char *tokenize(char *s, char *d);
void *reallocmem(void *ptr, unsigned int old_size, unsigned int new_size);
void *callocmem(unsigned int nmemb, unsigned int size);
int strcmps(char *s1, char *s2);

void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number);
void free_varglo(void);

#endif /*_MONTY_H_*/