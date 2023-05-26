#include "shell.h"
/**
 * find_exec - function searches for executable files in the path
 * @path_list: array of pointers to the path of exec file
 * @filename: file to execute
 * @found: pointer to variable keeping track of memory
 *
 * Return: pointer to filename or path
 */

char *find_exec(char **path_list, char *filename,  int *found)
{
	int i;
	char *path;

	for (i = 0; path_list[i]; i++)
	{
		path = malloc(sizeof(char) * (_strlen(path_list[i]) +
					_strlen(filename) + 2));
		if (!path)
		{
			perror("malloc");
			return ("(null)");
		}

		path = _strcpy(path, path_list[i]);
		path = _strcat(path, "/");
		path = _strcat(path, filename);
		if (access(path, F_OK) != -1)
		{
			*found = 1;
			return (path);
		}
		free(path);
	}

	if (access(filename, F_OK) != -1)
		return (filename);

	return (NULL);
}

/**
  * get_paths - functions concatenates the path variable
  *
  * Return: pointer to array of path location
  */

char **get_paths(void)
{
	int count = 0, i;
	char path_copy[PATH_SIZE];
	char *path_var, *token, **path_list;

	path_var = getenv_value();
	_strcpy(path_copy, path_var);
	for (i = 0; path_copy[i]; i++)
	{
		if (path_copy[i] == ':')
			count += 1;
	}
	count += 1;

	i = 0;
	path_list = malloc(sizeof(char *) * (count + 1));
	if (!path_list)
	{
		perror("malloc");
		return (NULL);
	}

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		path_list[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (path_list[i] == NULL)
		{
			perror("malloc");
			return (NULL);
		}

		_strcpy(path_list[i++], token);
		token = strtok(NULL, ":");
	}
	path_list[i] = NULL;

	return (path_list);
}


/**
 * get_main_path - functions get an array of main path
 *
 * Return: array of paths
 */

char **get_main_path(void)
{
	char **path_var;
	int i, count = 0;
	char **new_path;

	path_var = get_paths();
	for (i = 0; path_var[i]; i++)
		count += 1;

	new_path = malloc(sizeof(char *) * (count + 1));
	if (!new_path)
		return (NULL);

	for (i = 0; path_var[i]; i++)
	{
		new_path[i] = malloc(sizeof(char) * (_strlen(path_var[i]) + 1));
		_strcpy(new_path[i], path_var[i]);
	}
	new_path[i] = NULL;

	free_args(path_var);
	return (new_path);
}

/**
 * count_words - counts number of words input
 * @str: input string to count words
 *
 * Return: no of words
 */

int count_words(char *str)
{
	int word_count = 0;
	int len = _strlen(str);
	int i = 0;

	if (_strcmp(str, "") == 0)
		return (0);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (i < len)
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			word_count++;
			while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
				i++;
		}
		else
			i++;
	}
	if (str[len - 1] != ' ' && str[len - 1] != '\t' && str[len - 1] != '\n')
		word_count++;
	return (word_count);
}
