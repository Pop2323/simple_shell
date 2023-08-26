#ifndef SHELL_H
#define SHELL_H

extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

char *_strcpy(char *str1, char *str2);
char *_strcat(char *str1, char *str2);
int _strcmp(char *str1, char *str2);
int _strlen(char *str);
char **delim_separator(char *str, char *dlm);
int is_all_spaces(char *buff);
void *malloc_func(unsigned int num, unsigned int size);
char *get_env(char *find_env);
void find_env(void);
int execute(char **av);
char *find_path(char *comamnd);

#endif
