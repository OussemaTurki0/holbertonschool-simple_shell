#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

extern char **environ;

/* Function prototypes */

void display_prompt(void);
int execute_command(char **args);
int shell_exit(char **args);
int shell_env(char **args);
void shell_echo(char **args);
int handle_built_in(char **args, int *status);
char *read_line(void);
char *read_line_from_file(FILE *file);
void print_error(char *program_name, char *command);
int **tokenizer(char *line);
int count_tokens(const char *line, const char *delim);



#endif /* SHELL_H */

