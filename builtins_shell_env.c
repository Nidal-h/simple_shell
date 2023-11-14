#include "shell.h"

/**
 * shell_env - Displays all variables of the environment.
 *
 * Return: 0 on success, -1 on failure.
 */
int shell_env(void)
{
	int index;

	for (index = 0; environ[index]; index++)
	{
		_puts(environ[index]);
		_putchar('\n');
	}

	return (0);
}
