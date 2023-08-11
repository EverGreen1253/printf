#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * sub_int - prints signed integers
 * @list: the list
 *
 * Return: length of int chars
 */
int sub_int(va_list *list)
{
	int n = va_arg(*list, int);
	int len;
	int negative = 0;
	char *s;

	if (n < 0)
	{
		n = -1 * n;
		write(1, "-", 1);
		negative = 1;
	}

	len = print_int(n);

	if (negative == 1)
	{
		len = len + 1;
	}

	return (len);
}

/**
 * print_int - recursive func to print ints char by char
 * @n: num to print
 *
 * Return: length of digit printed
 */
int print_int(int n)
{
	int len = 0;
	int r = n % 10;
	char c = r + 48;

	if (n > 9)
	{
		len = len + print_int((n - r) / 10);
	}

	write(1, &c, 1);

	return (1);

}

/**
 * sub_dint - prints int values of different bases
 * @list: the list
 *
 * Return: length of digits printed
 */
int sub_dint(va_list *list)
{
	/**
	 * The numbers passed in could be in binary, hex or oct notation.
	 * That means they start with 0b, 0x
	 */

	sub_int(list);

	return (1);
}

