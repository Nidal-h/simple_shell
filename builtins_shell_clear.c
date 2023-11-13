#include "shell.h"

/**
 * shell_clear - Resets the screen of terminal.
 * @arguments: the array of arguments
 *
 * Return: 1 to proceed with execution,
 *         0 to exit.
*/
int shell_clear(char **arguments)
{
	(void)arguments; 
	_puts("\033[2J\033[H");
	return (1);
}
