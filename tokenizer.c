#include "shell.h"
/**
 * tokenizer - function that tokenizes a string
 * @path: pointer to array of path to token from string string path
 * @exit_status: exit status of old program
 *
 * Return: tokenized string
 */

char **tokenizer(char **path, int exit_status)
{
	char *input_line = NULL, **tokens, *token;
	size_t n = 0;
	int i = 0;

	if (isatty(STDIN_FILENO))
		write(1, "$ ", 2);
	if ((getline(&input_line, &n, stdin)) == -1)
	{
		free(input_line);
		free_args(path);
		exit(exit_status);
	}
	for (i = 0; input_line[i]; i++)
	{
		if (input_line[i] == '\n')
			input_line[i] = '\0';
	}
	tokens = malloc(sizeof(char *) * (count_words(input_line) + 1));
	if (!tokens)
	{
		perror("malloc");
		return (NULL);
	}
	token = strtok(input_line, " ");
	i = 0;
	while ((token != NULL) && !(_strcmp(token, "#") == 0))
	{
		tokens[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (tokens[i] == NULL)
		{
			perror("malloc");
			return (NULL);
		}
		_strcpy(tokens[i++], token);
		token = strtok(NULL, " ");
	}
	tokens[i] = NULL;

	free(input_line);
	return (tokens);
}

