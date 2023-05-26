#include "shell.h"

/**
 * handle_exit - function that handle calls to exit in the shell prog
 * @command: exit string name
 * @path_list: path array to free memory
 * @args: arguments passed
 * @exit_status: the exit status received by function
 * @code: exit status of previous program
 *
 * Return: nothing
 */
void handle_exit(char *command, char **path_list,
		char **args, char *exit_status, int code)
{
	char *exit_command = "exit";
	int i = 0, count = 0, status;

	if (_strlen(command) == _strlen(exit_command))
	{
		for (i = 0; exit_command[i]; i++)
		{
			if (command[i] == exit_command[i])
				count += 1;
		}
	}

	if ((count == 4) & (exit_status == NULL))
	{
		free_args(args);
		free_args(path_list);
		exit(code);
	}
	else if ((count == 4) & (exit_status != NULL))
	{
		status = atoi(exit_status);
		free_args(args);
		free_args(path_list);
		exit(status);
	}
}
