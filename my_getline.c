#include "shell.h"
/**
 * update_ptr - Reassigns the lineptr variable for _getline.
 * @ptr: A buffer to store an input string.
 * @n: The size of lineptr.
 * @buf: The string to assign to lineptr.
 * @b: The size of buffer.
 */

void update_ptr(char **ptr, size_t *n, char *buf, size_t b)
{
	if (*ptr == NULL)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*ptr = buf;
	}
	else if (*n < b)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*ptr = buf;
	}
	else
	{
		_strcpy(*ptr, buf);
		free(buf);
	}
}

/**
 * my_getline - Reads input from a stream.
 * @lineptr: A buffer to store the input.
 * @s: The size of lineptr.
 * @stream: The stream to read from.
 *
 * Return: The number of bytes read.
 */
ssize_t my_getline(char **lineptr, size_t *s, FILE *stream)
{
	static ssize_t input_len;
	ssize_t characters_read;
	char current_char = 'x', *buf;
	int read_result;

	if (input_len == 0)
		fflush(stream);
	else
		return (-1);
	input_len = 0;

	buf = malloc(sizeof(char) * 120);
	if (!buf)
		return (-1);

	while (current_char != '\n')
	{
		read_result = read(STDIN_FILENO, &current_char, 1);
		if (read_result == -1 || (read_result == 0 && input_len == 0))
		{
			free(buf);
			return (-1);
		}
		if (read_result == 0 && input_len != 0)
		{
			input_len++;
			break;
		}

		if (input_len >= 120)
			buf = _realloc(buf, input_len, input_len + 1);
		buf[input_len] = current_char;
		input_len++;
	}
	buf[input_len] = '\0';
	update_ptr(lineptr, s, buf, input_len);
	characters_read = input_len;
	if (read_result != 0)
		input_len = 0;
	return (characters_read);
}
