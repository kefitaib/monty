#ifndef _H_MONTY_H_
#define _H_MONTY_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

extern char **tokens, *buffer;
extern FILE *p;


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
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


void (*get_f(char *buffer))(stack_t **, unsigned int);
int check_monty(FILE *p);
char **create_tokens(char *, int, stack_t *);
void push(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);
void add(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void free_list(stack_t *);
void free_all(stack_t *);
void sub(stack_t **st, unsigned int i);
void divy(stack_t **st, unsigned int i);
void mul(stack_t **st, unsigned int i);
void mod(stack_t **st, unsigned int i);
void pchar(stack_t **st, unsigned int i);

#endif
