#include "4-shell.h"

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
    cmd_path = get_command_path(args[0]);
    if (cmd_path == NULL)
    {
        fprintf(stderr, "hsh: command not found: %s\n", args[0]);
        return (1);
    }

    pid = fork();
    if (pid == 0)
    {
        if (execvp(args[0], args) == -1)
        {
            handle_error();
        }
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        handle_error();
    }
    else
    {
        do
        {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return (1);
}

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
        return (shell_exit());
    }
    else if (strcmp(args[0], "env") == 0)
    {
        return (shell_env());
    }
    else if (strcmp(args[0], "cd") == 0)
    {
        return (shell_cd(args));
    }
    return (0); /* Not a builtin command */
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
    while (args[i] != NULL)
    {
        free(args[i]);
        i++;
    }
    free(args);
}
