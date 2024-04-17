#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "4-shell.h"

/**
 * shell_exit - Handles the exit command.
 * @args: Array of command arguments.
 * Return: 0 to indicate the shell should exit.
 */

int shell_exit(char **args)
{
	return (0); /* Return 0 to exit the shell */
}

/**
 * shell_env - Handles the env command.
 * @args: Array of command arguments.
 * Return: 1 to continue the shell loop.
 */

int shell_env(char **args)
{
	/* Print the current environment */
	for (char **env = envi00; *env != NULL; env++)

	{
		printf("%s\n", *env);
	}
	return (1); /* Return 1 to continue the shell loop */
}

/**
 * handle_built_in - Handles built-in commands.
 * @args: Array of command arguments.
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
	return (0);
}
