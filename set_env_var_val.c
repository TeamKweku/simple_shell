#include "shell.h"

/**
  * set_env_var_val - function that sets environmental variables
  * @var: variable to be set
  * @value: value to set to environment variable
  * @environ: environment to be set
  *
  * Return: sets a int value on success
  */
int set_env_var_val(char *var, char *value, char **environ)
{
	char *token;
	char *environ_cpy;
	int index = 0;
	char *rel;

	while (environ[index])
	{
		environ_cpy = _strdup(environ[index]);
		token = strtok(environ_cpy, "=");
		if (_strcmp(token, var) == 0)
		{
			rel = malloc(sizeof(char) * (_strlen(var) + _strlen(value) + 3));
			if (!rel)
				return (-1);
			_strcpy(rel, token);
			_strcat(rel, "=");
			_strcat(rel, value);
			environ[index] = rel;
			free(environ_cpy);
			return (0);
		}

		free(environ_cpy);
		index++;
	}

	return (-1);
}
