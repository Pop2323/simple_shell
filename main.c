#include "shell.h"

/**
 * main - function that similier the terminal
 *
 * @ac:  represents the num of cmd args
 * @av: this stands for arg vector
 *
 * Return: return res value
*/
int main(int ac, char **av)
{
	char *buf = NULL, *dlm = " \n";
	ssize_t linesize = 0;
	size_t buff_size = 0;
	int res = 0;
	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf(":) ");
		linesize = getline(&buf, &buff_size, stdin);
		if (linesize == -1 || _strcmp("exit\n", buf) == 0)
		{
			free(buf);
			break;
		}
		buf[linesize - 1] = '\0';
		if (_strcmp("env", buf) == 0)
		{
			find_env();
			continue;
		}
		if (is_all_spaces(buf) == 1)
		{
			res = 0;
			continue;
		}
		av = delim_separator(buf, dlm);
		av[0] = find_path(av[0]);
		if (av[0] != NULL)
		{
			res = execute(av);
		}
		else
		{
			perror("Error");
		}
		free(av);
	}
	return (res);
}

/**
 * execute - func that execute the cmd (termainal)
 *
 * @av: this stands for arg vector
 *
 * Return: return the reult value
*/
int execute(char **av)
{
	int result, pid;

	pid = fork();

	if (pid == 0)
	{
		if (execve(av[0], av, environ) == -1)
			perror("Error");
	}
	else
	{
		wait(&result);
		if (WIFEXITED(result))
			result = WEXITSTATUS(result);
	}
	return (result);
}
