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
    char *path;
    char *token;
    char *tmp;
    char *delim = ":";

    if (command == NULL)
        return NULL;

    /* Get the PATH environment variable */
    path = getenv("PATH");
    if (path == NULL)
        return NULL;

    /* Create a copy of PATH to tokenize */
    tmp = strdup(path);
    if (tmp == NULL)
        return NULL;

    /* Tokenize the PATH variable to search for the command */
    token = strtok(tmp, delim);
    while (token != NULL)
    {
        /* Construct the full path to the command */
        char *full_path = malloc(strlen(token) + strlen(command) + 2);
        if (full_path == NULL)
        {
            free(tmp);
            return NULL;
        }

        strcpy(full_path, token);
        strcat(full_path, "/");
        strcat(full_path, command);

        /* Check if the command exists at the constructed path */
        if (access(full_path, F_OK) == 0)
        {
            free(tmp);
            return full_path;
        }

        free(full_path);
        token = strtok(NULL, delim);
    }

    free(tmp);
    return NULL; /* Command not found */
}
