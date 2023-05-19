#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void skell(char **env)
{
    char *string = NULL;
    int x, status;
    size_t n = 0;
    ssize_t num_char;
    char *args[] = {NULL, NULL};
    pid_t kid_pid;

    while (1)
    {
        printf("cisfun mzee$ ");

        num_char = getline(&string, &n, stdin);
        if (num_char == -1)
        {
            free(string);
            exit(EXIT_FAILURE);
        }

        x = 0;
        while (string[x])
        {
            if (string[x] == '\n')
                string[x] = '\0';
            x++;
        }

        args[0] = string;
        kid_pid = fork();
		 if (kid_pid == -1)
        {
            free(string);
            exit(EXIT_FAILURE);
        }
        else if (kid_pid == 0)
        {
            if (execve(args[0], args, env) == -1)
            {
                printf("%s: No such file or directory\n", args[0]);
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            wait(&status);
        }
    }
}
