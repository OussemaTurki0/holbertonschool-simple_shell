#include <stdio.h>
#include "4-shell.h"

/**
 * read_line - Read a line of input from standard input (interactive mode).
 *
 * Return: A dynamically allocated string containing the input line,
 *         or NULL if end of file (Ctrl+D) or error occurs.
 */
char *read_line(void)
{
	char *l = NULL;
	size_t bf_sz = 0;

	/* Read a line of input from standard input */
	if (getline(&l, &bf_sz, stdin) == -1)
	{
		if (EOF(stdin))
		{
			free(l);
			return (NULL);
		}
		else
		{
			perror("Cannot read line");
			exit(EXIT_FAILURE);
		}
	}
	return (l);
}

/**
 * read_line_from_file - Read a line of input from
 * a file (non-interactive mode).
 * @f: Pointer to the file from which to read input.
 *
 * Return: A dynamically allocated string containing the input line,
 * or NULL if end of file or error occurs.
 */
char *read_line_from_file(FILE *f)
{
	char *l;
	size_t bf_sz = 0;

	if (getline(&l, &bf_sz, f) == -1)
	{
		if (EOF(f))
		{
			free(l);
			return (NULL);
		}
		else
		{
			perror("Cannot read line from file");
			exit(EXIT_FAILURE);
		}
	}
	return (l);
}

