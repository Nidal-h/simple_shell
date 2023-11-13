#include "shell.h"

/**
 * check_for_builtin : Verifies whether the command is a builtin
 * @arguments: The array of arguments
 *
 * Return: the command is a builtin return 1, return 0 if its not builtin.
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
