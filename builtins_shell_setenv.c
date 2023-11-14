#include "shell.h"

/**
 * shell_setenv - Assigns a value to an environment variable.
 * @arguments: Arguments specifying the name and value of the environment variable.
 *
 * Return: 0 on success, -1 on failure.
 */
int shell_setenv(char **arguments)
{
	char *variable, *value;

	if (arguments[1] == NULL || arguments[2] == NULL)
	{
		_puterror("Usage: setenv VARIABLE VALUE\n");
		return (-1);
	}

	variable = arguments[1];
	value = arguments[2];

	if (setenv(variable, value, 1) != 0)
	{
		_puterror("setenv");
		return (-1);
	}
	return (0);
}

/**
 * shell_unsetenv - Removes a specified environment variable.
 * @arguments: Arguments specifying the name of the environment variable.
 *
 * Return: 0 on success, -1 on failure.
 */
int shell_unsetenv(char **arguments)
{
	char *variable;

	if (arguments[1] == NULL)
	{
		_puterror("Usage: unsetenv VARIABLE\n");
		return (-1);
	}

	variable = arguments[1];

	if (unsetenv(variable) != 0)
	{
		_puterror("unsetenv");
		return (-1);
	}
	return (0);
}
