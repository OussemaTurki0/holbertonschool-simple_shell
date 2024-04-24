#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
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

    path = get_command_path(args[0]);
    if (path == NULL)
        return (1);

    if (handle_built_in(args, &status) == 1)
    {
        free(path);  /* Free path if it's a built-in command */
        return (status);
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

    free(path);  /* Free path if it's an external command */
    return (1);
}
