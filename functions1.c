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

/**
  * *_strcat - writes the character c to stdout
  * @dest: The destination array
  * @src: The source array
  *
  * Return: On success 1.
  * On error, -1 is returned, and errno is set appropriately.
  */
char *_strcat(char *dest, char *src)
{
	int tamS, tamD, i, tot, j;

	tamS = 0;
	j = 0;
	tamD = 0;
	while (dest[tamD] != '\0')
		++tamD;
	while (src[tamS] != '\0')
		++tamS;
	tot = tamD + tamS;
	for (i = tamD; i <= tot; i++)
	{
		dest[i] = src[j];
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
