#include "4-shell.h"

/**
 * interactive_shell - Run the shell in interactive mode.
 */
void interactive_shell(void)
{
	char *line;
	char **args;
	int status;

	do {
		display_prompt();   /* Display the shell prompt */
		line = read_line(); /* Read input line */
		if (line == NULL)
		{
			printf("\n");
			break;  /* Exit loop on Ctrl+D (EOF) */
		}

		args = split_line(line); /* Split input line into arguments */

		if (args != NULL)
		{
			status = execute(args); /* Execute command */

			free_args(args); /* Free memory */
		}
/* Ensure the shell waits for user input after execution */
		if (status)
			printf("\n");

	} while (1);
}

/**
 * non_interactive_shell - Run the shell in non-interactive mode.
 */
void non_interactive_shell(void)
{
	char *line;
	char **args;

	while ((line = read_line()) != NULL)
	{
		args = split_line(line);
		if (args != NULL)
		{
			execute(args);
			free_args(args); /* Free memory */
		}
	}
}

/**
 * main - Entry point of the shell.
 * Return: success.
 */
int main(void)
{
	if (isatty(STDIN_FILENO))
	{
        /* Interactive mode */
		run_interactive_shell();
	}
	else
	{
        /* Non-interactive mode */
		run_non_interactive_shell();
	}

	return (EXIT_SUCCESS);
}

