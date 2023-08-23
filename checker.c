#include "shell.h"

/**
 * checker - func that check the builtin func.
 *
 * @cmd: this take the input from user.
 * @buffer: char ptr to buffer.
 *
 * Return: return 1 if success otherwise 0.
*/
int checker(char *cmd[], char *buffer)
{
	if (find_builtin(cmd, buffer))
		return (1);
	else if (**cmd == '/')
	{
		execute(cmd[0], cmd);
		return (1);
	}
	return (0);
}
