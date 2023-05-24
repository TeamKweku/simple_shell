#include "shell.h"

/**
 * main - checks the working of the shell.
 *
 * Return: 0 on success.
 */
int main(void)
{
	char *command = NULL, **arguments = NULL;

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			display_prompt();
			command = capture_user_input();
			if (command == NULL)
				return (-1);
			arguments = tokenizer(command, " \n");
			if (arguments == NULL)
			{
				free(command);
				return (-1);
			}
			if (_strcmp(arguments[0], "exit") == 0)
			{
				free(command);
				free_args(arguments);
				break;
			}
			handle_builtin_cmds(arguments, environ);
			if (command && command[0] != '\n')
				free(command);
		}
	}
	else
	{
		command = NULL;
		non_interactive(command);
	}
	return (0);
}
