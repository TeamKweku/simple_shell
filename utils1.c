#include "shell.h"
/**
  * _strlen - function that returns the len of a string
  * @s: string to be checked
  *
  * Return: an int value for len of string
  */
int _strlen(const char *s)
{
	int i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
  * _puts - function is used to print string
  * @str: string to be printed
  *
  * Return: Nothing
  */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
}


/**
  * _realloc - function that reallocates a memory block using malloc
  * and free
  * @ptr: pointer to previous memory
  * @old_size: old size of pointer
  * @new_size: new size to be allocated
  *
  * Return: pointer to new allocated memory
  */
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	char *ptr_new;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		ptr_new = malloc(new_size);
		if (ptr_new == NULL)
		{
			return (NULL);
		}
		return (ptr_new);
	}
	else
	{
		ptr_new = malloc(new_size);
		if (ptr_new == NULL)
			return (NULL);
		i = 0;
		for (i = 0; i < old_size && i < new_size; i++)
		{
			ptr_new[i] = ((char *) ptr)[i];
		}
	}

	free(ptr);
	return (ptr_new);
}
