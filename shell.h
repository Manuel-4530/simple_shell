#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * skell - Start the shell and process user input.
 *
 * @env: The array of environment variables.
 */
void skell(char **env);

/**
 * read_input - Read a line of input from the user.
 *
 * Return: The line of input entered by the user.
 */
char *read_input(void);

/**
 * process_input - Process the user input.
 *
 * @input: The line of input entered by the user.
 * @env: The array of environment variables.
 */
void process_input(char *input, char **env);

/**
 * execute_command - Execute a command entered by the user.
 *
 * @command: The command to execute.
 * @env: The array of environment variables.
 */
void execute_command(char *command, char **env);

/**
 * exit_shell - Exit the shell.
 */
void exit_shell(void);

/**
 * env_shell - Display the environment variables.
 *
 * @env: The array of environment variables.
 */
void env_shell(char **env);

/**
 * execute_command_with_args - Execute a command with arguments.
 *
 * @command: The command to execute.
 * @args: The array of arguments.
 * @env: The array of environment variables.
 */
void execute_command_with_args(char *command, char **args, char **env);

/**
 * process_input_with_args - Process the user input with arguments.
 *
 * @input: The line of input entered by the user.
 * @env: The array of environment variables.
 */
void process_input_with_args(char *input, char **env);

/**
 * handle_command_with_args - Handle a command with arguments.
 *
 * @args: The array of arguments.
 * @env: The array of environment variables.
 */
void handle_command_with_args(char **args, char **env);

/**
 * handle_main - Handle the main loop of the shell.
 *
 * Return: 0 on success, or an error code on failure.
 */
int handle_main(void);

#endif /* _SHELL_H_ */

