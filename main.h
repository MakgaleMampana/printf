#ifndef PRINTF
#define PRINTF
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
/**
 * struct format - structure for printf format
 * @f: format char
 * @p: function for format
 */
typedef struct format
{
	char f;
	int (*p)(va_list, int);
} form;
/* main function */
int _printf(const char *format, ...);

/* side functions */
int _strlen(const char *s);
int _putchar(char c);
int print_number(int, int);
int _isnumber(int, int);
int _compare(char, int, va_list);
int hexa(int x);
int _validate(int, char, char);
int positive(int, int, int);
int negative(int, int, int, int);
int print_binary(unsigned int, unsigned int);
int _rev(va_list arg, int len);
int print_rot13(va_list arg, int len);

/* parameter functions */
int _char(va_list, int);
int _str(va_list, int);
int _int(va_list, int);
int _binary(va_list, int);
int _strspe(va_list, int);

#endif
