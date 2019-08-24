#include "holberton.h"
/**
 * alloc_memory_struct - alloc memory struct
 * Description: This function allocate memory for structure
 * Return: Nothing
 */
struct_v *alloc_memory_struct()
{
	struct_v *stru_v;

	stru_v = malloc(sizeof(struct_v));
	if (!stru_v)
		return (NULL);
	return (stru_v);
}
/**
 * alloc_memory_property - alloc_memory_property
 * Description: This function allocate memory for each property
 * Return: Nothing
 */
char *alloc_memory_property(char *property)
{
	property = malloc(sizeof(char)* 100);
	if (!property)
	{
		return (NULL);
	}
	return (property);
}

void init_structure(struct_v *stru_v, char *argv[], char *envp[])
{
	stru_v->argv = argv;
	stru_v->envp = envp;
	stru_v->input = NULL;
	stru_v->token = NULL;
	stru_v->string = NULL;
	stru_v->token_path = NULL;
	stru_v->path = NULL;
	stru_v->command = malloc(sizeof(char **) * 10);
}

void _free(struct_v *stru_v)
{

	free(stru_v->command);
        free(stru_v->input);
        free(stru_v->token);
	free(stru_v->string);
	free(stru_v->token_path);
	free(stru_v->path);
	free(stru_v);
}
/**
 * main - entry point
 * @argv: Array of pointers to parameters
 * @argc: count of parameters
 * @envp: Enviroment variables
 *
 * Return: OStatus
 * On error, -1 is returned, and errno is set appropriately.
 */
int main(int argc, char *argv[], char *envp[])
{
	int status = 0;
	struct_v *stru_v = NULL;
	(void)envp;
	(void)argc;
	stru_v = alloc_memory_struct();
	init_structure(stru_v, argv, envp);
	status = loop(stru_v);
	printf("bye");
	_free(stru_v);
	exit(status);
}
