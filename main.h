#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);

/**
 * struct op - Struct op
 *
 * @t: The term
 * @f: The function associated
 */
typedef struct op
{
	char *t;
	int (*f)(va_list *);
} op_t;

int sub_char(va_list *);
int sub_string(va_list *);
int sub_percent(va_list *);
int sub_int(va_list *);
int sub_dint(va_list *);

void print_substring(const char *, int, int);
int print_int_pos(int n);
int print_int_neg(int n);
int error_out(void);

#endif
