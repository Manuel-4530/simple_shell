#include "shell.h"

int (int *argc, char *argv, char **env)
{
	if(argc==1)
		_skell(argv,env);
	return(0);
}
