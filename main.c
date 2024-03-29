#include "holberton.h"
/**
 * alloc_memory_property - alloc_memory_property
 * @property: The pointer to allocate memory
 *
 * Description: This function allocate memory for each property
 * Return: Nothing
 */
char *alloc_memory_property(char *property)
{
	property = malloc(sizeof(char) * 100);
	if (!property)
	{
		return (NULL);
	}
	return (property);
}

/**
 * init_structure - Initialize a structure
 * @stru_v: The structure
 * @argv: The arguments passed by the user
 * @envp: The enviroment variables
 * @argc: The argc main
 * Description: This function initalize a structure
 * Return: Nothing
 */
void init_structure(struct_v *stru_v, char *argv[], char *envp[], int argc)
{
	stru_v->argv = argv;
	stru_v->envp = envp;
	stru_v->input = NULL;
	stru_v->token = NULL;
	stru_v->string = alloc_memory_property(stru_v->string);
	stru_v->token_path = NULL;
	stru_v->path = NULL;
	stru_v->command = malloc(sizeof(char **) * 10);
	stru_v->argc = argc;
}

/**
 * _free - Frees a structure
 * @stru_v: The structure
 *
 * Description: This function allocate memory for each property
 * Return: Nothing
 */
void _free(struct_v *stru_v)
{
	free(stru_v->command);
	free(stru_v->input);
	free(stru_v->token);
	free(stru_v->string);
	free(stru_v);
}
/**
 * sigintHandler - sigintHandler
 * @sig_num: num of signal
 *
 * Description: program that does not terminate when Ctrl+C is pressed
 * Return: Nothing
 */
void sigintHandler(int sig_num)
{
	(void)sig_num;

	signal(SIGINT, sigintHandler);
	fflush(stdout);
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

	stru_v = malloc(sizeof(struct_v));
	if (!stru_v)
		exit(EXIT_FAILURE);

	init_structure(stru_v, argv, envp, argc);
	signal(SIGINT, sigintHandler);
	status = loop(stru_v);
	_free(stru_v);
	exit(status);
}
