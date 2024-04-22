#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "4-shell.h"

/**
 * shell_exit - Handles the exit command.
 * @args: Array of command arg.
 * Return: 0 to indicate the shell should exit.
 */
int shell_exit(__attribute__((unused)) char **args)
{

	return (0); /* Return 0 to exit the shell */
}

/**
 * shell_env - Handles the env command.
 * @args: Array of command arg.
 * Return: 1 to continue the shell loop.
 */
int shell_env(__attribute__((unused)) char **args)
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
 * shell_cd - Change the current working directory.
 * @args: Array of command arguments
 * (should contain the directory to change to).
 * Return: 1 on success, -1 on failure.
 */
int shell_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "Usage: cd <directory>\n");
		return (-1);
	}
	if (chdir(args[1]) != 0)
	{
		perror("cd");
		return (-1);
	}
	return (1);
}

/**
 * handle_built_in - Handles built-in commands.
 * @args: Array of command arg.
 * @status: Pointer to the status variable.
 * Return: 1 if handled as built-in, 0 otherwise.
 */
int handle_built_in(char **args, __attribute__((unused)) int *status)
{
	buildin cmds[] = {
		{"exit", shell_exit},
		{"env", shell_env},
		{"cd", shell_cd},
		{NULL, NULL}}; /* Null terminator */

	int i;

	if (args[0] == NULL) /* Check if the command is empty */
	{
		return (1);
	}
	/* Loop through the built-in commands */
	for (i = 0; cmds[i].name != NULL; i++)
	{
		printf("Comparing: %s\n", args[0]);
		printf("With: %s\n", cmds[i].name);
		/* If command matches a built-in command, execute it */
		if (strcmp(args[0], cmds[i].name) == 0)
		{
			printf("Match found: %s\n", args[0]);
			return (cmds[i].function(args));
		}
	}
	/* If command not recognized, print error */
	print_error("simple shell", args[0]);
	return (0);
}
