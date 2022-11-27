#ifndef PRINTF
#define PRINTF
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
/**
 * struct format- entry point 
 * @f: input 
 * @p: inout 2
 */
typedef struct format
{
	char f;
	int (*p)(va_list, int);
} from;
int _printf(const char *format, ...);

int _putchar(char c);
int _isnumber(int, int);
int _compare(char, int, va_list);
int _validate(int, char, char);
int _strlen(const char *s);
int print_number(int, int);
int hexa(int x);
int positive(int, int, int);
int negative(int, int, int, int);
int print_binary(unsigned int, unsigned int);
int _rev(va_list arg, int len);
int print_rot13(va_list arg, int len);

int _char(va_list, int);
int _str(va_list, int);
int _int(va_list, int);
int _binary(va_list, int);
int _strspe(va_list, int);

#endif
