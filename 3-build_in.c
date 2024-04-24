#include "4-shell.h"

/**
 * shell_exit - Builtin command: exit
 *
 * Return: 0 to exit the shell
 */
int shell_exit(void)
{
	return (0); /* Return 0 to indicate exit */
}

/**
 * shell_cd - Builtin command: cd
 * @args: Array of command arguments
 *
 * Return: 1 if successful, 0 otherwise
 */
int shell_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "hsh: expected argument to \"cd\"\n");
		return (1);
	}
	if (chdir(args[1]) != 0)
	{
		perror("hsh");
	}
	return (1);
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
	return ((strcmp(cmd, "exit") == 0 || strcmp(cmd, "cd") == 0
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

