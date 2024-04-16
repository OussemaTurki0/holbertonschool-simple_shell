#include "shell.h"

/**
 * 
 * 
 * 
 * 
 */


int main(void)
{
    char *line;
    char **args;
    int status;

    /* Start the main shell loop */
    do {

        display_prompt(); /* Read a line of input from the user */
        line = read_line(); /* Parse(analyze) the input line into arguments */
        args = parse_line(line); /* Execute the command based on the arguments */
        status = execute_command(args);

        /* Free the allocated memory for the line and arguments */
        free(line); 
        free(args);
    } while (status);  /* Continue the loop if status is not 0 (exit command) */

    return 0;
}
