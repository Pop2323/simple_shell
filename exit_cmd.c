#include "shell.h"

/**
 * terminate_cmd - functiont that terminate the command line
 *
 * @c: the command input by the user.
 * @input_line: the input avlue
 *
 * Return: return void
*/
char *terminate_cmd(char *c[], char *input_line)
{
	free(input_line);
	clear_buffer(c);
	exit(0);
}
