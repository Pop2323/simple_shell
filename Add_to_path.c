#include "shell.h"

/**
 * Add_to_path - func that add info to path
 *
 * @c: the input cmd
 * @p: the commond path
 *
 * Return: return buffer if success otherwise NULL
*/
char *Add_to_path(char *p, char *c)
{
	char *buffer;
	size_t i, j;

	if (c == NULL)
		c = "";
	if (p == NULL)
		p = "";
	buffer = malloc(sizeof(char) * (_strlen(p) + _strlen(c) + 2));
	if (!buffer)
		return (NULL);
	for (i = 0; p[i]; i++)
	{
		buffer[i] = p[i];
	}
	if (p[i - 1] != '/')
	{
		buffer[i++] = '/';
	}
	for (j = 0; c[j]; j++)
	{
		buffer[i + j] = c[j];
	}
	buffer[i + j] = '\0';
	return (buffer);
}
