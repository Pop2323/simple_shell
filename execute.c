#include "shell.h"

/**
 * execute - funct that winn execute cmd
 *
 * @copy: char ptr that willcopy the cmd
 * @cmd: this the command
 *
 * Return: return void
*/
void execute(char *copy, char **cmd)
{
	int res;
	char **env = environ;
	pid_t my_pid;

	my_pid = fork();

	if (my_pid < 0)
		perror(copy);
	if (my_pid == 0)
	{
		execve(copy, cmd, env);
		perror(copy);
		free(copy);
		clear_buffer(cmd);
		exit(98);
	}
	else
		wait(&res);
}
