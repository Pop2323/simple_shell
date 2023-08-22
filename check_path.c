#include "shell.h"

/**
 * check_path - function that check the path
 *
 * @fn: file name char
 *
 * Return: return null
*/
char *check_path(char *fn)
{
	char *p, *path_copy;
	struct stat sb;
	int status;
	flag *head, *curr;

	curr = head;
	while (curr)
	{
		curr->path ? p = get_path(fn, curr->path) : curr = curr->next;
		if (!p)
		{
			free_list(head);
			return (NULL);
		}
		status = access(p, F_OK);
		status == 0 ? free_list(head) : curr = curr->next ? curr->next : NULL;
		free(p);
	}
	free_list(head);
	return (NULL);
}

/**
 * check_cwd - function that check the current working dir
 *
 * @fn: the filename path
 *
 * Return: return if success path otherwise null
*/
char *check_cwd(char *fn)
{
	char path;

	path = *get_cwd(char *fn);

	return ((access(path, F_OK | X_OK) == 0) ? path : (free(path), NULL));
}

/**
 * get_path - function that get the full path
 *
 * @fn: char file name
 *
 * @h: ptr char
 *
 * Return: return path
*/
char *get_path(char *fn, char *h)
{
	size_t i = 0, j = 0, len;
	char *path;

	len = strlen(fn) + strlen(h);
	path = malloc(sizeof(char) * len);
	if (path == NULL)
		return (NULL);
	_memset(path, len);
	for (; homedir[i]; i++)
	{
		path[i] = homedir[i];
	}
	path[++i] = '/';
	for (; filename[j]; j++)
	{
		path[++i] = filename[j];
	}
	return (path);
}
