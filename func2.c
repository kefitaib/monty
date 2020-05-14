#include "monty.h"

/**
 * add - dds the top two elements of the stack.
 * @st: first node of the list.
 * @i: lenght of the list.
 *
 * Return: void.
 */

void add(stack_t **st, unsigned int i)
{
	stack_t *tmp = *st;

	if (*st && (*st)->next)
	{
		*st = (*st)->next;
		(*st)->n += tmp->n;
		(*st)->prev = NULL;
		free(tmp);
	}

	else
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", i);
		free_all(*st);
	}
}


/**
 * free_list - function that free a list
 * @head : first element of a double linked list.
 * Return: Void.
 *
 */

void free_list(stack_t *head)
{
	stack_t *l = head;

	while (l)
	{
		head = head->next;
		free(l);
		l = head;
	}
}

/**
 * free_all - free every allocated memory of the heap.
 * @st : first element of a double linked list.
 * Return: Void.
 *
 */

void free_all(stack_t *st)
{
	fclose(p);

	if (st)
	{
		free_list(st);
		st = NULL;
	}
	if (tokens)
	{
		free(tokens);
		tokens = NULL;
	}
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	exit(EXIT_FAILURE);
}


/**
 * nop - do nothing.
 * @st : first element of a double linked list.
 * @i: lenght of the list.
 * Return: Void.
 *
 */

void nop(stack_t **st, unsigned int i)
{
	(void)i;
	(void)st;
}


/**
 * sub - dds the top two elements of the stack.
 * @st: first node of the list.
 * @i: lenght of the list.
 *
 * Return: void.
 */

void sub(stack_t **st, unsigned int i)
{
	stack_t *tmp = *st;

	if (*st && (*st)->next)
	{
		*st = (*st)->next;
		(*st)->n -= tmp->n;
		(*st)->prev = NULL;
		free(tmp);
	}

	else
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", i);
		free_all(*st);
	}
}
