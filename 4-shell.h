#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

extern char **envi00;

/* Function prototypes */

void display_prompt(void);
int execute_command(char **args);
int shell_exit(char **args);
int shell_env(char **args);
int handle_built_in(char **args, int *status);
void print_error(char *command);








#endif /* SHELL_H */
