#include "shell.h"

/**
 * _strlen - represents the length of a string
 * @string: the string to determine the length to check
 *
 * Return: integer length of string
 */
int _strlen(const char *string)
{
	int i = 0;

	if (!string)
		return (0);

	while (*string++)
		i++;
	return (i);
}

/**
 * _strcmp - Comparing two strings.
 * @string1: The 1st string to compare.
 * @string2: The 2nd string to compare.
 * Return: return 0 if @string1 and @string2 are equal,
 *         return negative value if @string1 is less than @string2,
 *         or a positive value if @string1 is greater than @string2.
 */
int _strcmp(const char *string1, const char *string2)
{
	while (*string1 != '\0' && *string2 != '\0' && *string1 == *string2)
	{
		string1++;
		string2++;
	}

	return ((int) (*string1) - (*string2));
}

/**
 * _strncmp - Compare two strings up to a specified length.
 * @string1: First string to compare.
 * @string2: Second string to compare.
 * @m: Maximum number of characters to compare.
 *
 * Return: return 0 if the strings are equal up to m characters,
 *         return negative value if string1 is less than string2, 
 *         or positive value if string1 is greater than string2.
 */
int _strncmp(const char *string1, const char *string2, size_t m)
{
	unsigned char ch1, ch2;

	while (m-- > 0)
	{
		ch1 = (unsigned char) *string1++;
		ch2 = (unsigned char) *string2++;

		if (ch1 != ch2)
			return (ch1 - ch2);
		if (ch1 == '\0')
			break;
	}

	return (0);
}

/**
 * _strstr - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: return the address of the next character of haystack or NULL
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
				{
					break;
				}
			}

			if (needle[j] == '\0')
			{
				return (&haystack[i]);
			}
		}
	}
	return (NULL);
}

/**
 * _strchr - function that finds a character in a string
 *
 * @string: pointer to our string array input
 * @ch: character to locate from input array
 *
 * Return: the first occurence of a specified charatcer or null if not found
*/

char *_strchr(char *string, char ch)
{
	while (*string != '\0')
	{
		if (*string == ch)
			return (string);
		string++;
	}
	/**
	 * if ch is '\0', you should return
	 * the pointer to the '\0' of the
	 * string string
	*/
	if (*string == ch)
		return (string);
	/*return null if not found*/
	return (NULL);
}
