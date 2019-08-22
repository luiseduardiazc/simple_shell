#include "holberton.h"
/**
 * _print_prompt - print prompt
 * @is_interactive_mode: interactive mode
 *
 * Return: Nothing.
 * None Error
*/
void _print_prompt(int is_interactive_mode)
{
	if (is_interactive_mode)
		print_prompt;

}
void _free(char *command[])
{
	int i;

	for (i = 0; command[i] != '\0'; i++)
		free(command[i]);
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
	char *command[BUFERSIZE], *input = NULL;
	size_t line, size = BUFERSIZE;
	int status, is_interactive_mode, flg = 0;
	(void)envp;

	is_interactive_mode = isatty(STDIN_FILENO);

	while (1)
	{
		_print_prompt(is_interactive_mode);

		line = getline(&input, &size, stdin);
		if (line == (size_t)-1 && line == (size_t)EOF)
			break;
		if (_strcmp(input, "exit\n") == 0)
			free(input), exit(EXIT_SUCCESS);

		split_input(command, input, &flg);
		if (command[0] != NULL)
		{
			if (_strcmp(command[0], "/bin/cd") == 0)
			{
				if (to_cd(command[1]) < 0)
				{
					perror(command[1]);
				}
				continue;
			}
		}
		child = fork();
		if (child == 0)
			_exeve(command, argv, input);
		wait(&status);
		if (flg == 1)
			free(command[0]);
	}
	free(input);
	return (status);
}
