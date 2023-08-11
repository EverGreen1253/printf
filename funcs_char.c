#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * sub_char - prints a single char
 * @list: the list
 *
 * Return: length of char(s) printed
 */
int sub_char(va_list *list)
{
	char c = va_arg(*list, int);

	write(1, &c, 1);

	return (1);
}

/**
 * sub_string - prints the string, char by char
 * @list: the list
 *
 * Return: length of char(s) printed
 */
int sub_string(va_list *list)
{
	char *s = va_arg(*list, char *);
	int i = 0;

	while (s[i] != '\0')
	{
		i = i + 1;
	}
	write(1, s, i);

	return (i);
}

/**
 * sub_percent - prints the percentage char
 * @list: the list
 *
 * Return: length of char(s) printed
 */
int sub_percent(va_list *list)
{
	if (list != NULL)
	{
		write(1, "%", 1);
	
		return (1);
	}
	return (0);
}

