#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <sys/wait.h>
#include <errno.h>

#define BUFFER_SIZE 1024

/* External environment variable */
extern char **environ;

/* Function prototypes */
int main(void);
void display_prompt(void);
char *read_line(void);
char **split_line(char *line);
int execute(char **args);
int execute_builtin(char **args);
void free_args(char **args);
int shell_exit(void);
int shell_pwd(void);
int shell_env(void);
char *get_command_path(const char *cmd);
int is_builtin(char *cmd);
void handle_error(void);
void interactive_shell(void);
void non_interactive_shell(void);

#endif /* SHELL_H */
