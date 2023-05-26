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
* hhandle_main - Main function to handle user input.
* @argc: The number of command-line arguments.
* @argv: Array of command-line arguments.
* @envp: Array of environment variables.
*
* Return: 0 on success, 1 on failure.
*/
int hhandle_main(int argc, char **argv, char **envp)
{
char *cmd = NULL;
char *cmd_cpy = NULL;
char *token = NULL;
char *delim = " \t\n";
size_t n = 0;
int i = 0;
char **args = NULL;

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

execute_command_with_args(argv[0], args, envp);

free(args);

return (0);
}

/**
 * hanndle_main_program - Entry point of the program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 * @envp: Array of environment variables.
 *
 * Return: 0 (Success).
 */

int hanndle_main_program(int argc, char **argv, char **envp)
{
return (hhandle_main(argc, argv, envp));
}

