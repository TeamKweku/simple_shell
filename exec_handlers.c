#include "shell.h"

/**
  * execute_cmds - function that executes a command specified
  * by the argv
  * @argv: arguments provided to funtion
  *
  * Return: nothing
  */
void execute_cmds(char **argv)
{
	pid_t pid;
	char *path;
	int child_status, exec_status;

	path = path_finder(argv);
	if (!path)
		perror("./hsh");
	else
	{
		pid = fork();
		if (pid == -1)
			perror("error creating child process");
		else if (pid == 0)
		{
			exec_status = execve(path, argv, environ);
			if (exec_status == -1)
			{
				frees1(argv);
				exit(EXIT_FAILURE);
			}

			exit(EXIT_SUCCESS);
		}
		else
			wait(&child_status);
		if (!path)
			free(path);
	}
	frees1(argv);
}

/**
  * handle_builtin_cmds - function handles buitin commands based
  * on the value of argv[0]
  * @argv: arguments to be compared
  * @env: environment variables
  *
  * Return: Success (1)
  */
int handle_builtin_cmds(char **argv, char **env)
{
	if (_strcmp(argv[0], "setenv") == 0)
	{
		set_env_var(argv, env);
		 frees1(argv);
	}
	else if (_strcmp(argv[0], "unsetenv") == 0)
	{
		unset_env_var(argv, env);
		 frees1(argv);
	}
	else if (_strcmp(argv[0], "cd") == 0)
	{
		cd(argv, env);
		frees1(argv);
	}
	else if (_strcmp(argv[0], "env") == 0)
	{
		print_env();
		frees1(argv);
	}
	else
		execute_cmds(argv);
	return (1);
}
