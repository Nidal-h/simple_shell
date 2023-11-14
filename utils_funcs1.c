#include "shell.h"

/**
 * _strlen - Calculates the length of a string.
 * @string: The string to determine the length of.
 *
 * Return: Integer length of the string.
 */
int _strlen(const char *string)
{
	int length = 0;

	if (!string)
		return (0);

	while (*string++)
		length++;

	return (length);
}

/**
 * _strcmp - Compares two strings.
 * @string1: The first string to compare.
 * @string2: The second string to compare.
 *
 * Return: 0 if @string1 and @string2 are equal,
 *         a negative value if @string1 is less than @string2,
 *         or a positive value if @string1 is greater than @string2.
 */
int _strcmp(const char *string1, const char *string2)
{
	while (*string1 != '\0' && *string2 != '\0' && *string1 == *string2)
	{
		string1++;
		string2++;
	}

	return ((int)(*string1) - (*string2));
}

/**
 * _strncmp - Compares two strings up to a specified length.
 * @string1: First string to compare.
 * @string2: Second string to compare.
 * @n: Maximum number of characters to compare.
 *
 * Return: 0 if the strings are equal up to n characters,
 *         a negative value if string1 is less than string2,
 *         or a positive value if string1 is greater than string2.
 */
int _strncmp(const char *string1, const char *string2, size_t n)
{
	unsigned char ch1, ch2;

	while (n-- > 0)
	{
		ch1 = (unsigned char)*string1++;
		ch2 = (unsigned char)*string2++;

		if (ch1 != ch2)
			return (ch1 - ch2);
		if (ch1 == '\0')
			break;
	}

	return (0);
}

/**
 * _strstr - Checks if needle starts with haystack.
 * @haystack: String to search.
 * @needle: The substring to find.
 *
 * Return: Address of the next character of haystack or NULL.
 */
char *_strstr(char *haystack, char *needle)
{
	int i;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		if (haystack[i] == needle[0])
		{
			int j;

			for (j = 0; needle[j] != '\0'; j++)
			{
				if (haystack[i + j] != needle[j])
					break;
			}

			if (needle[j] == '\0')
				return (&haystack[i]);
		}
	}

	return (NULL);
}

/**
 * _strchr - Finds a character in a string.
 * @string: Pointer to the string array input.
 * @ch: Character to locate in the input array.
 *
 * Return: The first occurrence of a specified character or NULL if not found.
 */
char *_strchr(char *string, char ch)
{
	while (*string != '\0')
	{
		if (*string == ch)
			return (string);
		string++;
	}

	/*
	 * If ch is '\0', return the pointer to the '\0' of the string string.
	 */
	if (*string == ch)
		return (string);

	/* Return NULL if not found. */
	return (NULL);
}