#include "shell.h"

/**
 * shell_cd - Modifies the current working directory
 * @arguments: The array of arguments.
 */
void shell_cd(char **arguments)
{
	int i;
	char *directory = arguments[1];
	


	if (directory == NULL)
	{
		directory = _getenv("HOME");
		if (directory == NULL)
		{
			_puts("cd: No HOME directory found\n");
			return;
		}
	}

	i = chdir(directory);
	if (i == -1)
	{
		perror("cd");
	}
}
