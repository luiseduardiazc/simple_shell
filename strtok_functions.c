/**
 * _strspn - function computes the length of the maximum initial segment
 * @s1: The string to compare
 * @s2: The string to compare
 *
 * Return: The strspn() function returns the length of the segment.
 */
size_t _strspn(const char *s1, const char *s2)
{
	size_t ret = 0;

	while (*s1 && _strchr(s2, *s1++))
		ret++;
	return (ret);
}
/**
 * _strrchr - function locates the ﬁrst occurrence of c
 * @s: The string to compare
 * @c: character to find
 *
 * Return: returns a pointer to the located character, or a null pointer
 */
char *_strrchr(char *s, int c)
{
	char *ret = 0;

	do {
		if (*s == (char)c)
			ret = s;
	} while (*s++);
	return (ret);
}

/**
 * _strcspn - function computes the length of the maximum initial segment
 * @s1: The string to compare
 * @s2: The string to compare
 *
 * Return: function returns the length of the segment.
 */

size_t _strcspn(const char *s1, const char *s2)
{
	size_t ret = 0;

	while (*s1)
	{
		if (_strchr(s2, *s1))
			return (ret);

		s1++, ret++;
	}
	return (ret);
}

/**
 * _strchr - function locates the ﬁrst occurrence of c
 * @s: The string to compare
 * @c: character to find
 *
 * Return: function returns a pointer to the located character
 */
char *_strchr(const char *s, int c)
{
	while (*s != (char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}
/**
 * _strtok_r - function is a reentrant version strtok()
 * @s: The string to split
 * @delim: The string to delimit s
 * @context: The saveptr argument
 * Return: functions return a pointer to the next token or NULL
 */

char *_strtok_r(char *s, char *delim, char **context)
{
	char *token = NULL;

	if (s == NULL)
		s = *context;

	/* skip initial delimiters */
	s += _strspn(s, delim);
	if (*s != '\0')
	{
		/* we have a token */
		token = s;
		/* skip the token */
		s += _strcspn(s, delim);
		if (*s != '\0')
		{
			/* cut the string to terminate the token */
			*s++ = '\0';
		}
	}
	*context = s;
	return (token);
}
