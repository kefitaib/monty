#include "monty.h"

char **tokens, *buffer = NULL;
int SQ = 0;

/**
 * word - return the number of words in a string.
 * @c: string.
 * @x: delimiter.
 *
 * Return: void.
 */

int word(char *c, char x)
{
	int w = 0, i = 0;

	while (c[i] != '\0')
	{
		if (c[i] != x)
		{
			w++;
			while (c[i] != x && c[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (w);
}


/**
 * get_f - selects the correct function to perform a tasck.
 * @buffer: function name.
 *
 * Return: .
 */

void (*get_f(char *buffer))(stack_t **, unsigned int)
{
	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divy},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", chaine},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	int i = 0;

	for ( ; op[i].opcode ; i++)
	{
		if (strcmp(op[i].opcode, buffer) == 0)
			return (op[i].f);
	}

	return (NULL);
}


/**
 * create_tokens - split a string to words.
 * @buffer: string.
 * @words: number of words in a string.
 * @st: first node of the list.
 * Return: array of words.
 */

char **create_tokens(char *buffer, int words, stack_t *st)
{
	char *str;
	int i = 0;

	tokens = malloc(sizeof(char *) * (words + 1));
	if (tokens == NULL)
	{
		fprintf(stderr, "USAGE: malloc failed\n");
		free_all(st);
	}
	str = strtok(buffer, " ");

	while (str)
	{
		tokens[i++] = str;
		str = strtok(NULL, " ");
	}
	tokens[i] = NULL;

	return (tokens);
}

/**
 * check_type - check the type of the list.
 *
 * Return: 1 in success, 0 in failure.
 */

int check_type(void)
{
	if (strcmp(tokens[0], "stack") == 0)
	{
		SQ = 0;
		return (1);
	}
	if (strcmp(tokens[0], "queue") == 0)
		{
		SQ = 1;
		return (1);
	}
	return (0);
}


/**
 * check_monty - execute a monty file.
 * @p: pointer to a file.
 *
 * Return: EXIT_SUCCESS , EXIT_FAILURE.
 */

int check_monty(FILE *p)
{
	char **tokens;
	int words = 0, c;
	size_t l = 0;
	unsigned int  nbl = 0;
	void (*func)(stack_t **stack, unsigned int);
	stack_t *st = NULL;

	while (1)
	{
		c = getline(&buffer, &l, p);
		if (c == -1)
			break;
		nbl++;
		buffer[c - 1] = '\0';
		words = word(buffer, ' ');
		if (words == 0)
			continue;
		tokens = create_tokens(buffer, words, st);
		if (!tokens)
		{
			fprintf(stderr, "USAGE: malloc failed\n");
			free_all(st);
		}
		if (tokens[0][0] == '#' || check_type() == 1)
		{
			free(tokens);
			continue;
		}
		func = get_f(tokens[0]);
		if (!func)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", nbl, tokens[0]);
			free_all(st);
		}
		func(&st, nbl);
		free(tokens);
	}
	free_list(st);
	return (EXIT_SUCCESS);
}
