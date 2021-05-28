#include "monty.h"

int x;


/**
 * push - add a new node to the list.
 * @st: first node of the list.
 * @i: lenght of the list.
 *
 * Return: void.
 */

void push(stack_t **st, unsigned int i)
{
	stack_t *new = NULL, *tmp = NULL;
	char *t = tokens[1];
	int j;

	if (!t)
	{
		fprintf(stderr, "L%u: usage: push integer\n", i);
		free_all(*st);
	}

	for (j = 0; t[j]; j++)
	{
		if (t[0] == '-' && j == 0)
			continue;

		else if (t[j] < '0' || t[j] > '9')
		{
			fprintf(stderr, "L%u: usage: push integer\n", i);
			free_all(*st);
		}
	}

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "USAGE: malloc failed\n");
		free_all(*st);

	}

	new->n = atoi(tokens[1]);

if (x == 0)
{
	new->next = *st;
	new->prev = NULL;

	if (*st)
		(*st)->prev = new;

	*st = new;
}
if (x == 1)
{
	tmp = *st;
		while (tmp->next)
		tmp = tmp->next;

	tmp->next = new;	
	new->prev = tmp;
	new->next = NULL;
	
}

/*printf("aaa%d\n", x);*/
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

/**
 * swap - swaps the top two elements of the stack.
 * @st: first node of the list.
 * @i: lenght of the list.
 *
 * Return: void.
 */

void swap(stack_t **st, unsigned int i)
{
	int x;

	(void)i;
	if (*st && (*st)->next)
	{
		x = (*st)->n;
		(*st)->n = (*st)->next->n;
		(*st)->next->n = x;
	}

	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", i);
		free_all(*st);
	}
}
