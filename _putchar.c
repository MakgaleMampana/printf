#include "main.h"

/**
 * _putchar - Prints a char to standard output
 * @c: char to be printed
 * Return: the char
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
