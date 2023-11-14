#include "shell.h"

/**
 * check_for_builtin - Verifies whether the command is a built-in.
 * @arguments: The array of arguments.
 *
 * Return: 1 if the command is a built-in, 0 if it's not a built-in.
 */
int check_for_builtin(char **arguments)
{
	if (!arguments[0])
		return (0);

	if (!_strcmp(arguments[0], "exit"))
		shell_exit(arguments);
	else if (!_strcmp(arguments[0], "env"))
		shell_env();
	else if (!_strcmp(arguments[0], "setenv"))
		shell_setenv(arguments);
	else if (!_strcmp(arguments[0], "unsetenv"))
		shell_unsetenv(arguments);
	else if (!_strcmp(arguments[0], "help"))
		shell_help();
	else if (!_strcmp(arguments[0], "cd"))
		shell_cd(arguments);
	else if (!_strcmp(arguments[0], "clear"))
		shell_clear(arguments);
	else
		return (0);

	return (1);
}
