#include "4-shell.h"

/**
* is_path - Checks if the command is an absolute path.
* @cmd: The command to check.
* Return: 1 if it is an absolute path, 0 otherwise.
*/
int is_path(const char *cmd)
{
int i; /* Counter for iterating through the command string */
/* Iterate through the command string until finding a '/' */
for (i = 0; cmd[i] != '/'; i++)
{
if (cmd[i] == '\0')
return (0);
}
return (1); /* Return 1 if a '/' was found */
}

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
		i++;							/* Move to the next environment variable */
	}
	return (NULL); /* Return NULL if no match found */
}

/**
 * get_command_path - Retrieve the full path of a command.
 * @command: The command name.
 *
 * Return: The full path of the command, or NULL if not found.
 */

char *get_command_path(const char *command)
{
	char *gpath;		/* Pointer to store each path directory */
	char *envr;		/* Pointer to store the value of the PATH environment variable */
	char *cmmd;			/* Pointer to store the constructed command path */
	char delim[] = ":"; /* Delimiter used to separate path directories */

	if (command) /* Check if command is not NULL */
				 /* Return command if it exists */
		return (access(command, F_OK) == 0 ? strdup(command) : NULL);

	envr = _getenv("PATH");
	if (!envr) /* If PATH is not set, return NULL */
		return (NULL);
	gpath = strtok(envr, delim); /* Get the first path directory */
	while (gpath)				 /* Loop through each path directory */
	{
		cmmd = malloc(strlen(gpath) + strlen(command) + 2);
		if (!cmmd) /* Check if memory allocation failed */
		{
			free(envr);	   /* Free memory allocated for envr */
			return (NULL); /* Return NULL */
		}
		snprintf(cmmd, strlen(gpath) + strlen(command) + 2, "%s/%s", gpath, command);
		if (access(cmmd, F_OK) == 0)
		{
			free(envr);	   /* Free memory allocated for envr */
			return (cmmd); /* Return the constructed command path */
		}

		free(cmmd);
		gpath = strtok(NULL, delim); /* Get the next path directory */
	}
	free(envr);
	return (NULL); /* Return NULL if command not found */
}

