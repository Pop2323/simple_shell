#include "shell.h"

/**
 * user_input - func that show the input parameter
 *
 * Return: return void
*/
void user_input(void)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		flag_f.flag = 1;
	if (flag_f.flag)
		write(STDERR_FILENO, "$ ", 2);
}
