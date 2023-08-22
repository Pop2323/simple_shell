#include "shell.h"

/**
 * getcwd - fun that get the current working dir
 *
 * Return: return current working dir
*/
char *getcwd()
{
	char *current_dir = NULL;
	int s = 100;
	char *free_m;

	for (;;)
	{
		current_dir = getcwd(current_dir, s);
		if (current_dir != NULL)
		{
			break;
		}
		free_m = current_dir;
		s = s * 2;
		free(free_m);
	}
	return (current_dir);
}

/**
 * get_cwd - func get current working dir path
 *
 * @fn: ptr for file name path
 *
 * Return: return the path of filename in cwd
*/
char *get_cwd(char *fn)
{
	char *current_dir, *path;
	int i, j;

	current_dir = getcwd();
	if (!current_dir)
		return (NULL);
	for (i = 0; current_dir[i]; i++)
		;
	for (j = 0; fn[j]; j++)
		;
	path = malloc(sizeof(char) * (i + j + 2));
	if (!path)
		return (NULL);
	_memset(path, 0, i + j + 2);
	for (i = 0; current_dir[i]; i++)
	{
		path[i] = current_dir[i];
	}
	path[i++] = '/';
	for (j = 0; fn[j]; j++)
	{
		path[i++] = fn[j];
	}
	free(current_dir);
	return (path);
}
