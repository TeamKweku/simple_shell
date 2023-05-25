#include "shell.h"

/**
 * display_prompt - function displays prompt on terminal.
 *
 * Rerurn: void.
 */
void display_prompt(void)
{
	_puts("X-shell$ ");
	fflush(stdout);
}

/**
 * capture_user_input - function reads input.
 *
 * Return: the user input.
 */
char *capture_user_input(void)
{
	size_t size = 0;
	char *input = NULL, *cmd = NULL;

	if (getline(&input, &size, stdin) == -1)
	{
		free(input);
		return (NULL);
	}
	if (_strcmp(input, "\n") == 0)
	{
		free(input);
		display_prompt();
		return (capture_user_input());
	}
	cmd = _strdup(input);
	if (input != NULL)
		free(input);
	return (cmd);
}

/**
 * find_path - executes new process
 * @arguments: the array of strings.
 *
 * Return: the path.
 */
char *find_path(char **arguments)
{
	int length;
	char *path = NULL, *token = NULL, *exe_path = NULL;
	struct stat status;

	if (stat(arguments[0], &status) == 0)
	{
		exe_path = _strdup(arguments[0]);
		return (exe_path);
	}
	path = getenv_value("PATH");
	if (path == NULL)
		return (NULL);
	token = strtok(path, ":");
	while (token != NULL)
	{
		length = _strlen(arguments[0]) + _strlen(token) + 2;
		exe_path = malloc(sizeof(char) * length);
		if (exe_path == NULL)
			return (NULL);
		_strcpy(exe_path, token);
		_strcat(exe_path, "/");
		_strcat(exe_path, arguments[0]);
		if (stat(exe_path, &status) == 0)
		{
			free(path);
			return (exe_path);
		}
		free(exe_path);
		token = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}

/**
 * retrieve_line - function retrieves an entire line from a string.
 * @line_buffer: a pointer to the text from stream.
 * @s: number of bytes needed for buffer.
 * @stream: is either stdin, stdout, stderr.
 *
 * Return: number of characters read.
 */
ssize_t retrieve_line(char **line_buffer, size_t *s, FILE *stream)
{
	ssize_t total_read_count;
	char *buf, *temp_buf, *end_buf;

	if (!line_buffer || !s || !stream)
		return (-1);
	fflush(stdout);
	if (*line_buffer == NULL && *s == 0)
	{
		*s = 10;
		buf = malloc(*s);
		if (buf == NULL)
			return (-1);
		*line_buffer = buf;
	}
	else
		buf = *line_buffer;
	temp_buf = buf;
	end_buf = buf + *s;
	total_read_count = retrieve_line1(line_buffer, buf, temp_buf, end_buf, s);
	return (total_read_count);
}

/**
 * retrieve_line1 - function complements retrieve_line func.
 * @p: pointer to the stram text.
 * @b: the buffer.
 * @j: the temporary moving pointer.
 * @end_buf: a pointer to the end of the buffer.
 * @s: number of bytes to be allocated.
 *
 * Return: number of characters read.
 */
ssize_t retrieve_line1(char **p, char *b, char *j, char *end_buf, size_t *s)
{
	ssize_t read_count = 1, total_read_count = 0;
	size_t new_buffer_size;
	char *new_buffer;

	while (read_count != 0)
	{
		read_count = read(STDIN_FILENO, j, 1);
		if (read_count == -1)
			return (-1);
		total_read_count += read_count;
		if (*j == '\n')
			break;
		if (j == end_buf)
		{
			new_buffer_size = *s * 2;
			new_buffer = _realloc(b, *s, new_buffer_size);
			if (new_buffer == NULL)
				return (-1);
			b = new_buffer;
			*p = b;
			j = b + *s - 1;
			end_buf = b + new_buffer_size;
			*s = new_buffer_size;
		}
		j++;
	}
	j++;
	*j = '\0';
	*p = b;
	return (total_read_count);
}
