#include "shell.h"
/**
 * cd - function that changes working directory
 * @args: commandline parameters to be passed
 *
 * Return: 0 (success)
 */

int cd(char **args)
{
	char *directory = args[1], *work_directory;

	if (directory == NULL)
		directory = getenv("HOME");

	if (_strcmp(directory, "-") == 0)
	{
		directory = getenv("OLDPWD");
		if (directory == NULL)
		{
			perror("not set");
			return (1);
		}
	}

	if (chdir(directory) != 0)
	{
		perror("cd");
		return (1);
	}

	work_directory = getcwd(NULL, 0);
	if (work_directory == NULL)
	{
		perror("getcwd");
		exit(1);
	}
	setenv("OLDPWD", getenv("PWD"), 1);
	setenv("PWD", work_directory, 1);
	free(work_directory);

	return (0);
}
