#include "4-shell.h"

/**
 * shell_exit - Builtin command: exit
 *
 * Return: 0 to exit the shell
 */
int shell_exit(void)
{
	exit(EXIT_SUCCESS); /* Call exit to terminate the program */
}

/**
 * shell_pwd - Builtin command: pwd
 *
 * Return: 1 if successful, 0 otherwise
 */
int shell_pwd(void)
{
	char cwd[PATH_MAX];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		printf("%s\n", cwd);
		return (1);
	}
	else
	{
		perror("getcwd() error");
		return (0);
	}
}
/**
 * shell_env - Builtin command: env
 *
 * Return: 1 if successful, 0 otherwise
 */
int shell_env(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (1);
}

/**
 * is_builtin - Check if a command is a builtin
 * @cmd: The command to check
 *
 * Return: 1 if builtin, 0 otherwise
 */
int is_builtin(char *cmd)
{
	return ((strcmp(cmd, "exit") == 0 || strcmp(cmd, "pwd") == 0
	|| strcmp(cmd, "env") == 0));
}
/**
 * handle_error - Print error message and exit
 */
void handle_error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

