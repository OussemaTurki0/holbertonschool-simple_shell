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
path = getenv("PATH");     /* Get the PATH environment variable */
if (path == NULL)
return (NULL);
temporary = strdup(path);     /* Create a copy of PATH to tokenize */
if (temporary == NULL)
return (NULL);
/* Tokenize the PATH variable to search for the command */
token = strtok(temporary, delim); /* Tokenize the PATH variable */
while (token != NULL)
{
len = strlen(token) + strlen(cmd) + 2; /* Construct the full path */
full_path = malloc(len);
if (full_path == NULL)
{
free(temporary);
return (NULL);
}
if (access(full_path, F_OK) == 0) /* Check the command exists at the path */
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
