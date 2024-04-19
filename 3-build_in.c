#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "4-shell.h"

/**
 * shell_exit - Handles the exit command.
 * @args: Array of command arg.
 * Return: 0 to indicate the shell should exit.
 */
int shell_exit(char **args)
{
    return (0); /* Return 0 to exit the shell */
}

/**
 * shell_env - Handles the env command.
 * @args: Array of command arg.
 * Return: 1 to continue the shell loop.
 */
int shell_env(char **args)
{
    char **env;
    /* Print the current envir */
    for (env = environ; *env != NULL; env++)
    {
        printf("%s\n", *env);
    }
    return (1); /* Return 1 to continue the shell loop */
}

/**
 * shell_echo - Handles the echo built-in command.
 * @args: Array of command arg.
 */
void shell_echo(char **args)
{
    int i;
    /* Print each arg */
    for (i = 1; args[i] != NULL; i++)
    {
        printf("%s ", args[i]);
    }
    printf("\n"); /* Print newline after printing all arg */
}

/**
 * handle_built_in - Handles built-in commands.
 * @args: Array of command arg.
 * @status: Pointer to the status variable.
 * Return: 1 if handled as built-in, 0 otherwise.
 */
int handle_built_in(char **args, int *status)
{
    if (args[0] == NULL) /* Check if the command is empty */
    {
        return (1); /* Return 1 to indicate the command was handled */
    }
    /* Implement logic to handle built-in commands */
    if (strcmp(args[0], "exit") == 0)
    {
        shell_exit(args); /* Handle the exit command */
        return (1);
    }
    else if (strcmp(args[0], "env") == 0)
    {
        shell_env(args); /* Handle the env command */
        return (1);
    }
    if (strcmp(args[0], "echo") == 0)
    {
        shell_echo(args);   /* Handle the echo command */
        return (1);
    }
    print_error(args[0]); /* Print error for unrecognized command */
    return (0);
}

/**
 * print_error - Prints an error message for unrecognized commands.
 * @command: The unrecognized command.
 */
void print_error(char *command)
{
    printf("Error: %s: command not found\n", command);
}
