#include "monty.h"

/**
 * error_push - print message error and free heap.
 * @s: message to print.
 * @st: first node of the list.
 * @i: lenght of the list.
 *
 * Return: void.
 */

void error_push(char *s, stack_t **st, unsigned int i)
{
	if (i > 0)
		fprintf(stderr, "L%u: %s\n", i, s);
	else
		fprintf(stderr, "%s\n", s);
	free_all(*st);
}

/**
 * push - add a new node to the list.
 * @st: first node of the list.
 * @i: lenght of the list.
 *
 * Return: void.
 */

void push(stack_t **st, unsigned int i)
{
	stack_t *new = NULL, *tmp = *st;
	char *t = tokens[1];
	int j;

	if (!t)
		error_push("usage: push integer", st, i);
	for (j = 0; t[j]; j++)
	{
		if (t[0] == '-' && j == 0)
			continue;
		else if (t[j] < '0' || t[j] > '9')
			error_push("usage: push integer", st, i);
	}
	new = malloc(sizeof(stack_t));
	if (!new)
		error_push("USAGE: malloc failed", st, i);
	new->n = atoi(tokens[1]);
	new->next = NULL;
	new->prev = NULL;
	if (*st)
	{
		if (SQ == 0)
		{
			new->next = *st;
			(*st)->prev = new;
			*st = new;
		}
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
			new->prev = tmp;
		}
	}
	else
		*st = new;
}

/**
 * pall - print a list.
 * @st: first node of the list.
 * @i: lenght of the list.
 *
 * Return: void.
 */

void pall(stack_t **st, unsigned int i)
{
	stack_t *tmp = *st;
	(void)i;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}

}


/**
 * pint - print the top of the list.
 * @st: first node of the list.
 * @i: lenght of the list.
 *
 * Return: void.
 */

void pint(stack_t **st, unsigned int i)
{
	(void)i;

	if (*st)
		printf("%d\n", (*st)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", i);
		free_all(*st);
	}
}


/**
 * pop - remove the top of the list.
 * @st: first node of the list.
 * @i: lenght of the list.
 *
 * Return: void.
 */

void pop(stack_t **st, unsigned int i)
{
	stack_t *tmp = *st;
	(void)i;

	if (tmp)
	{
		if (!tmp->next)
			*st = NULL;
		else
		{
			*st = (*st)->next;
			(*st)->prev = NULL;
		}
		free(tmp);
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", i);
		free_all(*st);
	}

}
