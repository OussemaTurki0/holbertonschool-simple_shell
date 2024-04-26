#include "4-shell.h"

/**
 * split_line - Split a line into tokens
 * @line: The line to split
 *
 * Return: Array of tokens
 */
char **split_line(char *line)
{
	int bufsize = BUFFER_SIZE, position = 0;
	char *token;
	char **tokens = malloc(bufsize * sizeof(char *)); /* Allocate memory for tokens array */

	if (!tokens) /* Check if memory allocation failed */
	{
		handle_error(); /* Call handle_error function */
	}

	token = strtok(line, " \t\r\n\a"); /* Get the first token from the line */
	while (token != NULL)
	{
		tokens[position] = token; /* Store the token in the tokens array */
		position++; /* Move to the next position in the tokens array */

		if (position >= bufsize) /* Check if the tokens array needs to be resized */
		{
			bufsize += BUFFER_SIZE; /* Increase the buffer size */
			tokens = realloc(tokens, bufsize * sizeof(char *)); /* Resize the tokens array */
			if (!tokens) /* Check if realloc failed */
			{
				handle_error(); /* Call handle_error function */
			}
		}

		token = strtok(NULL, " \t\r\n\a"); /* Get the next token from the line */
	}
	tokens[position] = NULL; /* Set the last element of the tokens array to NULL */
	return tokens; /* Return the tokens array */
}
