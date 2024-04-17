#include <stdio.h>
#include <stdlib.h>
#include "4-shell.h"

/**
 * main - Entry point of the simple shell program.
 *
 * Return: 0 on success, non-zero on failure.
 */
int main(void)
{
	char **args;
	char *line;
	int status;

	/* Handle interactive mode */
	if (isatty(STDIN_FILENO))
	{
		do {
			display_prompt();	/* Display the shell prompt */
			line = read_line(); /* Read a line of input from the user */
			if (line == NULL)
			{
				if (isatty(STDIN_FILENO))
				{
					printf("\n"); /* Print a newline if Ctrl+D is pressed */
				}
				return (0); /* Exit the program */
			}
			status = execute_command(line); /* Execute the command */
			free(line);						/* Free the allocated memory for the input line */
	} while (status);		/* Continue the loop if status is not 0 (exit command) */
	}

	/* Handle non-interactive mode */
	else
	{
		line = read_line_from_file(stdin); /* Read a line of input from stdin */
		if (line != NULL)
		{
			args = parse_line(line); /* Execute the command based on the arguments */
			status = execute_command(line); /* Execute the command */
			free(line);						/* Free the allocated memory for the input line */
			return (status);				/* Return the status */
		}
		else
		{
			fprintf(stderr, "Error: Unable to read input.\n");
			return (1); /* Return non-zero status on failure */
		}
	}

	return (0); /* Exit the program with status 0 on success */
}
