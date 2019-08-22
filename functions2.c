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
char *tok_path(char *token, int *flg)
{
	char *string;
	int res, n = 5;

	string = malloc(sizeof(char) * 50);
	if (!string)
		return (NULL);
	_strcpy(string, "/bin/");
	res = _strncmp(token, "/bin/", n);
	if (res == 0)
	{
		*flg = 0;
		free(string);
		return (token);
	}
	else
	{
		*flg = 1;
		_strcat(string, token);
		return (string);
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
void split_input(char *command[], char *input, int *flg)
{
	char *token;
	int i;

	token = strtok(input, delim);
	for (i = 0; token != NULL; i++)
	{
		if (i == 0)
		{
			command[i] = tok_path(token, flg);
		} else
		{
			command[i] = token;
		}
		token = strtok(NULL, delim);
	}
	command[i] = NULL;
}
/**
 * _exeve - execute comands
 * @command: Array of pointers
 * @argv: Enviroment variables
 * @input: input from user
 * Return: Nothing
 * On error EXIT_FAILURE
 */
void _exeve(char *command[], char *argv[], char *input)
{
	if (command[0] == NULL)
	{
		free(input);
		free(*command);
		_exit(EXIT_SUCCESS);
	}

	if (execve(command[0], command, NULL))
	{
		perror(argv[0]);
		free(input);
		_exit(EXIT_FAILURE);
	}
}

