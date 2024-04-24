#include "4-shell.h"

/**
 * get_command_path - Retrieve the full path of a command.
 * @cmd: The command name.
 *
 * Return: The full path of the command, or NULL if not found.
 */
char *get_command_path(const char *cmd)
{
	char *full_path;
    char *path;
    char *token;
    char *temporary;
    char *delim = ":";
	size_t len;

    if (cmd == NULL)
        return (NULL);

    /* Get the PATH environment variable */
    path = getenv("PATH");
    if (path == NULL)
        return (NULL);

    /* Create a copy of PATH to tokenize */
    temporary = strdup(path);
    if (temporary == NULL)
        return (NULL);

    /* Tokenize the PATH variable to search for the command */
    token = strtok(temporary, delim);
    while (token != NULL)
    {
        /* Construct the full path to the command */
		len = strlen(token) + strlen(cmd) + 2;
        full_path = malloc(len);
        if (full_path == NULL)
        {
            free(temporary);
            return (NULL);
        }
        snprintf(full_path, len, "%s/%s", token, cmd);
    	printf("Trying path: %s\n", full_path);


        /* Check if the command exists at the constructed path */
        if (access(full_path, F_OK) == 0)
        {
            free(temporary);
            return (full_path);
        }

        free(full_path);
        token = strtok(NULL, delim);
    }

    free(temporary);
    return (NULL); /* Command not found */
}