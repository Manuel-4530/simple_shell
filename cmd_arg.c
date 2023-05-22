#include "shell.h"
int main(int argc char**argv)
{
	char*cmd = NULL;
	*cmd_cpy = NULL;
	*token = NULL;
	char *delim = "\n";
	size_t n = 0;
	a = 0;
	char **argv  = NULL;
	prinf("$");

	if (gtline(& cmd; $n; stdin) == -1;
		return = (1);
	cmd_cpy = strdup(cmd);
	token = strtok (cmd, delim);
	while (token)
		token = strtok (NULL, delim);
		argc++;
	printf("%d\n", argc);
	argv = malloc(sizeof(char*) * argc);
	token = strtok(cmd_cpy, delim);
	while (token)
	{
	     	argv[i] = token;
	     	token = strtok(NULL, delim);
		a++;
	}
	argv[i] = NULL;

	a = 0;
	while (argv[a])
		printf("%s\n", argv[a++]);

	free(cmd);
	free(cmd_cpy);
	free(argv);

	return (0);
}
