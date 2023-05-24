#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
* main - Entry point of the program
* Description: Allows user input of a name and age.
* Prints a message based on the age.
*
* Return: Always 0 (Success)
*/

int main(void)
{
char name[100];
int age;

/* Prompt the user to enter their name */
write(1, "Enter your name: ", 17);
fgets(name, sizeof(name), stdin);

/* Prompt the user to enter their age */
write(1, "Enter your age: ", 16);
scanf("%d", &age);

/* Check the age and display the appropriate message */
if (age >= 18)
{
/* Age is 18 or above */
write(1, "Fit for marriage\n", 17);
}
else
{
/* Age is below 18 */
write(1, "Mea ndevu kwanza\n", 17);
}

return (0);
}

