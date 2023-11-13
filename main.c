#include "shell.h"

/**
 * main - implements a simple shell
 *
 * Return: EXIT_SUCCESS.
 */
int main(void)
{
	int s;
	char **arguments;
	char *i;
	
	/* Register signal handlers */
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	signal(SIGTSTP, handle_sigstp);

	do {
		i = get_input();
		if (!i || !*i)/* EOF detected, exit the loop */
			break;

		arguments = tokenize_input(i);
		if (!arguments || !*arguments)
		{
			free(i);
			free_tokens(arguments);
			continue;
		}
		s = execute(arguments);
		free(i);
		free_tokens(arguments);

		s = 1;
	} while (s);

	return (EXIT_SUCCESS);
}
