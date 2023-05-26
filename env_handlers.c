#include "shell.h"

/**
 * print_env - function that prints the current working
 * environment
 *
 * Return: exit status of last function
 */

int print_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(1, environ[i], _strlen(environ[i]));
		write(1, "\n", 1);
	}

	return (0);
}

/**
 * getenv_value - function gets the path environment variable
 *
 *
 * Return: value of path variable
 */
char *getenv_value()
{
	char *var_path = "PATH";
	int i;

	for (i = 0; environ[i]; i++)
	{
		if ((environ[i][0] == var_path[0]) &
				(environ[i][1] == var_path[1]) &
				(environ[i][2] == var_path[2]) &
				(environ[i][3] == var_path[3]))
			break;

	}
	return (&environ[i][5]);
}
