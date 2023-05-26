#include "shell.h"
/**
 * main - entry point to the shell program
 * @argc: number of argument being passed to progrm
 * @argv: pointer to array of variables
 * @env: environment variables
 *
 * Return: int no.
 */

int main(int argc, char **argv, char **env)
{
	int path_match = 0, exit_status = 0;
	char **args, **path_list, *executable;
	int command_count = 0, exec_inbuilt = 0;

	path_list = get_main_path();
	(void)argc, (void)argv;
	signal(SIGINT, signal_handler);
	while (1)
	{
		args = tokenizer(path_list, exit_status);
		command_count++;
		if (args[0] == NULL)
		{
			free_args(args);
			continue;
		}
		handle_exit(args[0], path_list, args, args[1], exit_status);
		exit_status = handle_builtin_cmds(args, &exec_inbuilt);
		if (exec_inbuilt == 1)
		{
			exec_inbuilt = 0;
			free_args(args);
			continue;
		}
		executable = find_exec(path_list, args[0], &path_match);
		if (!executable)
		{
			exit_status = 1;
			print_error_msgs(argv[0], command_count, args[0]);
			free_args(args);
			continue;
		}
		exit_status = execute_cmds(executable, args, env);
		if (path_match == 1)
			free(executable);
		path_match = 0;
		free_args(args);
	}
	return (exit_status);
}
