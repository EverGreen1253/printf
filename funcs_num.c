#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
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
	int len = 0;

	if (n < 0)
	{
		write(1, "-", 1);
		len = print_int_neg(n) + 1;
	}
	else if (n == 0)
	{
		write(1, "0", 1);
		len = 1;
	}
	else
	{
		len = print_int_pos(n);
	}

	return (len);
}

/**
 * print_int_pos - recursive func to print a pos int char by char
 * @n: num to print
 *
 * Return: length of digit printed
 */
int print_int_pos(int n)
{
	int len = 1;
	int r = n % 10;
	char c = r + 48;

	if (n > 9)
	{
		len = len + print_int_pos((n - r) / 10);
	}

	write(1, &c, 1);

	return (len);
}

/**
 * print_int_neg - recursive func to print a neg int char by char
 * @n: num to print
 *
 * Return: length of digit printed
 */
int print_int_neg(int n)
{
	int len = 1;
	int r =  -(n % 10);
	char c = r + 48;

	if (n < -9)
	{
		len = len + print_int_neg((n + r) / 10);
	}

	write(1, &c, 1);

	return (len);
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

