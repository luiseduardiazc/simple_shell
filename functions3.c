#include "holberton.h"

/**
 * _access - Checks if a file exists in a determinated directory
 * @s: The path to check
 *
 * Return: On success Nothing
 * On error, -1.
*/
int _access(char *s)
{
	return (access(s, F_OK));
}

/**
 * concat_path_points - Concatenate two strings when the path starts with :
 * @stru_v: The structure
 *
 * Return: On success Nothing
 * On error, -1.
*/
void concat_path_points(struct_v *stru_v)
{
	_strcpy(stru_v->string, "./");
	_strcat(stru_v->string, stru_v->token);
}

/**
 * concat_path_normal - Concatenate two strings from a structure normally
 * @stru_v: The structure
 *
 * Return: On success Nothing
 * On error, -1.
*/
void concat_path_normal(struct_v *stru_v)
{
	_strcpy(stru_v->string, stru_v->token_path);
	_strcat(stru_v->string, "/");
	_strcat(stru_v->string, stru_v->token);
}

/**
 * access_true - Function when the file exits in the path
 * @stru_v: The structure
 *
 * Return: On success nothing
 * On error, -1.
*/
void access_true(struct_v *stru_v)
{
	stru_v->token = stru_v->string;
	stru_v->accs_fail = 1;
}

/**
 * _strcmp_tok - Function that compare tokens
 * @stru_v: The structure
 *
 * Return: On success nothing
 * On error, -1.
*/
int _strcmp_tok(struct_v *stru_v)
{
	int cmp, len = _strlen(stru_v->token_path);

	cmp = _strncmp(stru_v->token, stru_v->token_path, len);
	return (cmp);
}
