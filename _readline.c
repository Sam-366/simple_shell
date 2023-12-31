#include "simple_shell.h"

/**
 * read_line - function that reads the input string.
 *
 * @i_eof: return value of getline function
 *
 * Return: returns input string
 */

char *read_line(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}
