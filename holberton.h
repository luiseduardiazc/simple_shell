#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#define BUFERSIZE 4052
#define delimiter " \t\n\r"
#define delim2 ":"
#define print_prompt write(STDIN_FILENO, "(: ", 3)


/**
  * struct struct_s - Struct that contain the variables to use
  * @accs_fail: The flag to indicate if is neccesary the free
  * @string: String to store the concatenation of the token and path
  * @input: Th input of user
  * @token: The token to separate the user input
  * @path: The enviroment path
  * @token_path: The token used to separate the path
  * @command: Array of pointer to store the commands and pass to excev
  * @argv: The arguments passed by user
  * @envp: The enviroment variables
  *
  * Description: DS to storage all required variable to do a shell interpreter
  */
typedef struct struct_s
{
	int accs_fail;
	char *string;
	char *input;
	char *token;
	char *path;
	char *token_path;
	char **command;
	char **argv;
	char **envp;
} struct_v;

/* functions0.c functions1.c */
int _strlen(char *s);
char *str_concat(char *s1, char *s2);
char *_strstr(char *haystack, char *needle);
int _strcmp(char *s1, char *s2);
char *_strncpy(char *dest, char *src, int n);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strncmp(char *s1, char *s2, int n);

/* functions2.c */
int to_cd(char *path);
void tok_path(struct_v *stru_v);
void split_input(struct_v *stru_v);
void _exeve(struct_v *stru_v);

/* functions3.c */
void concat_path_points(struct_v *stru_v);
void concat_path_normal(struct_v *stru_v);
void access_true(struct_v *stru_v);
int _access(char *s);
int _strcmp_tok(struct_v *stru_v);

/* functions for _strtok */
int _strspn(const char *s1, const char *s2);
char *_strrchr(char *s, int c);
int _strcspn(const char *s1, const char *s2);
char *_strchr(const char *s, int c);
char *_strtok_r(char *s, char *delim, char **context);
/* main_loop.c */
int loop(struct_v *stru_v);

ssize_t getline(char **lineptr, size_t *n, FILE *stream);

#endif
