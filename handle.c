#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
* execute_command_with_args - Execute a command with arguments.
* @command: The command string.
* @args: Array of arguments.
* @env: The environment variable.
*/
void execute_command_with_args(char *command, char **args, char **env)
{
pid_t pid = fork();

if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
/* Child process */
if (execve(command, args, env) == -1)
{
perror("execve");
exit(EXIT_FAILURE);
}
}
else
{
/* Parent process */
int status;
waitpid(pid, &status, 0);
}
}

/**
* handle_main - Main function to handle user input.
*
* Return: 0 on success, 1 on failure.
*/
int handle_main(void)
{
char *cmd = NULL;
char *cmd_cpy = NULL;
char *token = NULL;
char *delim = " \t\n";
size_t n = 0;
int argc = 0;
char **args = NULL;
int i = 0;

if (getline(&cmd, &n, stdin) == -1)
return (1);

cmd_cpy = strdup(cmd);
token = strtok(cmd, delim);
while (token)
{
token = strtok(NULL, delim);
argc++;
}

args = malloc(sizeof(char *) * (argc + 1));

token = strtok(cmd_cpy, delim);
i = 0;
while (token)
{
args[i] = token;
token = strtok(NULL, delim);
i++;
}
args[i] = NULL;

free(cmd);
free(cmd_cpy);

free(args);

return (0);
}

