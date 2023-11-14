#include "shell.h"

/**
 * find_in_path - Searches for a command in each directory mentioned in the PATH
 *                environment variable.
 * @cmd: Pointer to the string containing the command.
 *
 * Return: A pointer to the string containing the full path (success) if found,
 *         or NULL if not found (failure).
 */
char *find_in_path(char *cmd)
{
	char buffer[PATH_MAX_LENGTH], *path, *result, **directories;
	struct stat st;
	int stat_result, i;

	path = get_path();
	if (!path)
		return (NULL);
	directories = tokenize(path, PATH_SEPARATOR);
	if (!directories)
		return (NULL);
	for (i = 0; directories[i]; i++)
	{
		_memset(buffer, 0, PATH_MAX_LENGTH);
		_strcpy(buffer, directories[i]);
		_strcat(buffer, "/");
		_strcat(buffer, cmd);
		stat_result = stat(buffer, &st);
		if (stat_result == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
		{
			free_tokens(directories);
			result = malloc(sizeof(char) * (strlen(buffer) + 1));
			if (!result)
				return (NULL);
			strcpy(result, buffer);
			return (result);
		}
	}
	if (stat_result == -1)
		free_tokens(directories);
	return (NULL);
}
