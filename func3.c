#include "monty.h"

/**
 * divy - divides the top two elements of the stack.
 * @st: first node of the list.
 * @i: lenght of the list.
 *
 * Return: void.
 */

void divy(stack_t **st, unsigned int i)
{
	stack_t *tmp = *st;

	if (*st && (*st)->next)
	{
		if ((*st)->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", i);
			free_all(*st);
		}
		else
		{
			*st = (*st)->next;
			(*st)->n /= tmp->n;
			(*st)->prev = NULL;
			free(tmp);
		}
	}

	else
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", i);
		free_all(*st);
	}
}

/**
 * mul - divides the top two elements of the stack.
 * @st: first node of the list.
 * @i: lenght of the list.
 *
 * Return: void.
 */

void mul(stack_t **st, unsigned int i)
{
	stack_t *tmp = *st;

	if (*st && (*st)->next)
	{
		*st = (*st)->next;
		(*st)->n *= tmp->n;
		(*st)->prev = NULL;
		free(tmp);
	}

	else
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", i);
		free_all(*st);
	}
}

/**
 * mod - divides the top two elements of the stack.
 * @st: first node of the list.
 * @i: lenght of the list.
 *
 * Return: void.
 */

void mod(stack_t **st, unsigned int i)
{
	stack_t *tmp = *st;

	if (*st && (*st)->next)
	{
		if ((*st)->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", i);
			free_all(*st);
		}
		else
		{
			*st = (*st)->next;
			(*st)->n %= tmp->n;
			(*st)->prev = NULL;
			free(tmp);
		}
	}

	else
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", i);
		free_all(*st);
	}
}

/**
 * pchar - divides the top two elements of the stack.
 * @st: first node of the list.
 * @i: lenght of the list.
 *
 * Return: void.
 */

void pchar(stack_t **st, unsigned int i)
{

	if (*st)
	{
		if ((*st)->n < 0 || (*st)->n > 127)
		{
			fprintf(stderr, "L%u: can't pchar, value out of range\n", i);
			free_all(*st);
		}
		else
		{
			printf("%c\n", (*st)->n);
		}
	}

	else
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", i);
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
