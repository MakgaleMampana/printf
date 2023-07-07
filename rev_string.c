#include "main.h"

/**
 *print_rev - prints a string in reverse
 *
 *@s: pointer that will store the string's location
 *
 *Return: nothing
 */
void print_rev(const char *s)
{
	int p = 0;

	while (*s != 0)
	{
		s++;
		p++;
	}
	s--;
	while (p > 0)
	{
		_putchar(*s);
		s--;
		p--;
	}
}

/**
 * _rev - prints a string in reverse
 * @arg: list that contains the argument that will be printed
 * @len: Size specified to print (Spaces if len > string)
 *Return: amount of bytes printed
 */
int _rev(va_list arg, int len)
{
	const char *str;
	int i;

	str = va_arg(arg, char *);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if (*str == '\0')
		return (-1);
	i = _strlen(str);

	while (len > i)
	{
		write(1, " ", 1);
		len--;
	}

	print_rev(str);
	return (i);
}
