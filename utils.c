#include "shell.h"

/**
  * _strcmp - compares two strings
  * @str1: the first string
  * @str2: the second string
  *
  * Return: (0) if found, or -ve or +ve value if otherwise
  */
int _strcmp(char *str1, const char *str2)
{
	while (*str1 != '\0' && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	return (*str1 - *str2);
}

/**
  * _strcpy - copies the string src to dest
  * @dest: pointer to destination copied str
  * @src: pointer to string to be copied
  *
  * Return: Pointer to destination string
  */
char *_strcpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
  * _strdup - function used to duplicate a copy of a string
  * @str: string to duplicate
  *
  * Return: pointer to new string or NULL
  */

char *_strdup(const char *str)
{
	size_t len = _strlen(str);
	char *dup = malloc((len + 1) * sizeof(char));

	if (!dup)
		return (NULL);
	_strcpy(dup, str);

	return (dup);
}

/**
  * _strchr - locates the first occurance of a character in a string
  * @s: string being accessed
  * @c: the character
  *
  * Return: pointer to character address or NULL
  */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] >= '\0'; i++)
	{
		if (s[i] == c)
		{
			return (&s[i]);
		}
	}

	return (NULL);
}

/**
  * _strcat - concatenates two strings
  * @dest: pointer to destination string
  * @src: pointer to src string
  *
  * Return: pointer to dest string
  */
char *_strcat(char *dest, const char *src)
{
	char *dest_ptr = dest;
	const char *src_ptr = src;

	while (*dest_ptr != '\0')
		dest_ptr++;
	while (*src_ptr != '\0')
		*dest_ptr++ = *src_ptr++;
	*dest_ptr = '\0';

	return (dest);
}
