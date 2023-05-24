#include "shell.h"

/**
 * print_env - copies environment variables.
 *
 * Return: void.
 */
void print_env(void)
{
	int index = 0;

	while (environ[index])
	{
		_puts(environ[index]);
		_putchar('\n');
		index++;
	}
}

/**
 * new_env - copies environment variables.
 *
 * Return: the environment path.
 */
char **new_env(void)
{
	char **environ_1 = NULL;
	int i = 0, j = 0;

	while (environ[i])
	{
		i++;
	}
	environ_1 = malloc(sizeof(char *) * (i + 1));
	if (environ_1 == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		environ_1[j] = _strdup(environ[j]);
		j++;
	}
	environ_1[j] = NULL;
	return (environ_1);
}

/**
 * getenv_value - get the environment value.
 * @name: the name of the environment variable.
 *
 * Return: value of env.
 */
char *getenv_value(const char *str)
{
	char *token, *tokenized_env, *value = NULL;
	char **env_var = new_env();
	int index = 0;

	if (!env_var)
		return (NULL);
	while (env_var[index])
	{
		tokenized_env = _strdup(env_var[index]);
		token = strtok(tokenized_env, "=");

		if (_strcmp(token, str) == 0)
		{
			token = strtok(NULL, "=");
			value = _strdup(token);
			free_args(env_var);
			free(tokenized_env);

			return (value);
		}
		index++;
		free(tokenized_env);
	}
	free(value);
	free_args(env_var);

	return (NULL);
}

/**
 * set_env_var - sets the environment variables.
 * @arguments: the array of arguments
 * @env: the environment path.
 *
 * Return: 1 on success or 0.
 */
int set_env_var(char **arguments, char **env)
{
	int index = 0, i = 0, length;
	char *token, *copy, *result = NULL;

	while (arguments[i])
		i++;
	if (i != 3)
	{
		write(2, ARGS_ERROR, _strlen(ARGS_ERROR));
		return (-1);
	}
	length = _strlen(arguments[1]) + _strlen(arguments[2]) + 2;
	while (env[index])
	{
		copy = _strdup(env[index]);
		token = strtok(copy, "=");
		if (_strcmp(token, arguments[1]) == 0)
		{
			result = malloc(sizeof(char) * (length + 1));
			if (result == NULL)
				return (-1);
			_strcpy(result, token);
			_strcat(result, "=");
			_strcat(result, arguments[2]);
			env[index] = result;
			free(copy);
			return (0);
		}
		free(copy);
		index++;
	}
	result = malloc(sizeof(char) * (length + 1));
	if (result == NULL)
		return (-1);
	_strcpy(result, arguments[1]);
	_strcat(result, "=");
	_strcat(result, arguments[2]);
	env[index] = result;
	env[index + 1] = NULL;
	return (1);
}

int unset_env_var(char **arguments, char **env)
{
	int i = 0, index = 0, y;
	char *token, *copy;

	while (arguments[index])
		i++;
	if (i != 2)
	{
		write(2, ARGS_ERROR, _strlen(ARGS_ERROR));
		return (-1);
	}
	while (env[index])
	{
		copy  = _strdup(env[index]);
		token = strtok(copy, "=");
		if (_strcmp(token, arguments[1]) == 0)
		{
			y = index;
			while (env[y + 1])
			{
				env[y] = _strdup(env[y + 1]);
				y++;
			}
			env[y] = NULL;
			free(copy);
			return (0);
		}
		free(copy);
		index++;
	}
	write(2, VAR_ERROR, _strlen(VAR_ERROR));
	return (-1);
}
