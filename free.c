#include "shell.h"

/**
 * free_error - Releases allocated memory for pointers in response to a system error.
 * @argp: A pointer to a pointer to an array of pointers.
 * @arguments: A pointer to a pointer to an array of characters.
 *
 * Return: void.
 */
void free_error(char **argp, char *arguments)
{
	int index;

	for (index = 0; argp[index]; index++)
		free(argp[index]);
	free(argp);
	free(arguments);
	exit(EXIT_FAILURE);
}

/**
 * free_tokens - Releases dynamically allocated memory from the tokenize() function.
 * @pointer: A pointer to the allocated memory.
 *
 * Return: void.
 */
void free_tokens(char **pointer)
{
	int index;

	for (index = 0; pointer[index]; index++)
		free((pointer[index]));
	free(pointer);
}

/**
 * free_path - Deallocates the memory occupied by the global variable storing 
 *             the value of the PATH environment variable.
 *
 * Return: Nothing.
 */
void free_path(void)
{
	if (environ != NULL)
	{
		size_t index = 0;

		while (environ[index] != NULL)
		{
			if (_strncmp(environ[index], "PATH=", 5) == 0)
			{
				free(environ[index]);
				environ[index] = NULL;
				break;
			}
			index++;
		}
	}
}
