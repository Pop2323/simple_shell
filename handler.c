#include "shell.h"

/**
 * is_all_spaces - func check that all spaces are empty
 *
 * @buf: check buf using iteration
 *
 * Return: return 1 if success othewise 0
*/
int is_all_spaces(char *buf)
{
	int i, value = 1;

	for (i = 0; buf[i] != '\0'; i++)
	{
		if (buf[i] != ' ')
		{
			value = 0;
			break;
		}
	}
	return (value);
}

/**
 * malloc_func - func tha malloc the memmory
 *
 * @num: unsigned integer num
 * @size: unsigned intger size
 *
 * Return: return void
*/
void *malloc_func(unsigned int num, unsigned int size)
{
	char *ptr = NULL;
	unsigned int k = 0;

	if (num && size)
	{
		if (num == 0 || size == 0)
			return (NULL);
		ptr = malloc(num * size);
		if (ptr == NULL)
			return (NULL);
		for (; k < (num * size); k++)
		{
			ptr[k] = 0;
			k++;
		}
	}
	return (ptr);
}

/**
 * get_env - func that custom find_env
 *
 * @find_env: char to ptr
 *
 * Return: return the get_env output
*/
char *get_env(char *find_env)
{
	int i = 0;
	int j = 0;
	int is_match = 1;

	while (environ[i] && is_match)
	{
		is_match = 1;
		while (environ[i][j] != '=' && environ[i][j] != '\0')
		{
			if (environ[i][j] != find_env[j])
			{
				is_match = 0;
			}
			j++;
		}
		if (is_match)
		{
			break;
		}
		i++;
	}
	return (&environ[i][j + 1]);
}

/**
 * find_env - func that custom the find_env
 *
 * Return: return void
*/
void find_env(void)
{
	int k;

	for (k = 0; environ[k] ; k++)
	{
		printf("%s\n", environ[k]);
	}
}

/**
 * find_path - func that find the path
 *
 * @comamnd: the comamnd line output
 *
 * Return: return the path founded
*/
char *find_path(char *comamnd)
{
	char *path = get_env("PATH");
	char *cp_path;
	char **path_elements;
	char *resolved_path = NULL;
	char *dlm = ":";

	struct stat info;
	int element_length = 0;
	int index = 0;

	if (stat(comamnd, &info) == 0)
		return (comamnd);
	cp_path = malloc(_strlen(path) + 1);
	cp_path = _strcpy(cp_path, path);
	path_elements = delim_separator(cp_path, dlm);

	while (path_elements[index])
	{
		element_length = _strlen(path_elements[index]);
		if (path_elements[index][element_length - 1] != '/')
			resolved_path = _strcat(path_elements[index], "/");
		resolved_path = _strcat(path_elements[index], comamnd);
		if (stat(resolved_path, &info) == 0)
			break;
		index++;
	}
	free(cp_path);
	if (!path_elements[index])
	{
		free(path_elements);
		return (NULL);
	}
	free(path_elements);
	return (resolved_path);
}
