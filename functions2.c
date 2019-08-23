#include "holberton.h"
/**
 * to_cd - invoke cd command
 * @path: The path
 *
 * Return: A integer.
 * On error, retunr NULL.
 */
int to_cd(char *path)
{
	return (chdir(path));
}

/**
 * tok_path - Concatenate the input with the path
 * @token: The token passed
 *
 * Return: A pointer.
 * On error, retunr NULL.
 */
void tok_path(struct_v *stru_v)
{
	int res, n = 5;
	_strcpy(stru_v->string, "/bin/");
	res = _strncmp(stru_v->token, stru_v->string, n);
	if (res != 0)
	{
		_strcat(stru_v->string, stru_v->token);
		stru_v->token = stru_v->string;
	}
}
/**
 * split_input - Split the input
 * @command: The array that has the commands
 * @input: The input obtained from getline
 *
 * Return: nothing
 * On error, retunr NULL.
 */
void split_input(struct_v *stru_v)
{
	int i;

	stru_v->token = strtok(stru_v->input, delim);
	for (i = 0; i < BUFERSIZE && stru_v->token != NULL; i++)
	{
		if (i == 0)
		{
			tok_path(stru_v);
			stru_v->command[i] = stru_v->token;
		} else
		{
			/* 
			   if (i == 1)
			   {
			   stru_v->token = stru_v->token + 2;
			   }
			 */
			stru_v->command[i] = stru_v->token;
		}
		stru_v->token = strtok(NULL, delim);
	}
	stru_v->command[i] = NULL;
}
/**
 * _exeve - execute comands
 * @command: Array of pointers
 * @argv: Enviroment variables
 * @input: input from user
 * Return: Nothing
 * On error EXIT_FAILURE
 */
void _exeve(struct_v *stru_v)
{
	if (stru_v->command[0] == NULL)
	{
		_exit(EXIT_SUCCESS);
	}

	if (execve(stru_v->command[0], stru_v->command, NULL))
	{
		perror(stru_v->argv[0]);
		_exit(EXIT_FAILURE);
	}
}
