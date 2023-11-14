#include "shell.h"

/**
 * handle_sigint - Handles the SIGINT (Ctrl+C) signal.
 * @signal: The signal number.
 *
 * Return: Nothing.
 */
void handle_sigint(int signal)
{
	(void)signal;
	_putchar('\n');
	prompt();
}

/**
 * handle_sigquit - Handles the SIGQUIT (Ctrl+\) signal.
 * @signal: The signal number.
 *
 * Return: Nothing.
 */
void handle_sigquit(int signal)
{
	(void)signal;
	_puterror("Quit (core dumped)\n");
	exit(EXIT_SUCCESS);
}

/**
 * handle_sigstp - Handles the SIGTSTP (Ctrl+Z) signal.
 * @signal: The signal number.
 *
 * Return: Nothing.
 */
void handle_sigstp(int signal)
{
	(void)signal;
	_puts("\n");
	prompt();
}
