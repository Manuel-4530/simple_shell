#include "shell.h"
#include <sys/wait.h>
/**
* main - Entry point of the program.
* @argc: The number of command line arguments.
* @env: The environment variable.
*
* Return: Always 0.
*/
int main(int argc, char **argv, char **env)
{
(void)argc;
(void)env;

if (argc == 1)
{
skell(env); /* Call the skell function if no arguments are provided */
}
return (0);
}

