#include "shell.h"
/**
  * non_interactive - function that executes command in
  * non-interactive mode
  * @command: commands passed from user
  *
  * Return: 0 (success)
  */
int non_interactive(char *command)
{
	char **argv;
	size_t buffer_size = 0;

	while (my_getline(&command, &buffer_size, stdin) != -1)
	{
		argv = tokenizer(command, " \n");
		if (!argv)
		{
			free(command);
			exit(EXIT_FAILURE);
		}
		if (_strcmp(argv[0], "exit") == 0)
		{
			free_args(argv);
			break;
		}
		handle_builtin_cmds(argv, environ);
	}

	free(command);
	return (0);
}

