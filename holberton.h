#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#define BUFERSIZE 4052
#define delim " \t\n\r"
#define delim2 ":"
#define print_prompt write(STDIN_FILENO, "(: ", 3)

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
/* functions for _strtok */
size_t _strspn(const char *s1, const char *s2);
char *_strrchr(char *s, int c);
size_t _strcspn(const char *s1, const char *s2);
char *strchr(const char *s, int c);
char *_strtok_r(char *s, char *delim, char **context);
/* main_loop.c */
int loop(struct_v *stru_v);

#endif
