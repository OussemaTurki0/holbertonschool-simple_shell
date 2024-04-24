#include "4-shell.h"

/**
 * read_line - Read a line of input from stdin
 *
 * Return: The line read from stdin
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t getline_return;

	if (is_interactive())
	{
		display_prompt();
	}
	getline_return = getline(&line, &bufsize, stdin);
	if (getline_return == -1)
	{
		if (feof(stdin))
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			handle_error();
		}
	}
	return (line);
}
