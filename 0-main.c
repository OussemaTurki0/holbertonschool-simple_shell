#include <stdio.h>
#include <stdlib.h>
#include "4-shell.h"

/**
 * print_error - Prints an error message for unrecognized commands.
 * @program_name: The name of the program (shell).
 * @command: The unrecognized command.
 */
void print_error(char *program_name, char *command)
{
	fprintf(stderr, "Error: %s: %s: command not found\n", program_name, command);
}

/**
 * main - Entry point of the simple shell program.
 *Handle non-or-interactive mode: shell should be able to read commands from a file and execute them, rather than relying on user input from the terminal.
 * Return: 0 on success, non-zero on failure.
 */

int main(void)
{
	int i;
	char **args;
	char *line;
	int status;

	/* Handle interactive mode */
	if (isatty(STDIN_FILENO))
	{
		do
		{
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
			args = tokenizer(line);			/* Tokenize the input line */
			status = execute_command(args); /* Execute the command */
			free(line);						/* Free the allocated memory for the input line */
			/* Free the memory allocated for each argument */
			for (i = 0; args[i] != NULL; i++)
			{
				free(args[i]);
			}
			free(args);	  /* Free the allocated memory for the args array */
		} while (status); /* Continue the loop if status is not 0 (exit command) */
	}

	/* Handle non-interactive mode */
	else
	{
		line = read_line_from_file(stdin); /* Read a line of input from stdin */
		if (line != NULL)
		{
			args = tokenizer(line); /* tokenize the input line into arguments */
			if (args != NULL)
			{
				status = execute_command(args); /* Execute the command */
				if (status == -1)
				{
					print_error("shell", args[0]); /* Execute the command */
				}
				/* Free the memory allocated for each argument */
				for (i = 0; args[i] != NULL; i++)
				{
					free(args[i]);
				}
				/* Free the memory allocated for the args array itself */
				free(args);
				free(line);		 /* Free the allocated memory for the input line */
				return (status); /* Return the status */
			}
			else
			{
				fprintf(stderr, "Error: Unable to read input.\n");
				return (1); /* Return non-zero status on failure */
			}
		}

		return (0); /* Exit the program with status 0 on success */
	}
}
