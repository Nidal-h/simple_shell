#include "shell.h"

/**
 * prompt - Displays the shell prompt on the stdin stream.
 *
 * Return: void.
 */
void prompt(void)
{
	_puts(PROMPT);
	fflush(stdout);
}
