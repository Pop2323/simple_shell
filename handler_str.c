#include "shell.h"

/**
 * _strcpy - func that copy the str1
 *
 * @str1: the first str
 * @str2: the second str
 *
 * Return: return the copied str
*/
char *_strcpy(char *str1, char *str2)
{
	char *str = str1;

	while (*str2 != '\0')
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
	return (str);
}

/**
 * _strcat - func that concatenates two strs
 *
 * @str1: the first str that will be concatenate
 * @str2: the second str that will be concatenate
 *
 * Return: return the concatenate str
*/
char *_strcat(char *str1, char *str2)
{
	int i = 0, j = 0;

	while (str1[i] != '\0')
	{
		i++;
	}
	while (str2[j] != '\0')
	{
		str1[i] = str2[j];
		i++;
		j++;
	}
	str1[i] = '\0';
	return (str2);
}

/**
 * _strcmp - func that compare between two str
 *
 * @str1: the first string
 * @str2: the second string
 *
 * Return: return the difference between the two str
*/
int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}

/**
 * _strlen - func that return the length of the str
 *
 * @str: the str passed
 *
 * Return: return the length of the str
*/
int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

/**
 * delim_separator - separet the str using delimiter
 *
 * @str: the string value
 * @dlm: the delimiter symbol
 *
 * Return: return str value
*/
char **delim_separator(char *str, char *dlm)
{
	char *current_segment, **result_segments;
	int i = 0;

	current_segment = strtok(str, dlm);
	result_segments = (char **)malloc_func(100, sizeof(char *));
	if (!result_segments)
	{
		free(result_segments);
		return (NULL);
	}
	while (current_segment)
	{
		result_segments[i] = current_segment;
		current_segment = strtok(NULL, dlm);
		i++;
	}
	return (result_segments);
}
