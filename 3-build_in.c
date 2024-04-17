#include "4-shell.h"

int shell_exit(char **args)
{
    return 0;  /* Return 0 to exit the shell */
}

int shell_env(char **args)
{
    /* Print the current environment */
    for (char **env = envi00; *env != NULL; env++) {
        printf("%s\n", *env);
    }
    return 1;  /* Return 1 to continue the shell loop */
}
