#include "shell.h"

/**
 * _strcpy - copying a string
 * @destination: desct
 * @source: src
 *
 * Return: pointer to dest
 */
char *_strcpy(char *destination, char *source)
{
	int j = 0;

	if (destination == source || source == 0)
		return (destination);
	while (source[j])
	{
		destination[j] = source[j];
		j++;
	}
	destination[j] = 0;
	return (destination);
}

/**
 * _strcat - concatenates two strings
 * @destination: the destination buffer
 * @source: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *destination, const char *source)
{
	char *r = destination;

	while (*destination)
		destination++;
	while (*source)
		*destination++ = *source++;
	*destination = *source;
	return (r);
}

/**
 * _strdup - Creates a duplicate of a string.
 * @string: The string to be duplicated.
 *
 * Return: Pointer to the duplicated string.
 */
char *_strdup(const char *string)
{
	int len = 0;
	char *r;

	if (string == NULL)
		return (NULL);
	while (*string++)
		len++;
	r = malloc(sizeof(char) * (len + 1));
	if (!r)
		return (NULL);
	for (len++; len--;)
		r[len] = *--string;
	return (r);
}

/**
 *_putchar - Outputs the character ch to the standard output.
 * @ch: The character to be printed.
 * Return: On success, returns 1.
 * On error, returns -1, and sets errno appropriately.
 */
int _putchar(char ch)
{
	return (write(1, &ch, 1));
}

/**
 * _strspn - A function that calculates the
 *           length of a prefix substring
 *
 * @s: pointer to the input string.
 * @acc: substring prefix to search for.
 *
 * Return: the number of bytes in the initial segment
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
