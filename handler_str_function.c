#include "shell.h"

/**
 * _strlen - func that return the len of the str
 *
 * @str: the given string.
 *
 * Return: return the len of the str
*/
int _strlen(char *str)
{
	int len = 0;

	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

/**
 * _strchr - detecte the ch in the str
 *
 * @str: String that will be checked.
 * @ch: The char that will be detected
 *
 * Return: return the valueif success otherwise NULL
*/
char *_strchr(char *str, char ch)
{
	while (*str)
	{
		if (*str == ch)
			return (str);
	}
	if (!ch)
		return (str);
	return (NULL);
}
/**
 * _strncmp - funct that check two str
 *
 * @str1: str1 that will compare with str2
 * @str2: str2 that will compare with str1
 * @num: the intger value
 *
 * Return: return the between str1 and str2
*/
int _strncmp(char *str1, char *str2, int num)
{
	int i = 0;

	for (; str1[i] && str2[i] && i < num; i++)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	}
	return (0);
}

/**
 * _strcmp - func taht compare between str1 and str2
 *
 * @str1: str1 that will compare with str2
 * @str2: str2 that will compare with str1
 *
 * Return: return the between str1 and str2
*/
int _strcmp(char *str1, char *str2)
{
	int i, result;

	while (*(str1 + i) == *(str2 + i) && *(str1 + i) != '\0')
		i++;
	result = (*(str1 + i) - *(str2 + i));
	return (result);
}

/**
 * _strdup - fync that will duplicate the str
 *
 * @str: str that will be  duplicated
 *
 * Return: return the  duplicated value
*/
char *_strdup(char *str)
{
	int i = 0, str_len;
	char *res;

	if (str == NULL)
		return (NULL);
	str_len = _strlen(str);
	res = malloc(sizeof(char) * (str_len + 1));
	if (!res)
		return (NULL);
	for (; *str != '\0'; str++, i++)
		res[i] = str[0];
	res[i++] = '\0';
	return (res);
}
