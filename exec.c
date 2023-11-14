#include "main.h"
/**
 * execute - execute the command
 * @arguments: array of command arguments
 *
 * Return: the result of the executed function
 */
int execute(char **arguments)
{
    int (*builtin_func[])(char **) = {
        &my_cd,
        &my_env,
        &my_help,
        &my_exit
    };

    char *builtin_commands[13] = {
        "cd",
        "env",
        "help",
        "exit"
    };
    int index;

    if (arguments[0] == NULL)
        return -1;

    for (index = 0; index < num_builtin(builtin_commands); index++)
    {
        if (strcmp(arguments[0], builtin_commands[index]) == 0)
        {
            return (*builtin_func[index])(arguments);
        }
    }
    return launch(arguments);
}
