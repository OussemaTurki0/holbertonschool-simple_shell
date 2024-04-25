#include "4-shell.h"

/**
* _getenv - handling the environment.
* @env_var: the variable to retrieve.
* Return: value of the variable, otherwise NULL.
*/
char *_getenv(const char *env_var)
{
int i = 0;
char *key;
while (environ[i])
{
key = strtok(environ[i], "="); /* Extract key from environment variable */
if (strcmp(env_var, key) == 0)
return (strtok(NULL, "/")); /* Return value if key matches */
i++; /* Move to the next environment variable */
}
}

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
