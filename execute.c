#include "shell.h"

/**
 * execute - Execute a command along with its arguments.
 * @arguments: An array that contains the command and its arguments.
 *
 * Return: The status of the executed command.
 */
int execute(char **arguments)
{
	char *env_vars[2], *full_path;
	pid_t child_pid;
	int status = 0;

	if (arguments == NULL || *arguments == NULL)
		return (status);

	if (check_for_builtin(arguments))
		return (status);

	child_pid = fork();
	if (child_pid < 0)
	{
		_puterror("fork");
		return (1);
	}

	if (child_pid == -1)
	{
		perror(arguments[0]);
		free_tokens(arguments);
		free_last_input();
	}

	if (child_pid == 0)
	{
		env_vars[0] = get_path();
		env_vars[1] = NULL;
		full_path = NULL;

		if (arguments[0][0] != '/')
			full_path = find_in_path(arguments[0]);

		if (full_path == NULL)
			full_path = arguments[0];

		if (execve(full_path, arguments, env_vars) == -1)
		{
			perror(arguments[0]);
			free_tokens(arguments);
			free_last_input();
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do {
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (status);
}
