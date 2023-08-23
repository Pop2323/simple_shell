#include "shell.h"

/**
 * return_env - func that will return the env
 *
 * Return: return void
*/
void return_env(void)
{
	char **env = environ;
	int i;

	for (i = 0; env[i]; i++)
	{
		write(STDOUT_FILENO, (const void *)env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
