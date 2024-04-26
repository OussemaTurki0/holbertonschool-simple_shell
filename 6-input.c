#include "4-shell.h"

/**
 * read_line - Read a line of input from stdin
 *
 * Return: The line read from stdin
 */
char *read_line(void)
{
	char *line = NULL; /* Initialize line to NULL */
	size_t bufsize = 0; /* Initialize bufsize to 0 */
	ssize_t get_line; /* Variable to store the return value of getline */

	get_line = getline(&line, &bufsize, stdin); /* Read a line from stdin */
	if (get_line == -1) /* Check if getline failed */
	{
		if (feof(stdin)) /* Check if end-of-file was reached */
		{
			printf("\n"); /* Print a newline character */
			exit(EXIT_SUCCESS); /* Exit the program with success status */
		}
		else
		{
			handle_error(); /* Call handle_error function */
		}
	}
	return line; /* Return the line read from stdin */
}
