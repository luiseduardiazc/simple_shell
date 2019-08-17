#include "holberton.h"

/**
 * _strcmp - writes the character c to stdout
 * @s1: The first character to compare
 * @s2: The second character to compare
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
*/
int _strcmp(char *s1, char *s2)
{
	int i, res = 0;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			res = s1[i] - s2[i];
			break;
		}
	}
	return (res);
}

/**
  * _strncmp - Compare two strings n bytes
  * @s1: The first character to compare
  * @s2: The second character to compare
  * @n: Number of bytes
  *
  * Return: On success 0.
  * On error.
  */
int _strncmp(char *s1, char *s2, int n)
{
	int i, res = 0;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			res = s1[i] - s2[i];
			break;
		}
	}
	return (res);
}

/**
  * _strcpy - writes the character c to stdout
  * @dest: The new array
  *@src: The array to be copied
  *
  * Return: On success 1.
  * On error, -1 is returned, and errno is set appropriate
  */
char *_strcpy(char *dest, char *src)
{
	int tam, i = 0;

	tam = _strlen(src);
	while (i <= tam)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
