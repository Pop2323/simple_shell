#include "shell.h"

/**
 * clear_buffer - function to claer or free buffer
 *
 * @buffer: char ptr to ptr to free buffer
 *
 * Return: return void
*/
void clear_buffer(char **buffer)
{
	int i = 0;

	if (!buffer)
		return;
	for (; buffer[i] != NULL; i++)
	{
		free(buffer[i]);
	}
	free(buffer);
}
