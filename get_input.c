#include "shell.h"

static char *last;

/**
 * get_input - Captures a line of input from the user.
 *
 * Return: Pointer to a buffer containing the user's input.
 */
char *get_input(void)
{
	size_t size = 0;
	ssize_t read;
	char *input = NULL;

	do {
		prompt();

		read = getline(&input, &size, stdin);

		if (read == -1)
		{
			free(input);
			_puts("\n");
			return (NULL);
		}

		input[read - 1] = '\0';

	} while (input[0] == '\0' || isspace(input[0]));

	last = input;
	return input;
}

/**
 * free_last_input - Deallocates the memory associated with the latest user-entered input.
 *
 * This function is responsible for releasing the memory allocated for 
 * the most recent input string provided by the user. It should be
 * invoked once the input string is no longer required.
 */
void free_last_input(void)
{
	free(last);
	last = NULL;
}
