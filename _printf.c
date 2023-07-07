#include "main.h"

/**
 *_printf - prints formatted
 *@format: the format with which the function will print
 *Return: length of string printed
 */
int _printf(const char *format, ...)
{
	va_list arg;
	int i, len = 0, bytes = 0;

	if (format == NULL)
		return (-1);
	va_start(arg, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			while (format[i] - 48 >= 0 && format[i] - 48 <= 9)
			{
				len = _isnumber(len, (format[i] - 48));
				i++;
			}
			bytes += _validate(_compare(format[i], len, arg), format[i], format[i - 1]);
		}
		else if (format[i] == '%' && format[i + 1] == '\0')
		{
			return (-1);
		}
		else
		{
			bytes++;
			_putchar(format[i]);
		}
	}
	va_end(arg);
	return (bytes);
}
/**
 * _isnumber - length input
 * @len: actual value of length
 * @x: value of will be added
 * Return: length added
 */
int _isnumber(int len, int x)
{
	len *= 10;
	len += x;
	return (len);
}
/**
 * _compare - compare parameters with format
 * @format: actual value of format
 * @len: number of values that must be printed
 * @arg: list of arguments
 * Return: 0 if dont found any parameter
 */
int _compare(char format, int len, va_list arg)
{
	int j, flag = 0;
	form params[] = {
		{'c', _char},
		{'s', _str},
		{'d', _int},
		{'i', _int},
		{'b', _binary},
		{'S', _strspe},
		{'r', _rev},
		{'R', print_rot13},
		{'\0', NULL},
	};
	for (j = 0; params[j].f != '\0'; j++)
	{
		if (params[j].f == format)
		{
			flag = params[j].p(arg, len);
			break;
		}
		else
			flag = 0;
	}
	return (flag);
}
/**
 * _validate - valide the flag
 * @flag: 0 if not found parameter, -1 if string is null,
 * >= 1 flag is number of bytes
 * @actual: actual value of format
 * @percent: percentage
 * Return: Number of bytes that was printed
 */
int _validate(int flag, char actual, char percent)
{
	int bytes = 0;

	if (flag == 0 && (actual != 'i' && actual != 'd' && actual != 'S'
		    && actual != 'b'))
	{
		if (actual != '%')
		{
			_putchar(percent);
			bytes++;
		}
		_putchar(actual);
		bytes++;
	}
	if (flag == -1)
		return (bytes);
	if (flag >= 1)
		bytes += flag;
	return (bytes);
}
