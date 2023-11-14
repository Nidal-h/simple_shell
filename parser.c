#include "shell.h"

/**
 * tokenize - Parses user input into arguments by dividing a string into 
 *            tokens using a specified delimiter.
 * @string: The string to be tokenized.
 * @delimiter: The delimiter used to split the string.
 *
 * Return: An array of pointers to tokens, or NULL if an error occurs.
 */
char **tokenize(char *string, const char *delimiter)
{
	int j = 0;
	char *token = NULL;
	char **result = NULL;

	token = strtok(string, delimiter);
	while (token)
	{
		result = realloc(result, sizeof(char *) * (j + 1));
		if (result == NULL)
			return (NULL);

		result[j] = malloc(_strlen(token) + 1);
		if (!result[j])
			return (NULL);

		_strcpy(result[j], token);
		token = strtok(NULL, delimiter);
		j++;
	}

	result = realloc(result, (j + 1) * sizeof(char *));
	if (!result)
		return (NULL);

	result[j] = NULL;
	return result;
}

/**
 * tokenize_input - Divides a user input string into tokens using the tokenize() function.
 * @input: The user input string to be tokenized.
 *
 * Return: An array of pointers to tokens, or NULL if an error occurs.
 */
char **tokenize_input(char *input)
{
	char **tokens = NULL;
	char *temporary = NULL;

	temporary = _strdup(input);
	if (temporary == NULL)
	{
		_puts("Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	tokens = tokenize(temporary, " \t\r\n\a");
	free(temporary);

	return tokens;
}