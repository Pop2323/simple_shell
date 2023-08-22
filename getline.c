#include "shell.h"

/**
 * _getline - func that get the number of the input
 *
 * Return: return ptr of buffer
*/
char *_getline()
{
	char ch;
	char  *input;
	size_t buf_size = 1024, i = 0;
	static  char  *buffer, *copy;

	buffer  = malloc(sizeof(char) * buf_size);

	if (buffer == NULL)
		return (NULL);
	_memset(buffer, buf_size);
	input = buffer;
	ch = getchar();

		if (ch == -1)
		{
			buffer[0] = 0x04;
			return (buffer);
			while (!(ch == EOF || ch == '\n'))
				if (i > buf_size)
				{
					buf_size = buf_size * 2;
					copy = buffer;
					buffer = malloc(sizeof(char) * buf_size);
					if (buffer == NULL)
					{
						return (copy);
					}
					_memset(buffer, buf_size);
					_strcpy(copy, buffer);
					free(copy);
				}
			buffer[i] = ch;
			ch = getchar();
			i++;
		}
	if (input && i > 1024)
		free(input);
	return (buffer);
}
