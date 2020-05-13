#include "monty.h"

FILE *p = NULL;

/**
 * main - execute a monty file.
 * @ac: number of arguments.
 * @av: list of arguments
 *
 * Return: 0 in success, -1 in failure.
 */

int main(int ac, char **av)
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);

	}
	p = fopen(av[1], "r");
	if (!p)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		return (EXIT_FAILURE);
	}

	check_monty(p);
	fclose(p);
	free(buffer);
	return (EXIT_SUCCESS);
}
