#include "4-shell.h"

/**
 * get_command_path - Retrieve the full path of a command.
 * @command: The command name.
 *
 * Return: The full path of the command, or NULL if not found.
 */

char *get_command_path(const char *command)
{
char *gpath; /* Pointer to store each path directory */
char *envr; /* Pointer to store the value of the PATH environment variable */
char *cmmd; /* Pointer to store the constructed command path */
char delim[] = ":"; /* Delimiter used to separate path directories */

	if (command) /* Check if command is not NULL */
	/* Return command if it exists */
		return (access(command, F_OK) == 0 ? strdup(command) : NULL);

	envr = _getenv("PATH");
	if (!envr) /* If PATH is not set, return NULL */
		return (NULL);
	gpath = strtok(envr, delim); /* Get the first path directory */
}
