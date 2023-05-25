#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/*global variables*/
void skell(char **env);
char *read_input(void);

/* main function functions*/
void process_input(char *input, char **env);
void execute_command(char *command, char **env);

/*exit builtin*/ 
void exit_shell(void);

/*envirnment */
void env_shell(char **env);

/*execute functions*/
void execute_command_with_args(char *command, char **args, char **env);
void process_input_with_args(char *input, char **env);
void handle_command_with_args(char **args, char **env);
int handle_main(void);

#endif

