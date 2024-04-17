#include <unistd.h>
#include "4-shell.h"
/**
 * execute_command - Execute a command.
 * @args: Array of command arguments.
 *
 * Return: 1 to continue the shell loop, 0 to exit the shell.
 */

int execute_command(char **args)
{
	pid_t pid;

	/* Check if the command is empty */
	if (args[0] == NULL)
	{
		return (1); /* Return 1 to continue the shell loop */
	}

	/* Check if the command is the exit command */
	if (strcmp(args[0], "exit") == 0)
	{
		return (0); /* Return 0 to exit the shell */
	}

	/* Fork a new process */
	pid = fork();

	if (pid == 0)
	{
		/* Child process */
		/* Execute the command */
		if (execve(args[0], args, envi00) == -1)
		{
			perror("Error");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		/* Error forking */
		perror("Error");
	}
	else
	{
		/* Parent process */
		/* Wait for the child process to finish */
		wait(NULL);
	}
	return (1); /* Return 1 to continue the shell loop */
}
