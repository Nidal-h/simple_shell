#include "shell.h"

/**
 * shell_exit - Terminates the shell.
 * @arguments: The array of Arguments.
 *
 * Return: Nothing.
 */
void shell_exit(char **arguments)
{
	int s = 0;

	if (arguments[1] != NULL)
	{
		s = _atoi(arguments[1]);
	}
	free_tokens(arguments);
	free_last_input();
	exit(s);
}
