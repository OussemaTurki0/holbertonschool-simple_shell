README.md:               This file should contain information about your project, how to compile and run it, and any other relevant details.

man_1_simple_shell:      This is the man page for your shell, providing documentation on how to use it.

AUTHORS:                 This file should list all individuals who have contributed to the project.

shell.h:                 Header file containing function prototypes and any necessary includes.

main.c:                  Main entry point for your shell program.

prompt.c:                Contains functions related to displaying the shell prompt.
                         This file contains functions related to displaying the shell prompt. The prompt is the text that appears on the screen to indicate that the shell is ready to accept input from the user. In this file, you would typically have a function that prints the prompt (e.g., print_prompt) and waits for the user to enter a command.

execute.c:               Contains functions related to executing commands.
                         This file contains functions related to executing commands. When the user enters a command, the shell needs to execute it. In this file, you would have functions that handle executing external commands (using execve), handling built-in commands (e.g., exit, env), and any other logic related to command execution.

helper_functions.c:      Contains any additional helper functions you may need.
                         This file contains any additional helper functions you may need in your shell. These functions are used to perform common tasks that are needed throughout your shell implementation. For example, you might have a function to tokenize a command string into individual arguments (tokenize), or a function to free memory (free_memory).

builtins.c: Contains:    implementations for built-in shell commands (e.g., exit, env).
                         This file contains implementations for built-in shell commands. Built-in commands are commands that are implemented within the shell itself, rather than being external programs. Examples of built-in commands include exit, which exits the shell, and env, which prints the current environment variables. In this file, you would have functions that implement these built-in commands.
