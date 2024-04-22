#include "4-shell.h"

/**
 * execute_command - Execute a command.
 * @args: Array of command arguments.
 *
 * Return: 1 to continue the shell loop, 0 to exit the shell.
 */
int execute_command(char **args)
{
    int status = 0;
    pid_t pid;
    char *path;

    if (args[0] == NULL)
        return (1);

    if (handle_built_in(args, &status) == 1)
    {
        printf("Handled as built-in\n");

        return (status);
    }
    path = get_command_path(args[0]);
    printf("Not a built-in command\n");

    if (path == NULL)
    {
        fprintf(stderr, "%s: command not found\n", args[0]);
        return (1);
    }

    pid = fork();

    if (pid == 0)
    {
        if (execve(path, args, environ) == -1)
        {
            perror("Error");
            exit(EXIT_FAILURE);
        }
    }
    else if (pid < 0)
    {
        perror("Error");
    }
    else
    {
        waitpid(pid, &status, 0);
    }

    free(path);
    return (1);
}
