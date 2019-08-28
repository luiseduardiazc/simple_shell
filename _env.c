#inlcude "holberton.h"

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
