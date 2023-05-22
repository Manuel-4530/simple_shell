#include "shell.h"

<<<<<<< HEAD
int (int *argc, char *argv, char **env){

	if(argc==1)
		_skell(argv,env);
	return(0);
=======
/**
* main - Entry point of the program.
* @argc: The number of command line arguments.
* @env: The environment variable.
*
* Return: Always 0.
*/
int main(int argc, char **env)
{
(void)argc;
(void)env;

if (argc == 1)
{
skell(env); /* Call the skell function if no arguments are provided */
>>>>>>> 221a86eed345b6a901c19d382f54fda35cdfe5c6
}
return (0);
}

