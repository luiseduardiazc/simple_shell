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
 * ret_path - Search in the enviroment variables the variable PATH
 * @stru_v: The structure with the variables
 *
 * Return: Nothing
 * On error.
*/
void ret_path(struct_v *stru_v)
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

/**
 * tok_path - Concatenate the input with the path
 * @stru_v: The structure of variables
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
	ret_path(stru_v);
	_strcpy(path_copy, stru_v->path);
	if (_strcmp(path_copy, "") == 0 && _access(stru_v->token) == 0)
	{
		stru_v->accs_fail = 1;
		return;
	}
	stru_v->token_path = _strtok_r(path_copy, delim2, &ptr_safe_strtok);
	while (stru_v->token_path != NULL)
	{
		comp = _strcmp_tok(stru_v);
		if (comp != 0)
		{
			if (path_copy[0] == ':')
				concat_path_points(stru_v);
			else
				concat_path_normal(stru_v);
			if (_access(stru_v->string) == 0)
			{
				access_true(stru_v);
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
 * @stru_v: The structure with the variables
 *
 * Return: nothing
 * On error, retunr NULL.
 */
void split_input(struct_v *stru_v)
{
	int i;
	char *ptr_safe_strtok;

	stru_v->token = _strtok_r(stru_v->input, delimiter, &ptr_safe_strtok);
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
		stru_v->token = _strtok_r(NULL, delimiter, &ptr_safe_strtok);
	}
	stru_v->command[i] = NULL;
}
/**
 * _exeve - execute comands
 * @stru_v: The structure of variables
 * Return: Nothing
 * On error EXIT_FAILURE
 */
void _exeve(struct_v *stru_v)
{
	/**
	* if (stru_v->accs_fail == 0)
	* {
	*	_exit(EXIT_SUCCESS);
	* }
	*/
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
