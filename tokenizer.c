#include "shell.h"

/**
  * tokenizer - function that tokenizes a string using a delim into
  * a string of commands
  * @string: string to be tokenized
  * @delim: provided delimiters to use for tokenization
  *
  * Return: pointer to strings of commands
  */
char **tokenizer(char *string, char *delim)
{
	int arg_count = 0;
	int i;
	char **argv = NULL;
	char *str_cpy = NULL, *token = NULL;

	if (!string)
		return (NULL);
	str_cpy = _strdup(string);
	if (!str_cpy)
		return (NULL);
	token = strtok(string, delim);
	while (token)
	{
		token = strtok(NULL, delim);
		arg_count++;
	}
	argv = malloc(sizeof(char *) * (arg_count + 1));
	if (!argv)
		return (NULL);
	token = strtok(str_cpy, delim);
	i = 0;
	while (token)
	{
		argv[i] = _strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	argv[arg_count] = NULL;
	free(str_cpy);

	return (argv);
}
