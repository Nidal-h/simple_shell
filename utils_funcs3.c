#include "shell.h"

/**
 * _atoi - Converting a str to an int.
 * @string: The string to convert.
 *
 * Return: The int value of str.
 */
int _atoi(const char *string)
{
	unsigned int numero;
	int signal, j;
	

	j = 0;
	signal = 1;
	numero = 0;

	while (string[j] != '\0')
	{
		if (string[j] == '-')
			signal *= -1;
		else if (string[j] >= '0' && string[j] <= '9')
			numero = (numero * 10) + (string[j] - '0');
		else
			break;
		j++;
	}
	return (numero * signal);
}

/**
 **_memset - Populating a memory area with a const byte.
 *@s: Pointer to the mem area
 *@byte: The byte to fill with
 *@number: The num of bytes to fill.
 *Return: (s) pointer to the mem area s
 */
char *_memset(char *s, char byte, unsigned int number)
{
	unsigned int j;

	for (j = 0; j < number; j++)
		s[j] = byte;
	return (s);
}

/**
 * _memcpy - Copies a specified memory area.
 *
 * @destination: Buffer to copy to.
 * @source: Data to be copied.
 * @n: Number of bytes from @source to copy.
 *
 * Return: Always 0 (Success)
*/

char *_memcpy(char *destination, char *source, unsigned int n)
{
	unsigned int j;

	for (j = 0; j < n; j++)
		destination[j] = source[j];
	return (destination);
}

/**
 * _realloc - Adjusts the size of a previously allocated memory block.
 * @pointer: Pointer to the previous mallocated block.
 * @old_sz: Byte size of the previous block.
 * @new_sz: Byte size of the new block.
 *
 * Return: Returns a pointer to the old block if successful.
 */
void *_realloc(void *pointer, unsigned int old_sz, unsigned int new_sz)
{
	char *n;

	if (!pointer)
		return (malloc(new_sz));
	if (!new_sz)
		return (free(pointer), NULL);
	if (new_sz == old_sz)
		return (pointer);

	n = malloc(new_sz);
	if (!n)
		return (NULL);

	old_sz = old_sz < new_sz ? old_sz : new_sz;
	while (old_sz--)
		n[old_sz] = ((char *)pointer)[old_sz];
	free(pointer);
	return (n);
}

/**
 * _calloc - a function that allocates
 *           memory for an array using malloc
 *
 *           It is basically the equivalent to
 *           malloc followed by memset
 *
 * @nmemb: size of array
 * @size: size of each element
 *
 * Return: pointer with new allocated memory
 *         or NULL if it fails
*/

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *p;

	if (nmemb == 0 || size == 0)
		return (NULL);

	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);

	_memset(p, 0, nmemb * size);

	return (p);
}
