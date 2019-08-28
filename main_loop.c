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
/**
 * command_not_found - Print the error
 * @stru_v: The structure
 *
 * Return: Nothing.
 * None Error
 */
void command_not_found(struct_v *stru_v)
{
	char error[1024];

	_strcpy(error, stru_v->argv[0]);
	_strcat(error, ": 1: ");
	_strcat(error, stru_v->input);
	_strcat(error, ": not found\n");
	write(STDOUT_FILENO, error, _strlen(error));
}
/**
 * loop - loop for the prompt
 * @stru_v: The structure
 *
 * Return: An integer
 * On error, -1 is returned, and errno is set appropriately.
 */
int loop(struct_v *stru_v)
{
	pid_t child;
	size_t line, size = BUFERSIZE;
	int status = 0, is_interactive_mode;

	is_interactive_mode = isatty(STDIN_FILENO);
	while (1)
	{
		_print_prompt(is_interactive_mode);
		line = getline(&stru_v->input, &size, stdin);
		if (line == (size_t)-1 && line == (size_t)EOF)
			break;
		if (_strcmp(stru_v->input, "exit\n") == 0)
			break;
		if (_strcmp(stru_v->input, "\n") == 0)
		{
			if (is_interactive_mode)
				continue;
			else
				break;
		}
		split_input(stru_v);
		if (stru_v->command[0] != NULL)
		{
			if (_strcmp(stru_v->command[0], "/bin/cd") == 0)
			{
				if (to_cd(stru_v->command[1]) < 0)
					perror(stru_v->command[1]);
				continue;
			}
		}
		child = fork();
		if (child == 0)
			_exeve(stru_v);
		wait(&status);
		/**
		* if (stru_v->accs_fail == 0)
		*	command_not_found(stru_v);
		*/
	}
	return (status);
}
