#include "shell.h"

/**
 * getcwd - fun that get the current working dir
 *
 * Return: return current working dir
*/
char *_getcwd()
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
	int length = 0, index = 0;
	char *curr_dir, *full_path;

	curr_dir = _getcwd();
	if (!curr_dir)
		return (NULL);
	while (curr_dir[length]) 
		length++;
	while (fn[index])
	{
		index++;
		length++;
	}
	full_path = malloc(sizeof(char) * (length + 1));
	if (!full_path)
		return (NULL);
	_memset(full_path, length + 1);
	length = 0;
	index = 0;
	while (curr_dir[length])
	{
		full_path[length] = curr_dir[length];
		length++;
	}
	full_path[length] = '/';
	length++;
	while (fn[index])
	{
		full_path[length + index] = fn[index];
		index++; 
	}
	free(curr_dir);
	return (full_path);
}
