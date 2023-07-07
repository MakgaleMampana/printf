#include "main.h"

/**
 *rot13 - codes a string into rot 13
 *
 *@s: the pointer containing the string
 *
 *Return: the string already coded
 */
char *rot13(char *s)
{
	int i, j;
	char e1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char e2[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; e1[j] != '\0'; j++)
		{
			if (s[i] == e1[j])
			{
				write(1, (e2 + j), 1);
				break;
			}
		}
		if (j == 52)
			write(1, (s + i), 1);
	}
	return (s);
}

/**
 * print_rot13 - prints a string converted to rot13
 * @arg: list that contains the argument that will be printed
 * @len: Size specified to print (Spaces if len > string)
 *Return: amount of bytes printed
 */
int print_rot13(va_list arg, int len)
{
	char *str;
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
	rot13(str);

	return (i);
}
