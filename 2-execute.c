#include "4-shell.h" /* Include the custom shell header file */

/**
 * execute_builtin - Execute a builtin command
 * @args: Array of command arguments
 *
 * Return: 1 if successful, 0 otherwise
 */
int execute_builtin(char **args)
{
    if (strcmp(args[0], "exit") == 0) /* Check if the command is "exit" */
    {
        shell_exit(); /* Call the shell_exit function */
        return (0); /* Return 0 to indicate successful execution */
    }
    else if (strcmp(args[0], "env") == 0) /* Check if the command is "env" */
    {
        return (shell_env()); /* Call the shell_env function and return its result */
    }
    else if (strcmp(args[0], "pwd") == 0) /* Check if the command is "pwd" */
    {
        return (shell_pwd()); /* Call the shell_pwd function and return its result */
    }
    return (0); /* Not a builtin command */
}

/**
 * execute - Execute a command
 * @args: Array of command arguments
 *
 * Return: 1 if successful, 0 otherwise
 */
int execute(char **args)
{
    char *cmd_path; /* Declare a variable to store the full path of the command */
    pid_t pid; /* Declare a variable to store the process ID */
    int status; /* Declare a variable to store the status of the child process */

    if (args[0] == NULL) /* Check if the command is empty */
    {
        return (1); /* Empty command */
    }

    if (is_builtin(args[0])) /* Check if the command is a builtin */
    {
        return (execute_builtin(args)); /* Call the execute_builtin function and return its result */
    }

    /* Check if command is 'ls' */
    if (strcmp(args[0], "ls") == 0) /* Check if the command is "ls" */
    {
        args[0] = "/bin/ls"; /* Update the command path */
    }

    /* Get the full path of the command */
    cmd_path = get_command_path(args[0]); /* Get the full path of the command */
    if (cmd_path == NULL) /* Check if the command path is valid */
    {
        fprintf(stderr, "hsh: command not found: %s\n", args[0]); /* Print an error message */
        return (1); /* Return 1 to indicate failure */
    }

    /* Fork a new process to execute the command */
    pid = fork(); /* Fork a new process */
    if (pid == 0) /* Check if it's the child process */
    {
        /* Child process */
        if (execve(cmd_path, args, environ) == -1) /* Execute the command */
        {
            perror("execve"); /* Print an error message if execve fails */
            exit(EXIT_FAILURE); /* Terminate the child process with failure status */
        }
    }
    else if (pid < 0) /* Check if there was an error forking the process */
    {
        /* Error forking process */
        perror("fork"); /* Print an error message */
        free(cmd_path); /* Free the command path */
        return (1); /* Return 1 to indicate failure */
    }
    else
    {
        /* Parent process */
        do
        {
            /* Wait for child process to complete */
            waitpid(pid, &status, WUNTRACED); /* Wait for the child process to complete */
        } while (!WIFEXITED(status) && !WIFSIGNALED(status)); /* Continue waiting until the child process exits or is signaled */
    }

    free(cmd_path); /* Free the command path */
    return (1); /* Return 1 to indicate successful execution */
}

/**
 * free_args - Free memory allocated for an array of strings.
 * @args: Array of strings to free.
 *
 * Description: This function frees each string in the array @args
 *              and then frees the array itself.
 */
void free_args(char **args)
{
    int i = 0; /* Initialize a counter variable */

    while (args[i]) /* Loop through each string in the array */
    {
        free(args[i]); /* Free the current string */
        i++; /* Move to the next string */
    }
    free(args); /* Free the array itself */
}
