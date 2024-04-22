#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
