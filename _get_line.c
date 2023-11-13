#include "shell.h"

/**
 * get_line - retrieve the string typed by the user.
 *
 * Return: The string.
*/
void *get_line(void)
{
	char curr_char;
	static int buffer_pos, buffer_size;
	int len = 0;
	static char buf[BUFFER_SIZE];
	char *str = NULL;
	

	while (1)
	{
		if (buffer_pos >= buffer_size)
		{
			buffer_size = read(STDIN_FILENO, buf, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_size == 0)
				return (str);
			else if (buffer_size < 0)
			{
				perror("read");
				return (NULL);
			}
		}

		curr_char = buf[buffer_pos];

		buffer_pos++;

		if (curr_char == '\n')
		{
			str = realloc(str, len + 1);
			str[len] = '\0';
			return (str);
		}
		else
		{
			str = realloc(str, len + 1);
			str[len] = curr_char;
			len++;
		}
	}
}
