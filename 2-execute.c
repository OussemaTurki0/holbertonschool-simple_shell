#include "4-shell.h"

int execute_command(char **args)
{
    /* Check if the command is empty */
    if (args[0] == NULL) 
    {
        return 1;  /* Return 1 to continue the shell loop */
    }

    /* Check if the command is the exit command */
    if (str(args[0], "exit") == 0) 
    {
        return 0;  /* Return 0 to exit the shell */
    }

    /* Fork a new process */
    pid_t pid = fork();
    if (pid == 0) 
    {
        /* Child process */
        /* Execute the command */
        if (exe(args[0], args) == -1) 
        {
            error("shell");
        }
        exit(EXIT_FAILURE);
    }
    else if (pid < 0) 
    {
        /* Error forking */
        perror("shell");
    } else {
        /* Parent process */
        /* Wait for the child process to finish */
        wait(NULL);
    }

    return 1;  /* Return 1 to continue the shell loop */
}
