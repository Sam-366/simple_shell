#include "simple_shell.h"

/**
 * exec_line - function that finds builtins and commands
 *
 * @datash: data relevant (args)
 *
 * Return: 1 on success, otherwise 0.
 */

int exec_line(data_shell *datash)
{
	int (*builtin)(data_shell *datash);

	if (datash->args[0] == NULL)
		return (1);

	builtin = get_builtin(datash->args[0]);

	if (builtin != NULL)
		return (builtin(datash));

	return (exec_cmd_line(datash));
}
