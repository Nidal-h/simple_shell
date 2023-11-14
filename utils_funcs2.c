```c
#include "shell.h"

/**
 * _strcpy - Copies a string from source to destination.
 * @destination: The destination buffer.
 * @source: The source string.
 *
 * Return: A pointer to the destination buffer.
 */
char *_strcpy(char *destination, char *source)
{
	int index = 0;

	if (destination == source || source == NULL)
		return (destination);

	while (source[index])
	{
		destination[index] = source[index];
		index++;
	}
	destination[index] = '\0';
	return (destination);
}

/**
 * _strcat - Concatenates two strings.
 * @destination: The destination buffer.
 * @source: The source buffer.
 *
 * Return: A pointer to the destination buffer.
 */
char *_strcat(char *destination, const char *source)
{
	char *result = destination;

	while (*destination)
		destination++;

	while (*source)
		*destination++ = *source++;

	*destination = *source;
	return (result);
}

/**
 * _strdup - Creates a duplicate of a string.
 * @string: The target string.
 *
 * Return: Pointer to the resulting string, or NULL on failure.
 */
char *_strdup(const char *string)
{
	int length = 0;
	char *result;

	if (string == NULL)
		return (NULL);

	while (*string++)
		length++;

	result = malloc(sizeof(char) * (length + 1));

	if (!result)
		return (NULL);

	for (length++; length--;)
		result[length] = *--string;

	return (result);
}

/**
 * _putchar - Outputs the character 'ch' to the standard output.
 * @ch: The character to be printed.
 *
 * Return: On success, returns 1. On error, returns -1, and sets errno appropriately.
 */
int _putchar(char ch)
{
	return (write(1, &ch, 1));
}

/**
 * _strspn - Calculates the length of a prefix substring.
 * @s: Pointer to the input string.
 * @acc: Substring prefix to search for.
 *
 * Return: The number of bytes in the initial segment.
 */
unsigned int _strspn(char *s, char *acc)
{
	unsigned int i, j;

	for (i = 0; s[i]; i++)
	{
		for (j = 0; acc[j]; j++)
		{
			if (s[i] == acc[j])
				break;
		}
		if (!acc[j])
			return (i);
	}

	return (i);
}