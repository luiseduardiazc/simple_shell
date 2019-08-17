#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

#define BUFERSIZE 50

int to_cd(char *path)
{
	return (chdir(path));
}

char *tok_path(char *token)
{
	char *string = "/bin/", *realPoint;
	int res, n = 5;

	res = _strncmp(token, string, n);
	if (res == 0)
		realPoint = token;
	else
		realPoint = str_concat(token, string);
	return (realPoint);
}

int main(int argc, char *argv[], char *envp[])
{
	pid_t child;
	char *command[BUFERSIZE], *token, *input = NULL;
	size_t i, size;
	int status;
	(void)envp;
	while (1)
	{
		printf(":) ");
		getline(&input, &size, stdin);
		/* printf("input %s\n", input); */

		if (strcmp(input, "exit\n") == 0)
			exit(EXIT_SUCCESS);

		token = strtok(input, " \t\n\r");
		for (i = 0; i < strlen(*command) && token != NULL; i++)
		{
			command[i] = tok_path(token);
			token = strtok(NULL, " \t\n\r");
		}
		command[i] = NULL;
		if (strcmp(command[0], "cd") == 0)
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
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		if (child > 0)
			waitpid(child, &status, WUNTRACED);
	}
	free(input);
	putchar('\n');
	exit(status);
}
