README.md:               This file should contain information about your project, how to compile and run it, and any other relevant details.

man_1_simple_shell:      This is the man page for your shell, providing documentation on how to use it.

AUTHORS:                 This file should list all individuals who have contributed to the project.

shell.h:                 Header file containing function prototypes and any necessary includes.

main.c:                  Main entry point for your shell program.

origine.c"promput":                Contains functions related to displaying the shell prompt.
                         The prompt is the text that appears on the screen to indicate that the shell is ready to accept input from the user. In this file, you would typically have a function that prints the prompt (e.g., print_prompt) and waits for the user to enter a command.

execute.c:               Contains functions related to executing commands.
                         When the user enters a command, the shell needs to execute it. In this file, you would have functions that handle executing external commands (using execve), handling built-in commands (e.g., exit, env), and any other logic related to command execution.

helper_functions.c:      Contains any additional helper functions you may need.
                         These functions are used to perform common tasks that are needed throughout your shell implementation. For example, you might have a function to tokenize a command string into individual arguments (tokenize), or a function to free memory (free_memory).

build_in.c: Contains:    implementations for built-in shell commands (e.g., exit, env).
                         Built-in commands are commands that are implemented within the shell itself, rather than being external programs. Examples of built-in commands include exit, which exits the shell, and env, which prints the current environment variables. In this file, you would have functions that implement these built-in commands.


+-----------------------------+
|        Start Program        |
+-----------------------------+
             |
             v
+----------------------------+
|    Check Interactive Mode   |
+----------------------------+
             |
             v
+----------------------------+
|     Display Shell Prompt    |
+----------------------------+
             |
             v
+----------------------------+
|       Read Input Line       |
+----------------------------+
             |
             v
+----------------------------+
|       Parse Input Line      |
+----------------------------+
             |
             v
+----------------------------+
|   Check for Built-in Commands |
+----------------------------+
       |                |
       |                |
       |   Yes        No   |
       v                |
+----------------------------+
|     Execute Built-in Command |
+----------------------------+
             |
             v
+----------------------------+
|    Fork and Execute Command  |
+----------------------------+
             |
             v
+----------------------------+
|      Wait for Child Process  |
|         to Complete          |
+----------------------------+
             |
             v
+----------------------------+
|     Check for Exit Command   |
+----------------------------+
             |
             v
+----------------------------+
|       Continue Shell Loop    |
+----------------------------+
             |
             v
+----------------------------+
|         End Program         |

![Logo](https://blog.holbertonschool.com/wp-content/uploads/2021/05/cropped-Fichier-16.png)




This is a simple UNIX command line interpreter, created as part of the Holberton School curriculum. The shell is designed to replicate basic functionalities of the `sh` shell, providing users with a minimalistic interface to interact with their system.

## Table of Contents

- [Description](#description)
- [Installation](#installation)
- [Features](#features)
- [Contributing](#contributing)
- [Authors](#authors)
- [License](#license)

## Description

The Holberton Simple Shell, or hsh, is a simple UNIX command line interpreter created as part of the Holberton School curriculum. It provides users with a minimalistic interface to interact with their system, allowing them to execute basic commands.

## Installation

To install the Holberton Simple Shell, follow these steps:

1. Clone the repository to your local machine:
``git clone https://github.com/OussemaTurki0/holbertonschool-simple_shell.git``

2. Compile the source code using GCC:
`gcc 4.8.4 -Wall -Werror -Wextra -pedantic *.c -o hsh`.  

## Features

- Displays a simple prompt for users to enter commands
- Executes commands found in the system's `PATH`
- Handles command lines with arguments
- Implements the `exit` built-in to exit the shell
- Implements the `env` built-in to print the current environment

## Contributing

To contribute to the Holberton Simple Shell, follow these steps:

1. Fork the repository on GitHub
2. Create a new branch
3. Make your changes and commit them
4. Push your changes to your fork
5. Submit a pull request to the main repository

## Authors

- Ghofrane Amemi
- Turki Oussema

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
