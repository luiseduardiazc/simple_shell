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
#define print_prompt write(STDIN_FILENO, "(: ", 3)
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
char *tok_path(char *token);
void split_input(char *command[], char *input);
void _exeve(char *command[], char *argv[], char *input);
/* main_loop.c */
int loop(char *argv[], char *envp[]);

#endif
