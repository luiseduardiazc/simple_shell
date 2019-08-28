#include "holberton.h"

/**
* _env - Print the enviroment variables
* @stru_v: The structure with the variables
*
* Return: Nothing
* On error.
*/
void _env(struct_v *stru_v)
{
	int i, len;
	char *mssg;

	if (stru_v->command[1] == NULL)
	{
		for (i = 0; stru_v->envp[i] != NULL; i++)
		{
			len = _strlen(stru_v->envp[i]);
			write(STDOUT_FILENO, stru_v->envp[i], len);
			write(STDOUT_FILENO, "\n", 1);
		}
	}
	else
	{
		mssg = "No such file or directory";
		write(STDIN_FILENO, "env", _strlen("env"));
		write(STDIN_FILENO, ": ", 2);
		write(STDIN_FILENO, stru_v->command[1], _strlen(stru_v->command[1]));
		write(STDIN_FILENO, ": ", 2);
		write(STDIN_FILENO, mssg, _strlen(mssg));
		write(STDIN_FILENO, "\n", 1);
		exit(2);
	}
}
