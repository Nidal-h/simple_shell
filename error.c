#include "shell.h"

/**
 * _puts - Displays a string to the standard output stream.
 * @string: The string to be printed.
 * Return: Void
 */
void _puts(char *string)
{
	ssize_t num;
	size_t length;
	

	length = _strlen(string);
	num = write(STDOUT_FILENO, string, length);
	if (num == -1)
	{
		perror("write");
	}
}

/**
 * _puterror - Displays an error message to the standard error stream
 * @error: The error message to be printed.
 * Return: Void
 */
void _puterror(char *error)
{
	size_t length;
	ssize_t num;

	length = _strlen(error);
	num = write(STDERR_FILENO, error, length);
	if (num == -1)
	{
		perror("write");
	}
}
