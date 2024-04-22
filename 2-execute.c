#include <unistd.h>
#include "4-shell.h"

/**
 * get_command_path - Retrieve the full path of a command.
 * @command: The command name.
 *
 * Return: The full path of the command, or NULL if not found.
 */

char *get_command_path(const char *command)
{
	char *directory_path, *current, *cmd_path;
	char *path = getenv("PATH");

	if (!path || !command)
		return (NULL);
	current = strtok(path, ":");
	while (current != NULL)
	{
		directory_path = strdup(current);
		if (directory_path == NULL)
			return (NULL);

		cmd_path = malloc(strlen(directory_path) + strlen(command) + 2);
		if (cmd_path == NULL)
		{
			free(directory_path);
			return (NULL);
		}
		strcpy(cmd_path, directory_path);
		strcat(cmd_path, "/");
		strcat(cmd_path, command);

		if (access(cmd_path, X_OK) == 0)
		{
			free(directory_path);
			return (cmd_path);
		}
		free(directory_path);
		free(cmd_path);
		current = strtok(NULL, ":");
	}
	return (NULL); /* Command not found in any directory in PATH */
}

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

	if (args[0] == NULL)     /* Check if the command is empty */
	{
		return (1); /* Return 1 to continue the shell loop */
	}
	if (handle_built_in(args, &status))
	{
		return (status);
	}
	if (strcmp(args[0], "exit") == 0) /* Checking the exit command */
	{
		status = 0;
		return (0); /* Return 0 to exit the shell */
	}
	path = get_command_path(args[0]);
	if (path == NULL)
	{
		fprintf(stderr, "%s: command not found\n", args[0]);
		return (1); /* Continue the shell loop */
	}
	pid = fork();       /* Fork a new process */

	if (pid == 0)
	{
		if (execve(path, args, environ) == -1)      /* Execute the command */
		{
			perror("Error");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("Error");    /* Error forking */
	}
	else
	{
		waitpid(pid, &status, 0);     /* Wait for the child process to finish */
	}
	free(path);
	return (1); /* Return 1 to continue the shell loop */
}

