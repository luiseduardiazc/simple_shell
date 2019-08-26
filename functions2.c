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

void return_path(struct_v *stru_v)
{
	int i;

	for (i = 0; stru_v->envp[i] != NULL; i++)
	{
		if (_strncmp(stru_v->envp[i], "PATH", 4) == 0)
		{
			stru_v->path = stru_v->envp[i] + 5;
			break;
		}
	}
}

int _access(char *s)
{
	return (access(s, F_OK));
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
	int comp;
	char *ptr_safe_strtok;
	char path_copy[1024];

	stru_v->accs_fail = 0;
	return_path(stru_v);

	_strcpy(path_copy, stru_v->path);
	stru_v->token_path = _strtok_r(path_copy, delim2, &ptr_safe_strtok);

	while (stru_v->token_path != NULL)
	{
		comp = _strncmp(stru_v->token, stru_v->token_path, _strlen(stru_v->token_path));
		if (comp != 0)
		{
			strcpy(stru_v->string, stru_v->token_path);
			_strcat(stru_v->string, "/");
			_strcat(stru_v->string, stru_v->token);
			if (_access(stru_v->string) == 0)
			{
				stru_v->token = stru_v->string;
				stru_v->accs_fail = 1;
				break;
			}
		}
		else
		{
			if (_access(stru_v->token) == 0)
			{
				stru_v->accs_fail = 1;
				break;
			}
		}

		stru_v->token_path = _strtok_r(NULL, delim2, &ptr_safe_strtok);
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

	stru_v->token = strtok(stru_v->input, delimiter);
	for (i = 0; i < BUFERSIZE && stru_v->token != NULL; i++)
	{
		if (i == 0)
		{
			tok_path(stru_v);
			stru_v->command[i] = stru_v->token;
		} else
		{
			stru_v->command[i] = stru_v->token;
		}
		stru_v->token = strtok(NULL, delimiter);
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
	if (stru_v->accs_fail == 0)
	{
		printf("Error no encotnró path");
		_exit(EXIT_SUCCESS);
	}
	if (stru_v->command[0] == NULL)
	{
		_exit(EXIT_SUCCESS);
	}

	if (execve(stru_v->command[0], stru_v->command, stru_v->envp))
	{
		perror(stru_v->argv[0]);
		_exit(EXIT_FAILURE);
	}
}
