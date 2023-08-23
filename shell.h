#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <time.h>

/* env vars */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

/*main unc*/
char *check_path(char **p, char *c);
char *Add_to_path(char *p, char *c);
void terminate_cmd(char **c, char *input_line);
int find_builtin(char **c, char *input_line);
int checker(char **cmd, char *buffer);
char **tokenizer(char *input_line);
void handler(int n);
void output_env(void);
void user_input(void);

/*handler func*/
int _strlen(char *str);
int _strcmp(char *str1, char *str2);
char *_strchr(char *str, char ch);
char *_strdup(char *str);
int _strncmp(char *str1, char *str2, int num);
char *get_path(void);
void clear_buffer(char **buffer);
void execute(char *copy, char **cmd);

/**
 * struct flag_b - struct that contain two ptr char
 *
 * @env: ptr char that refer to envirnoment
 * @exit: ptr chat that refer to exit
 *
 * description: struct that contain two ptr char
*/
struct flag_b
{
	char *env;
	char *exit;
} flag_b;

/**
 * struct flag_t - struct that conatin two integer value
 *
 * @line_exit: int for exit
 * @line_count: int for count
 *
 * description: struct that conatin two integer value
*/
struct flag_t
{
	int line_exit;
	int line_count;
} flag_t;

/**
 * struct flag_f - struct that contain boolen value
 *
 * @flag: bool value for flag
 *
 * description: struct that contain boolen value
*/
struct flag_f
{
	bool flag;
} flag_f;

#endif
