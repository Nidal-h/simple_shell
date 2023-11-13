#include "shell.h"

/**
 * execute - Execute a command along with its arguments.
 * @arguments: An array that containe the command and its arguments.
 *
 * Return: The status of the executed command.
 */
int execute(char **arguments)
{
	char *envi[2], *path;
	pid_t i;
	int s = 0;

	if (arguments == NULL || *arguments == NULL)
		return (s);
	if (check_for_builtin(arguments))
		return (s);

	i = fork();
	if (i < 0)
	{
		_puterror("fork");
		return (1);
	}
	if (i == -1)
		perror(arguments[0]), free_tokens(arguments), free_last_input();
	if (i == 0)
	{
		envi[0] = get_path();
		envi[1] = NULL;
		path = NULL;
		if (arguments[0][0] != '/')
			path = find_in_path(arguments[0]);
		if (path == NULL)
			path = arguments[0];
		if (execve(path, arguments, envi) == -1)
		{
			perror(arguments[0]), free_tokens(arguments), free_last_input();
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do {
			waitpid(i, &s, WUNTRACED);
		} while (!WIFEXITED(s) && !WIFSIGNALED(s));
	}
	return (s);
}
