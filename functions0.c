#include "holberton.h"

/**
  * _strlen - Calculate lenght
  * @s: The array
  *
  * Return: A int that its the lenght of s.
  * On error, retunr NULL.
  */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

/**
  * str_concat- Concatenate two arrays
  * @s1: The first array
  * @s2: The second array
  *
  * Return: A pointer.
  * On error, retunr NULL.
  */
char *str_concat(char *s1, char *s2)
{
	unsigned int i, j, in, tam;
	char *buff;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	tam = (_strlen(s1) + _strlen(s2));
	buff = malloc(tam + 1);
	in = 0;
	if (buff == NULL)
		return (NULL);
	for (i = 0; s1[i] != '\0'; i++)
		buff[i] = s1[i];
	for (j = i; s2[in] != '\0'; j++)
	{
		buff[j] = s2[in];
		in++;
	}
	buff[j] = '\0';
	return (buff);
}

/**
  * _strdup - Duplicate an array or return NULL
  * @str: The string to be copied
  *
  * Return: On success a pointer.
  * On error, NULL is returned.
  */
char *_strdup(char *str)
{
	int i = 0;
	char *buff;

	if (str == NULL)
		return (NULL);
	buff = malloc(_strlen(str) + 1);
	if (buff == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		buff[i] = str[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

/**
 * _strncpy - Copy a string
 * @dest: The array to destination
 * @src: The array to be copied
 * @n: Number of characters to be copied
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
*/
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for ( ; i < n; i++)
		dest[i] = '\0';
	return (dest);
}

/**
 * _strstr - Search a substring in a string
 * @haystack: The array to compare
 * @needle: The array that have the substring
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
*/
char *_strstr(char *haystack, char *needle)
{
	int haysLeng, needLeng, i = 0, j;
	char buff[1024];

	haysLeng = _strlen(haystack);
	needLeng = _strlen(needle);
	while (i <= (haysLeng - needLeng))
	{
		_strncpy(buff, haystack + i, needLeng);
		buff[needLeng] = '\0';
		j = _strcmp(buff, needle);
		if (j == 0)
		{
			return (haystack + i);
		}
		i++;
	}
	return (0);
}
