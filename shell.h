#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait>

void _skell(char *argv, char **env);
int main(int argc, char **argv **env)
=======
void skell(char **env);
char *read_input(void);
void process_input(char *input, char **env);
void execute_command(char *command, char **env);
void exit_shell(void);
void env_shell(char **env);

#endif

