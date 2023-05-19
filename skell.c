#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void skell(char **env);
char *read_input(void);
void process_input(char *input, char **env);
void execute_command(char *command, char **env);

/**
 * skell - Function to execute commands in the shell.
 * @env: The environment variable.
 */
void skell(char **env)
{
	char *input;
	while (1)
	{
		printf("cisfun mzee$ ");
		fflush(stdout);
		input = read_input();
		process_input(input, env);
		free(input);
	}
}

/**
 * read_input - Read input from the user.
 * Return: The input string.
 */
char *read_input(void)
{
	char *input = NULL;
	size_t n = 0;
	ssize_t num_char = getline(&input, &n, stdin);

	if (num_char == -1)
	{
		free(input);
		exit(EXIT_FAILURE);
	}

	if (input[num_char - 1] == '\n')
		input[num_char - 1] = '\0';

	return input;
}

/**
 * process_input - Process the user input.
 * @input: The user input string.
 * @env: The environment variable.
 */
void process_input(char *input, char **env)
{
	char *command = strtok(input, " \t\n");

	while (command != NULL)
	{
		execute_command(command, env);
		command = strtok(NULL, " \t\n");
	}
}

/**
 * execute_command - Execute a command.
 * @command: The command string.
 * @env: The environment variable.
 */
void execute_command(char *command, char **env)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *args[2];
		memset(args, 0, sizeof(args));
		strcpy(args[0], command);

		if (execve(args[0], args, env) == -1)
		{
			printf("%s: No such file or directory\n", args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;
		wait(&status);
	}
}

