#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
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
        full_path = malloc(strlen(token) + strlen(cmd) + 2);
        if (full_path == NULL)
        {
            free(temporary);
            return (NULL);
        }

        strcpy(full_path, token);
        strcat(full_path, "/");
        strcat(full_path, cmd);

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