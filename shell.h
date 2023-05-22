#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void skell(char **env);
char *read_input(void);
void process_input(char *input, char **env);
void execute_command(char *command, char **env);
void exit_shell(void);
void env_shell(char **env);

#endif

