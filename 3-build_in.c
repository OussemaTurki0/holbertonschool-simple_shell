#define _GNU_SOURCE /* Define _GNU_SOURCE before including headers to enable GNU extensions */
#include <stdio.h> /* Include standard input/output header */
#include <stdlib.h> /* Include standard library header */
#include <unistd.h> /* Include POSIX operating system API header */
#include <string.h> /* Include string manipulation functions header */
#include <limits.h> /* Include limits.h for PATH_MAX constant */
#include "4-shell.h" /* Include custom header file */

/**
 * shell_exit - Builtin command: exit
 *
 * Return: 0 to exit the shell
 */
int shell_exit(void)
{
    exit(EXIT_SUCCESS); /* Call exit to terminate the program with success status */
}

/**
 * shell_pwd - Builtin command: pwd
 *
 * Return: 1 if successful, 0 otherwise
 */
int shell_pwd(void)
{
    char cwd[PATH_MAX]; /* Declare a character array to store the current working directory */

    if (getcwd(cwd, sizeof(cwd)) != NULL) /* Get the current working directory and check for success */
    {
        printf("%s\n", cwd); /* Print the current working directory */
        return (1); /* Return 1 to indicate success */
    }
    else
    {
        perror("getcwd() error"); /* Print an error message if getcwd fails */
        return (0); /* Return 0 to indicate failure */
    }
}

/**
 * shell_env - Builtin command: env
 *
 * Return: 1 if successful, 0 otherwise
 */
int shell_env(void)
{
    int i = 0; /* Initialize a counter variable */

    while (environ[i]) /* Loop through each environment variable */
    {
        printf("%s\n", environ[i]); /* Print the current environment variable */
        i++; /* Increment the counter */
    }
    return (1); /* Return 1 to indicate success */
}

/**
 * is_builtin - Check if a command is a builtin
 * @cmd: The command to check
 *
 * Return: 1 if builtin, 0 otherwise
 */
int is_builtin(char *cmd)
{
    return ((strcmp(cmd, "exit") == 0 || strcmp(cmd, "pwd") == 0 /* Check if the command is "exit", "pwd", or "env" */
             || strcmp(cmd, "env") == 0));
}

/**
 * handle_error - Print error message and exit
 */
void handle_error(void)
{
    perror("Error"); /* Print an error message */
    exit(EXIT_FAILURE); /* Call exit to terminate the program with failure status */
}
