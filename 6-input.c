#include <stdio.h>
#include <stdlib.h>
#include "4-shell.h"

/**
 * read_line - Read a line of input from standard input (interactive mode).
 *
 * Return: A dynamically allocated str containing the input line,
 *         or NULL if end of file (Ctrl+D) or error occurs.
 */
char *read_line(void)
{
    char *line = NULL;
    size_t bufsize = 0;

    /* Read a line of input from standard input */
    if (getline(&line, &bufsize, stdin) == -1)
    {
        if (feof(stdin))
        {
            free(line);
            return (NULL);
        }
        else
        {
            perror("Cannot read line");
            exit(EXIT_FAILURE);
        }
    }
    return (line);
}

/**
 * read_line_from_file - Read a line of input from
 * a file (non-interactive mode).
 * @file: Pointer to the file from which to read input.
 *
 * Return: A dynamically allocated str containing the input line,
 * or NULL if end of file or error occurs.
 */
char *read_line_from_file(FILE *file)
{
    char *line = NULL;
    size_t bufsize = 0;

    if (getline(&line, &bufsize, file) == -1)
    {
        if (feof(file))
        {
            free(line);
            return (NULL);
        }
        else
        {
            perror("Cannot read line from file");
            exit(EXIT_FAILURE);
        }
    }
    return (line);
}
