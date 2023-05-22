#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * exit_shell - Exit the shell.
 */
void exit_shell(void)
{
	perror("Exiting the shell mzee...");
	exit(EXIT_SUCCESS);
}

