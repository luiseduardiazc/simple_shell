#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include "holberton.h"
#define BUFERSIZE 50

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
char *tok_path(char *token)
{
	char *string, *realPoint;
	int res, n = 5;

	string = malloc(sizeof(char) * 50);
	if (!string)
		return (NULL);
	_strcpy(string, "/bin/");
	res = _strncmp(token, string, n);
	if (res == 0)
		realPoint = token;
	else
	{
		_strcat(string, token);
		return (string);
	}
	free(string);
	return (realPoint);
}

/**
 * split_input - Split the input
 * @command: The array that has the commands
 * @input: The input obtained from getline
 *
 * Return: nothing
 * On error, retunr NULL.
 */
void split_input(char *command[], char *input)
{
	char *token;
	int i;

	token = strtok(input, " \t\n\r");
	command[0] = tok_path(token);
	for (i = 1; i < strlen(*command) && token != NULL; i++)
	{
		token = strtok(NULL, " \t\n\r");
		command[i] = token;
	}
	command[i] = NULL;
}

/**
 * loop - loop for the prompt
 * @argv: Array of pointers to parameters
 * @envp: Enviroment variables
 *
 * Return: An integer
 * On error, -1 is returned, and errno is set appropriately.
 */
int loop(char *argv[], char *envp[])
{
	pid_t child;
	char *command[BUFERSIZE], *token, *input = NULL;
	size_t line, size = BUFERSIZE;
	int status;

	while (1)
	{
		printf(":) ");
		line = getline(&input, &size, stdin);

		if (line == -1 && line == EOF)
			break;
		if (strcmp(input, "exit\n") == 0)
			free(input), exit(EXIT_SUCCESS);

		split_input(command, input);

		if (strcmp(command[0], "/bin/cd") == 0)
		{
			if (to_cd(command[1]) < 0)
			{
				perror(command[1]);
			}
			continue;
		}
		child = fork();
		if (child == 0)
		{
			if (execve(command[0], command, NULL))
			{
				perror(argv[0]);
				free(input);
				_exit(EXIT_FAILURE);
			}
		}
		wait(&status);
	}
	free(input);
	return (status);
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
	int status;
	(void)envp;
	status = loop(argv, envp);
	exit(status);
}
