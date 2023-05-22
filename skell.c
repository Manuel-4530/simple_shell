#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

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
write(STDOUT_FILENO, "cisfun mzee$ ", 13);

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

return (input);
}

/**
* process_input - Process the user input.
* @input: The user input string.
* @env: The environment variable.
*/
void process_input(char *input, char **env)
{
char *command = strtok(input, " \t\n");

if (strcmp(command, "env") == 0)
{
env_shell(env);
}

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
if (strcmp(command, "env") == 0)
{
int i = 0;

while (env[i] != NULL)
{
printf("%s\n", env[i]);
i++;
}
}
else if (strcmp(command, "exit") == 0)
{
printf("Exiting the shell Mzee...\n");
exit(EXIT_SUCCESS);
}
else
{
pid_t pid;

pid = fork();
if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
char *args[2];

args[0] = command;
args[1] = NULL;

if (execve(args[0], args, env) == -1)
{
perror("No such file or directory");
exit(EXIT_FAILURE);
}
}
else
{
int status;
wait(&status);
}
}
}

