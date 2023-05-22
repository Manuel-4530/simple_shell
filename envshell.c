#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* env_shell - Print the current environment.
* @env: The environment variable.
*/
void env_shell(char **env)
{
int i;
for (i = 0; env[i] != NULL; i++)
{
size_t len = strlen(env[i]);
if (write(STDOUT_FILENO, env[i], len) < 0 || write(STDOUT_FILENO, "\n", 1) < 0)
{
perror("write");
exit(EXIT_FAILURE);
}
}
}
