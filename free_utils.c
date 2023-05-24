#include "shell.h"

/**
  * free_args - function that frees a pointer to pointer
  * @argv: strings to be freed
  *
  * Return: Nothing
  */
void free_args(char **argv)
{
	int i = 0;

	if (argv != NULL)
	{
		while (argv[i] != NULL)
		{
			free(argv[i]);
			i++;
		}

		free(argv);
	}
}

/**
  * free_memory - function frees memory of any leaks
  * @argv: pointer to assigned memory to be freed
  * @env: environment variables to be freed
  *
  * Return: Nothing
  */
void free_memory(char **argv, char **env)
{
	int argv_index = 0, env_index;

	if (argv)
	{
		while (argv[argv_index])
		{
			free(argv[argv_index]);
			argv_index++;
		}
		free(argv);
	}
	if (env)
	{
		env_index = 0;
		while (env[env_index])
		{
			free(env[env_index]);
			env_index++;
		}
		free(env);
	}
}
