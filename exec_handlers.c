#include "shell.h"
/**
 * execute_cmds - function that produces the execution
 * status based on path variable
 * @cmd_path: specifies the location PATH
 * @argv: input parameters
 * @environ: environment variables
 *
 * Return: execution status
 */

int execute_cmds(char *cmd_path, char **argv, char **environ)

{
	int pid, child_status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	else if (pid == 0)
	{
		if ((execve(cmd_path, argv, environ)) == -1)
		{
			exit(1);
		}
		exit(0);
	}
	else
		wait(&child_status);
	if (WIFEXITED(child_status))
		return (WEXITSTATUS(child_status));

	return (child_status);
}


/**
 * handle_builtin_cmds - this function executes inbuilt functions
 *
 * @args: parameters that the func receives to run
 * @builtin_exec: confirms if the func run or not
 *
 * Return: exit status
 */

int handle_builtin_cmds(char **args, int *builtin_exec)
{
	int exit_status = 0;

	if (_strcmp(args[0], "cd") == 0)
	{
		exit_status = cd(args);
		*builtin_exec = 1;
		return (exit_status);
	}

	else if (_strcmp(args[0], "env") == 0)
	{
		exit_status = print_env();
		*builtin_exec = 1;
		return (exit_status);
	}

	return (exit_status);
}
