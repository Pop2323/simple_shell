#include "shell.h"

/**
* _putchar - func that wwill print the char
*
* @c: the char that will print
*
* Return: return 1 if success othewise 0
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* print_str - func that will print the str
* @str: the str that will be printed
*
* Return: return the num of the char
*/
int print_str(char *str)
{
	int res = 0;

	while (str[res] != '\0')
	{
		_putchar(str[res]);
		res++;
	}
	return (res);
}
