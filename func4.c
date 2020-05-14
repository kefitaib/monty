#include "monty.h"


/**
 * chaine - divides the top two elements of the stack.
 * @st: first node of the list.
 * @i: lenght of the list.
 *
 * Return: void.
 */

void chaine(stack_t **st, unsigned int i)
{
stack_t *tmp = *st;
(void) i;

	if (*st)
	{
		for (; tmp ; tmp = tmp->next)
		{
			if (tmp->n <= 0 || tmp->n > 127)
				break;
			printf("%c", tmp->n);
		}

	}
	printf("\n");
}

void rotl(stack_t **st, unsigned int i)
{
stack_t *tmp = *st;

(void) i;

while (tmp->next)
tmp = tmp->next;

tmp->next = *st;
*st = (*st)->next;
(*st)->prev = NULL;
tmp->next->prev = tmp;
tmp->next->next = NULL;

}
