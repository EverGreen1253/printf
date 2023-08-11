#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "main.h"

int sub_char(va_list *list)
{
	char c = va_arg(*list, int);
	write(1, &c, 1);

	return 1;
}

int sub_string(va_list *list)
{
	char *s = va_arg(*list, char *);
	int i = 0;

	while (s[i] != '\0')
	{
		i = i + 1;
	}
	write(1, s, i);

	return i;
}

int sub_percent(va_list *list)
{
	/**
	 * OK. I played cheat by printing out the percentage directly.
	 * But we still need to call va_arg to move on to the next arg in the list.
	 */
	char c = va_arg(*list, int);
	write(1, "%", 1);

	return 1;
}

