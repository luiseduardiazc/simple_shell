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

	while (*s1 && strchr(s2, *s1++))
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
		if (strchr(s2, *s1))
			return (ret);

		s1++, ret++;
	}
	return (ret);
}
