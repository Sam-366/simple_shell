#include "simple_shell.h"

/**
 * get_sigint - function that handles the crtl + c call in prompt
 *
 * @sig: signal 
 *
 * Return: none
 */

void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}
