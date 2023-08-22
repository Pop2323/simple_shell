#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 * struct flags - the path of the file
 *
 * @path: this is the path to the file
 * @next: ptr to next file
 *
*/
typedef struct flags
{
	char *path;
	struct flags *next;
} flag;

size_t strlen(const char *s);
size_t wordlen(char **s);
int _strcpy(char *dest, char *src);
char *strtok(char *str, char **ptr, char s);
char *check_path(char *fn);
char *get_path(char *fn, char *h);
char *check_cwd(char *fn);
char *get_cwd(char *fn);
int _memset(char *mem, size_t size);
char *_getcwd();
flag *gethead();
void free_pointer(char *ptr);
void release_string_array_memory(char *argv[]);
int check_space(char *s);
int handle_line(char *input);
void exit_shell(char **, char *);
int handle_argv(char **argv, char *line, int env_set, int pre_in, int pre_st);
int _strcmp(char *dest, char *src);
int is_defined(char *argv1, char *argv2);
char *_abs_path(char **argv, char *cwd_path, char *path_in);
void free_all_memory(char *input, char **argv, char *cwd_path, char *path);
char *_getline();

#endif
