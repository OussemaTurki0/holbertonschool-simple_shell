#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

/**
 * struct built_in_command - Structure for built-in
 * commands and their functions
 * @name: The name of the command
 * @function: Pointer to the function implementing the command
 */
typedef struct built_in_command
{
	char *name;
	int (*function)(char **);
} buildin;

extern char **environ;

/* Function prototypes */

void display_prompt(void);
int execute_command(char **args);
char *get_command_path(const char *command);
int shell_exit(char **args);
int shell_env(char **args);
int shell_cd(char **args);
int handle_built_in(char **args, int *status);
char *read_line(void);
char *read_line_from_file(FILE *file);
void print_error(char *program_name, char *command);
char **tokenizer(char *line);
int count_tokens(const char *line, const char *delim);
int handle_built_in(char **args);
int handle_built_in(char **args, int *status);

#endif /* SHELL_H */
