#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "4-shell.h"

/**
 * print_error - Prints an error message for unrecognized commands.
 * @program_name: The name of the program (shell).
 * @command: The unrecognized command.
 */
void print_error(char *program_name, char *command)
{
	fprintf(stderr, "Error: %s: %s: command not found\n",
		program_name, command);
}

/**
 * handle_interactive_mode - Handles interactive mode of the shell.
 */
void handle_interactive_mode(void)
{
	int i;
	char **args;
	char *line;
	int status;

	do {
		display_prompt();               /* Display the shell prompt */
		line = read_line();             /* Read a line of input from the user */

		if (line == NULL) {
			if (isatty(STDIN_FILENO)) {
				printf("\n");           /* Print a newline if Ctrl+D is pressed */
			}
			return;                     /* Exit the function */
		}
		args = tokenizer(line);         /* Tokenize the input line */

		status = execute_command(args); /* Execute the command */
		free(line);                     /* Free the allocated memory for the input line */
		/* Free the memory allocated for each argument */
		for (i = 0; args[i] != NULL; i++) {
			free(args[i]);
		}
		free(args);                     /* Free the allocated memory for the args array */
	} while (status);                   /* Continue the loop if status is not 0 (exit command) */
}

/**
 * handle_non_interactive_mode - Handles non-interactive mode of the shell.
 */
void handle_non_interactive_mode(void)
{
	char *line;
	char **args;
	int status;

	line = read_line_from_file(stdin); /* Read a line of input from stdin */
	if (line != NULL) {
		args = tokenizer(line);         /* Tokenize the input line into arguments */
		if (args != NULL) {
			status = execute_command(args); /* Execute the command */
			if (status == -1) {
				print_error("shell", args[0]); /* Print an error message */
			}
			/* Free the memory allocated for each argument */
			for (int i = 0; args[i] != NULL; i++) {
				free(args[i]);
			}
			/* Free the memory allocated for the args array itself */
			free(args);
			free(line);                 /* Free the allocated memory for the input line */
			return;                     /* Exit the function */
		} else {
			fprintf(stderr, "Error: Unable to read input.\n");
			exit(1);                    /* Exit the program with non-zero status */
		}
	}
}

/**
 * main - Entry point of the simple shell program.
 * Handle non-interactive mode: shell should be able to read commands from a file and execute them, rather than relying on user input from the terminal.
 * Return: 0 on success, non-zero on failure.
 */
int main(void)
{
	if (isatty(STDIN_FILENO)) {
		handle_interactive_mode();  /* Handle interactive mode */
	} else {
		handle_non_interactive_mode(); /* Handle non-interactive mode */
	}

	return 0;   /* Exit the program with status 0 on success */
}
