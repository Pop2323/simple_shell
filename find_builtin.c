#include "shell.h"

/**
 * find_builtin - func that handle andcheck builin func
 *
 * @c: the command input by the user.
 * @input_line: the input avlue
 *
 * Return: return 1 if success otherwise 0.
*/
int find_builtin(char **c, char *input_line)
{
	struct flag_b flag_b = {"env", "exit"};

	if (_strcmp(*c, flag_b.env) == 0)
	{
		output_env();
		return (1);
	}
	else if (_strcmp(*c, flag_b.exit) == 0)
	{
		terminate_cmd(c, input_line);
		return (1);
	}
	return (0);
}
