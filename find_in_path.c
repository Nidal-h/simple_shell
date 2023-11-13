#include "shell.h"

/**
 * find_in_path - Searches for every command in each directory mentioned in the PATH
 *                environment variable
 * @cmd: pointer to the string `cmd`.
 *
 * Return: A pointer to the string containing the full path (success) if it is found,
 *         or NULL if it is not found (failure).
*/
char *find_in_path(char *cmd)
{
	char buf[PATH_MAX_LENGTH], *path, *r, **directory;
	struct stat st;
	int st_ret, i;

	path = get_path();
	if (!path)
		return (NULL);
	directory = tokenize(path, PATH_SEPARATOR);
	if (!directory)
		return (NULL);
	for (i = 0; directory[i]; i++)
	{
		_memset(buf, 0, PATH_MAX_LENGTH);
		_strcpy(buf, directory[i]);
		_strcat(buf, "/");
		_strcat(buf, cmd);
		st_ret = stat(buf, &st);
		if (st_ret == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
		{
			free_tokens(directory);
			r = malloc(sizeof(char) * (strlen(buf) + 1));
			if (!r)
				return (NULL);
			strcpy(r, buf);
			return (r);
		}
	}
	if (st_ret == -1)
		free_tokens(directory);
	return (NULL);
}
