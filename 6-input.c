#include "4-shell.h"

/**
 * read_line - Read a line of input from stdin
 *
 * Return: The line read from stdin
 */
/**
 * read_line - Read a line of input from stdin
 *
 * Return: The line read from stdin, or NULL on EOF or error
 */
char *read_line(void)
{
    char *line = NULL;
    size_t bufsize = 0;
    ssize_t get_line;

    get_line = getline(&line, &bufsize, stdin);
    if (get_line == -1)
    {
        if (feof(stdin))
        {
            free(line); /* Free the memory allocated for line */
            return NULL; /* Return NULL to indicate EOF */
        }
        else
        {
            perror("getline error"); /* Print an error message */
            free(line); /* Free the memory allocated for line */
            exit(EXIT_FAILURE); /* Exit the program with failure status */
        }
    }
    return line; /* Return the line read from stdin */
}
