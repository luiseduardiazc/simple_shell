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

	for (i = 0; stru_v->envp[i] != NULL; i++)
	{
		len = _strlen(stru_v->envp[i]);
		write(STDOUT_FILENO, stru_v->envp[i], len);
	}
}
