#include "shell.h"

/**
 * shell_env - Displays all variables of the environment.
 *
 * Return: Void.
 */
int shell_env(void)
{
	int j;

	for (j = 0; environ[j]; j++)
	{
		_puts(environ[j]);
		_putchar('\n');
	}

	return (0);
}
