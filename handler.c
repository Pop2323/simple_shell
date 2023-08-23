#include "shell.h"

/**
 * handler - func that handle that command status
 *
 * @n:integer number
 *
 * Return: return void
*/
void handler(int n)
{
	char new_line = '\n';
	char prompt[] = "$ ";
	(void)n;

	write(STDERR_FILENO, &new_line, 1);
	write(STDERR_FILENO, prompt, sizeof(prompt) - 1);
}
