#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "4-shell.h"

void print_error(char *program_name, char *command)
{
    fprintf(stderr, "Error: %s: %s: command not found\n",
            program_name, command);
}

void handle_interactive_mode(void)
{
    int i;
    char **args;
    char *line;
    int status;

    do
    {
        display_prompt();
        line = read_line();

        if (line == NULL)
        {
            if (isatty(STDIN_FILENO))
            {
                printf("\n");
            }
            return;
        }
        args = tokenizer(line);

        status = execute_command(args);
        free(line);
        for (i = 0; args[i] != NULL; i++)
        {
            free(args[i]);
        }
        free(args);
    } while (status);
}

void handle_non_interactive_mode(void)
{
    char *line;
    char **args;
    int status;

    line = read_line_from_file(stdin);
    if (line != NULL)
    {
        args = tokenizer(line);
        if (args != NULL)
        {
            status = execute_command(args);
            if (status == -1)
            {
                print_error("shell", args[0]);
            }
            for (i = 0; args[i] != NULL; i++)
            {
                free(args[i]);
            }
            free(args);
            free(line);
            return;
        }
        else
        {
            fprintf(stderr, "Error: Unable to read input.\n");
            exit(1);
        }
    }
}

int main(void)
{
    if (isatty(STDIN_FILENO))
    {
        handle_interactive_mode();
    }
    else
    {
        handle_non_interactive_mode();
    }

    return 0;
}
