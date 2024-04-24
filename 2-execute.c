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

    if (args == NULL || args[0] == NULL)
    {
        /* Empty command */
        return 1;
    }

    if (strcmp(args[0], "exit") == 0)
    {
        /* Exit the shell */
        return 0;
    }

    if (strcmp(args[0], "env") == 0)
    {
        /* Print environment variables */
        char **env;
        for (env = environ; *env != NULL; env++)
        {
            printf("%s\n", *env);
        }
        return 1;
    }

    if (strcmp(args[0], "cd") == 0)
    {
        /* Change directory */
        if (args[1] == NULL)
        {
            fprintf(stderr, "Error: cd: missing argument\n");
        }
        else if (chdir(args[1]) != 0)
        {
            perror("Error");
        }
        return 1;
    }

    /* For other commands, try to execute them */
    pid = fork();

    if (pid == 0)
    {
        /* Child process */
        if (execve(args[0], args, environ) == -1)
        {
            /* If execve fails, print "command not found" */
            fprintf(stderr, "Error: %s: command not found\n", args[0]);
            exit(EXIT_FAILURE);
        }
    }
    else if (pid < 0)
    {
        /* Fork failed */
        perror("Error");
    }
    else
    {
        /* Parent process */
        waitpid(pid, &status, 0);
    }

    return 1;
}
