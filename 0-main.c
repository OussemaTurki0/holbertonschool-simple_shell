#include "4-shell.h"

/**
 * main - Entry point of the shell
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(void)
{
    char *line;
    char **args;
    int status;

    do
    {
        line = read_line();
        args = split_line(line);
        status = execute(args);

        free(line);
        free_args(args);
    } while (status);

    return (EXIT_SUCCESS);
}

/**
 * is_interactive - Check if the shell is running in interactive mode
 *
 * Return: 1 if interactive, 0 otherwise
 */
int is_interactive(void)
{
    return (isatty(STDIN_FILENO));
}
