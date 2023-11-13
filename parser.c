#include "shell.h"

/**
 * tokenize - Parses user input into arguments by dividing a string into 
 *            tokens using a specified delimiter.
 * @string: the string to be tokenized.
 * @delimeter: the delimiter used to split the string.
 *
 * Return: array of pointers,
 *         or NULL if an error occurs.
 */
char **tokenize(char *string, const char *delimeter)
{
	int j = 0;
	char *tok = NULL;
    char **r = NULL;
	
	tok = strtok(string, delimeter);
	while (tok)
	{
		r = realloc(r, sizeof(char *) * (j + 1));
		if (r == NULL)
			return (NULL);

		r[j] = malloc(_strlen(tok) + 1);
		if (!(r[j]))
			return (NULL);

		_strcpy(r[j], tok);
		tok = strtok(NULL, delimeter);
		j++;
	}
	r = realloc(r, (j + 1) * sizeof(char *));
	if (!r)
		return (NULL);

	r[j] = NULL;
	return (r);
}

/**
 * tokenize_input - Divides a user input string into tokens using the tokenize() function.
 * @input: The user input string to be tokenized.
 *
 * Return: array of pointers, or NULL if an error occurs
 */
char **tokenize_input(char *input)
{
	char **toks = NULL;
	char *tmp = NULL;

	tmp = _strdup(input);
	if (tmp == NULL)
	{
		_puts("Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	toks = tokenize(tmp, " \t\r\n\a");
	free(tmp);

	return (toks);
}
