#include "holberton.h"
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
	int status;
	(void)envp;
	(void)argc;
	status = loop(argv, envp);
	exit(status);
}
