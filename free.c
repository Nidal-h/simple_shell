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
	int j;

	for (j = 0; argp[j]; j++)
		free(argp[j]);
	free(argp);
	free(arguments);
	exit(EXIT_FAILURE);
}

/**
 * free_tokens -  Releases dynamically allocated memory from the tokenize() function.
 * @pointer: A pointer to the allocated memory
 *
 * Return: void.
 */
void free_tokens(char **pointer)
{
	int j;

	for (j = 0; pointer[j]; j++)
		free((pointer[j]));
	free(pointer);
}


/**
 * free_path - Deallocates the memory occupied by the global variable storing 
 *              the value of the PATH environment variable
 *
 * Return: Nothing
 */
void free_path(void)
{
	if (environ != NULL)
	{
		size_t j = 0;

		while (environ[j] != NULL)
		{
			if (_strncmp(environ[j], "PATH=", 5) == 0)
			{
				free(environ[j]);
				environ[j] = NULL;
				break;
			}
			j++;
		}
	}
}
