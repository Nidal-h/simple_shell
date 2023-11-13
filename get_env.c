#include "shell.h"

/**
 * _getenv - Retrieves the value of an environment variable.
 * @n: Name of the environment variable
 *
 * Return: return the value of the environment variable, or NULL if it doesn't exist
 */
char *_getenv(const char *n)
{
	size_t len = _strlen(n);
	char **environment;
	

	for (environment = environ; *environment != NULL; environment++)
	{
		if (_strncmp(*environment, n, len) == 0 && (*environment)[len] == '=')
		{
			return (&(*environment)[len + 1]);
		}
	}

	return (NULL);
}
