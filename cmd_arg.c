#include "shell.h"

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of strings containing the command-line arguments
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	char *cmd = NULL;
	char *cmd_p = NULL;
	char *token = NULL;
	char *delim = "\n";
	ssize_t line_size;
	int a = 0;
	size_t n = 0;
	char **argv  = NULL;

	prinf("$");

	line_size = getline(&cmd, &n, stdin);
	if (line_size == -1)
	{
	perror("getline error");
	return (1);
	}

	cmd_p = strdup(cmd);
	token = strtok(cmd, delim);
	while (token)
		token = strtok(NULL, delim);
	argc++;
	printf("%d\n", argc);
	args = malloc(sizeof(char *) * argc);
	token = strtok(cmd_cpy, delim);
	while (token)
	{
	argv[i] = token;
	token = strtok(NULL, delim);
		a++;
	}
	argv[a] = NULL;

	a = 0;
	while (argv[a])
		printf("%s\n", argv[a++]);

	free(cmd);
	free(cmd_p);
	free(args);
	return (0);
}
