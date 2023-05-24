#include "shell.h"

/**
  * update_pwd - function updates the PWD and OLDPWD environment
  * variables
  * @environ: pointer to environment
  * @curr_dir: pointer representing current directory
  *
  * Return: 0 (success), -1 (failure)
  */
int update_pwd(char **environ, char *curr_dir)
{
	char *old_dir;

	old_dir = getenv_value("PWD");
	if (!old_dir)
		return (-1);
	if (set_env_var_val("PWD", curr_dir, environ) == -1 ||
			set_env_var_val("OLDPWD", old_dir, environ) == -1)
	{
		return (-1);
	}

	return (0);
}

/**
  * cd - function that changes the current working directory
  * @argv: array of commandline arguments
  * @env: array of environment variables
  *
  * Return: Changes directory per the return value of func
  */

void cd(char **argv, char **env)
{
	char curr_dir[BUFFSIZE], *dir = NULL;
	int arg_count = 0;

	while (argv[arg_count])
		arg_count++;
	if (arg_count == 1 && argv[1] == NULL)
	{
		dir = getenv_value("HOME");
		if (chdir(dir) == -1)
			perror(argv[0]);
		update_pwd(env, dir);
	}
	else if (_strcmp(argv[1], "-") == 0 && arg_count == 2)
	{
		dir = getenv_value("OLDPWD");
		if (chdir(dir) == -1)
			perror(argv[0]);
		else
			update_pwd(env, dir);
	}
	else if (arg_count == 2)
	{
		if (chdir(argv[1]) == -1)
			perror(argv[1]);
		else
		{
			getcwd(curr_dir, BUFFSIZE);
			update_pwd(env, curr_dir);
		}
	}
	else
	{
		write(STDERR_FILENO, ARGS_ERROR, _strlen(ARGS_ERROR));
		exit(EXIT_FAILURE);
	}
}
