#include "shell.h"

/**
 * main - simple shell
 *
 * Return: EXIT_SUCCESS
 */
int main(void)
{
	int p;
	char **args;
	char *i;
	
	/* Registering handlers */
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	signal(SIGTSTP, handle_sigstp);

	do {
		i = get_input();
		if (!i || !*i)/* EOF detected so we need to exit the loop */
			break;

		args = tokenize_input(i);
		if (!args || !*args)
		{
			free(i);
			free_tokens(args);
			continue;
		}
		p = execute(args);
		free(i);
		free_tokens(args);

		p = 1;
	} while (p);

	return (EXIT_SUCCESS);
}
