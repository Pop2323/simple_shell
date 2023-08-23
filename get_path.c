#include "shell.h"

/**
 * get_path - func that find the path
 *
 * Return: return path if success otherwise NULL
*/
char *get_path(void)
{
	int i;
	char **env = environ, *p = NULL;

	for (; *env; env++)
	{
		if (strncmp(*env, "PATH=", 5) == 0)
		{
			p = *env;
			for (i = 0; *p && i < 5; i++)
			{
				p++;
			}
			return (p);
		}
	}
	return (NULL);
}
