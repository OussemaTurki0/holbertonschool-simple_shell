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
	fprintf(stderr, "Error: %s: %s: command not found\n", program_name, command);
}

/**
 * main - Entry point of the simple shell program.
 *Handle non-or-interactive mode: shell should be able to read commands from a file and execute them, rather than relying on user input from the terminal.
 * Return: 0 on success, non-zero on failure.
 */

int main(void)
{
    char *line;
    char **args;
    int status;

    do
    {
        display_prompt();        /* Display the shell prompt */
        line = read_line();      /* Read a line of input from the user */
        if (line == NULL)        /* Check for end-of-file (Ctrl+D) */
        {
            printf("\n");        /* Print a newline if Ctrl+D is pressed */
            break;              /* Exit the loop */
        }
        args = tokenizer(line); /* Tokenize the input line */
        if (args == NULL)       /* Check for tokenization error */
        {
            fprintf(stderr, "Error: Unable to tokenize input.\n");
            continue;           /* Skip to the next iteration */
        }

        /* Check for the exit command */
        if (strcmp(args[0], "exit") == 0)
        {
            free(line);         /* Free the allocated memory for the input line */
            free(args);         /* Free the allocated memory for the args array */
            break;              /* Exit the loop */
        }

        status = execute_command(args); /* Execute the command */
        free(line);             /* Free the allocated memory for the input line */
        /* Free the memory allocated for each argument */
        for (int i = 0; args[i] != NULL; i++)
        {
            free(args[i]);
        }
        free(args);             /* Free the allocated memory for the args array */
    } while (1);                /* Continue the loop indefinitely */

    return (0);                 /* Exit the program */
}
