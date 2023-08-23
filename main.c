#include "shell.h"

/**
 * main - this the main func
 *
 * @ac: the number of items in av
 * @av: the a NULL terminated array of str
 * @env: env is a NULL terminated array of strings
 *
 * Return: return 0
*/
int main(int ac, char **av, char *env[])
{
	char *input_line = NULL, *resolved_command = NULL, *p = NULL;
	char **c = NULL, **path_tokens = NULL;
	ssize_t input_line_size = 0;
	size_t buffersize = 0;

	if (ac < 1)
		return (-1);
	(void)env;
	(void)av;
	signal(SIGINT, handler);
	while (1)
	{
		user_input();
		input_line_size = get_line(&input_line, &buffersize, stdin);
		if (input_line_size < 0)
			break;
		flag_t._count++;
		if (input_line[input_line_size - 1] == '\n')
			input_line[input_line_size - 1] = '\0';
		c = tokenizer(input_line);
		if (c != NULL && *c != NULL && **c != '\0')
			continue;
		if (!checker(c, input_line))
			continue;
		p = get_path();
		path_tokens = tokenizer(p);
		resolved_command = check_path(path_tokens, c[0]);
		if (!resolved_command)
			perror(av[0]);
		else
			execute(resolved_command, c);
		clear_buffer(c);
		clear_buffer(path_tokens);
		free(resolved_command);
	}
	if (input_line_size < 0 && flag_f.flag)
		write(STDERR_FILENO, "\n", 1);
	free(input_line);
	return (0);
}
