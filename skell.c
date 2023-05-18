#include "shell.h"
#include <sys/wait.h>

void skell(char **argv, char **env);
	{
	char *string = NULL;
	int x, status;
	size_t n=0;
	ssize_t num_char;
	char *argv[] = (NULL, NULL);
	pid_t kid_pid;
	
	while (1)
	{
		printf("cisfun mzee$");

		num_char = getline(&string, &n, stdin);
		if(num_char == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		x=0
			while(string[1])
			{
				if(string[x]== '\n')
				string[x] = 0;
				x++;
			}
		argv[0] = string;
		kid_pid = fork();
		if(kid_pid == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		if (kid_pid == 0)
		{
			if(execve (argv[0], argv, env) == -1)
			printf("%s:No such file or directory \n" argv[0])
		}
		else
			wait(&status);
	}
}
