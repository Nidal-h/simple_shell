#include "shell.h"

/**
 * main - Simple shell
 *
 * Return: EXIT_SUCCESS
 */
int main(void)
{
	int proceed;
	char **arguments;
	char *input;

	/* Registering signal handlers */
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	signal(SIGTSTP, handle_sigstp);

	do {
		input = get_input();
		if (!input || !*input)/* EOF detected, exit the loop */
			break;

		arguments = tokenize_input(input);
		if (!arguments || !*arguments)
		{
			free(input);
			free_tokens(arguments);
			continue;
		}

		proceed = execute(arguments);

		free(input);
		free_tokens(arguments);

		proceed = 1;
	} while (proceed);

	return (EXIT_SUCCESS);
}
