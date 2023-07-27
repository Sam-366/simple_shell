#include "simple_shell.h"

/**
 * free_data - function that frees data structure
 *
 * @datash: data structure
 *
 * Return: none
 */

void free_data(data_shell *datash)
{
	unsigned int k;

	for (k = 0; datash->_environ[k]; k++)
	{
		free(datash->_environ[k]);
	}

	free(datash->_environ);
	free(datash->pid);
}

/**
 * set_data - function that initialize data structure
 *
 * @datash: data structure
 *
 * @av: arg vector
 *
 * Return: none
 */

void set_data(data_shell *datash, char **av)
{
	unsigned int i;

	datash->av = av;
	datash->input = NULL;
	datash->args = NULL;
	datash->status = 0;
	datash->counter = 1;

	for (i = 0; environ[i]; i++)
		;

	datash->_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		datash->_environ[i] = _strdup(environ[i]);
	}

	datash->_environ[i] = NULL;
	datash->pid = aux_itoa(getpid());
}

/**
 * main - Entry point to the programme
 *
 * @ac: argument count
 *
 * @av: argument vector
 *
 * Return: 0 on success.
 */

int main(int ac, char **av)
{
	data_shell datash;
	(void) ac;

	signal(SIGINT, get_sigint);
	set_data(&datash, av);
	shell_loop(&datash);
	free_data(&datash);
	if (datash.status < 0)
		return (255);
	return (datash.status);
}
