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


#endif
