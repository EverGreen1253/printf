#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
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
		{"c", sub_char},
		{"s", sub_string},
		{"%", sub_percent},
		{"d", sub_int},
		{"i", sub_dint}
	};
	va_list list;
	int i = 0;
	int j = 0;
	int len = 0;
	int temp = 0;
	char *output;
	int startpos = 0;
	int endpos;

	va_start(list, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			endpos = i - 1;
			while (j < 5)
			{
				if (*ops[j].t == format[i + 1])
				{
					len = len + (endpos - startpos) + 1;
					
					// printf("\nStartpos - %d, Endpos - %d, len - %d\n", startpos, endpos, ((endpos - startpos) + 1));

					print_substring(format, startpos, endpos);

					startpos = i + 2;

					len = len + ops[j].f(&list);

					/**
					 * + 1 if conversion specifier found and end the ops comparison loop
					 * the next increment to i in the main loop will place i nicely on the
					 * next character after the specifier
					 */

					i = startpos - 1;
					j = 5;
				}
				j = j + 1;
			}
		}

		j = 0;
		i = i + 1;
	}
	va_end(list);

	endpos = i - 1;
	len = len + (endpos - startpos) + 1;

	// printf("\nStartpos - %d, Endpos - %d, len - %d\n", startpos, endpos, ((endpos - startpos) + 1));

	print_substring(format, startpos, endpos);

	// printf("Final Length - %d\n", len);

	return (len);
}

void print_substring(const char *format, int startpos, int endpos)
{
	int i = startpos;

	while (i <= endpos)
	{
		write(1, format + i, 1);
		i = i + 1;
	}
}
