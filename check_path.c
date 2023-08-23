#include "shell.h"

/**
 * check_path - func that check the path is correct
 *
 * @p: char ptr to ptr to path
 * @c: the user input
 *
 * Return: return path if success otherwise NULL
*/
char *check_path(char *p[], char *c)
{
	char *res;
	int i = 0;

	for (; path[i]; i++)
	{
		res = Add_to_path(p[i], c);
		if (access(res, F_OK | X_OK) == 0)
			return (res);
		free(res);
	}
	return (NULL);
}
