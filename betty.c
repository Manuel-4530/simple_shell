#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
* bet_main - Entry point of the program
* Description: This program prints the name "ALX student"
* Return: Always 0 (on successful execution)
*/
int bet_main(void)
{
char name[] = "ALX student";

/* Write "Name: " to standard output */
write(STDOUT_FILENO, "Name: ", 6);

/* Write the content of 'name' to standard output */
write(STDOUT_FILENO, name, sizeof(name) - 1);

/* Write a newline character to standard output */
write(STDOUT_FILENO, "\n", 1);

return (0);
}

