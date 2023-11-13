#include "shell.h"

/**
 * shell_setenv - Assigns a value to an environment variable.
 * @arguments: Arguments specifies the name and value of the environment variable.
 *
 * Return: Nothing
 */
int shell_setenv(char **arguments)
{
	char *v, *n;

	if (arguments[1] == NULL || arguments[2] == NULL)
	{
		_puterror("Usage: setenv VARIABLE VALUE\n");
		return (-1);
	}

	n = arguments[1];
	v = arguments[2];

	if (setenv(n, v, 1) != 0)
	{
		_puterror("setenv");
		return (-1);
	}
	return (0);
}

/**
 * shell_unsetenv - Removes a specified environment variable.
 * @arguments: Arguments specifies the name of the environment variable.
 *
 * Return: Nothing
 */
int shell_unsetenv(char **arguments)
{
	char *n;

	if (arguments[1] == NULL)
	{
		_puterror("Usage: unsetenv VARIABLE\n");
		return (-1);
	}

	n = arguments[1];

	if (unsetenv(n) != 0)
	{
		_puterror("unsetenv");
	}
	return (0);
}
