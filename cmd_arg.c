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

