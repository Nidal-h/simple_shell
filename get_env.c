#include "shell.h"

/**
 * _getenv - Retrieves the value of an environment variable.
 * @name: Name of the environment variable.
 *
 * Return: The value of the environment variable, or NULL if it doesn't exist.
 */
char *_getenv(const char *name)
{
	size_t len = _strlen(name);
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(*env, name, len) == 0 && (*env)[len] == '=')
		{
			return (&(*env)[len + 1]);
		}
	}

	return (NULL);
}
