#include "4-shell.h"

/**
 * execute_builtin - Execute a builtin command
 * @args: Array of command arguments
 *
 * Return: 1 if successful, 0 otherwise
 */
int execute_builtin(char **args)
{
    if (strcmp(args[0], "exit") == 0)
    {
        shell_exit();
        return (0);
    }
    else if (strcmp(args[0], "env") == 0)
    {
        return (shell_env());
    }
    else if (strcmp(args[0], "pwd") == 0)
    {
        return (shell_pwd());
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
    char *cmd_path;
    pid_t pid;
    int status;

    if (args[0] == NULL)
    {
        return (1); /* Empty command */
    }

    if (is_builtin(args[0]))
    {
        return (execute_builtin(args));
    }

    /* Check if command is 'ls' */
    if (strcmp(args[0], "ls") == 0)
    {
    args[0] = "/bin/ls"; /* Update the command path */
    }

    /* Get the full path of the command */
    cmd_path = get_command_path(args[0]);
    if (cmd_path == NULL)
    {
        fprintf(stderr, "hsh: command not found: %s\n", args[0]);
        return (1);
    }

    /* Fork a new process to execute the command */
    pid = fork();
    if (pid == 0)
    {
        /* Child process */
        if (execve(cmd_path, args, environ) == -1)
        {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    }
    else if (pid < 0)
    {
        /* Error forking process */
        perror("fork");
        free(cmd_path);
        return (1);
    }
    else
    {
        /* Parent process */
        do
        {
            /* Wait for child process to complete */
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    free(cmd_path);
    return (1);
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
    int i = 0;

    while (args[i])
    {
        free(args[i]);
        i++;
    }
    free(args);
}
