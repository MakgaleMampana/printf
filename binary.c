#include "main.h"

/**
 *_binary - prints a number in binary form
 *@arg: list that will contain the argument needed in order to print the binary
 *@len: Number of characters that will be printed if len > act_len print spaces
 *Return: amount of bytes printed
 */
int _binary(va_list arg, int len)
{
	int i, bytes = 0, cont;
	unsigned int x = va_arg(arg, unsigned int);
	int res[32];

	if (x ==  0)
	{
		_putchar('0');
		return (1);
	}
	for (cont = 0; x > 0; cont++)
	{
		res[cont] = x % 2;
		x = x / 2;
	}
	for (i = cont - 1; i >= 0; i--)
	{
		_putchar(res[i] + 48);
		bytes++;
	}
	while (len > 0)
	{
		_putchar(' ');
		bytes++, len--;
	}
	return (bytes);
}
