#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _printf - the big one
 * @format: the string with the slots that need substituting
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	op_t ops[] = {
		{"c", sub_char}, {"s", sub_string}, {"%", sub_percent},
		{"d", sub_int}, {"i", sub_dint}
	};
	va_list list;
	int i = 0;
	int j = 0;
	int len = 0;
	int startpos = 0;

	if (!format)
	{
		exit(98);
		return (-1);
	}
	va_start(list, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1])
			while (j < 5)
			{
				if (*ops[j].t == format[i + 1])
				{
					print_substring(format, startpos, (i - 1));
					len = len + (((i - 1) - startpos) + 1) + ops[j].f(&list);
					startpos = i + 2;
					i = startpos - 1;
				}
				j = j + 1;
			}
		else
			return (-1);

		j = 0;
		i = i + 1;
	}
	va_end(list);
	print_substring(format, startpos, (i - 1));
	return  (len + ((i - 1) - startpos) + 1);
}

/**
 * print_substring - prints chars between positions passed in
 * @format: the string pointer
 * @startpos: start position int
 * @endpos: end position int
 */
void print_substring(const char *format, int startpos, int endpos)
{
	int i = startpos;

	if (format)
	{
		while (i <= endpos)
		{
			write(1, format + i, 1);
			i = i + 1;
		}
	}
}
