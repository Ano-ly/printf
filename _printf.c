#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

int specify(char spec, va_list values);

/**
 * _printf - custom printf function
 * @format: format string
 * @...: subsequent arguments
 *
 * Description - a custom printf function
 * Return: count of characters printed to stdout
*/

int _printf(const char *format, ...)
{
	int i;
	int count;
	char cursor;
	char spec;
	va_list values;

	count = 0;
	i = 0;

	va_start(values, format);

	if (format != NULL)
	{
		while (format[i] != '\0')
		{
			cursor = format[i];

			if (cursor != '%')
			{
				_putchar(cursor);
				cursor++;
				count++;
			}
			else
			{
				spec = format[i + 1];
				count += specify(spec, values);
				i++;
			}
			i++;
		}

	}
	va_end(values);
	return (count);
}

/**
 * specify - handles the specifiers c, s, %, d, and i
 * @spec: format specifier
 * @values: list of arguments
 *
 * Definition - handles format specifiers c, s, %, d, and i
 * Return: count of printed characters
*/

int specify(char spec, va_list values)
{
	char *value_str;
	int j;
	int sub_count = 0;

	if (spec == 'c')
	{
		_putchar(va_arg(values, int));
		sub_count++;
	}
	if (spec == 's')
	{
		value_str = va_arg(values, char *);
		if (value_str != NULL)
		{
			j = 0;
			while (value_str[j] != '\0')
			{
				_putchar(value_str[j]);
				sub_count++;
			j++;
			}
		}
	}
	if (spec == 'b')
	{
		sub_count += _malloc(values, 2);
	}

	if (spec == 'd' || spec == 'i')
		sub_count += _malloc2(values, 10);
	if (spec == 'u')
		sub_count += _malloc(values, 10);
	if (spec == 'o')
		sub_count += _malloc(values, 8);
	if (spec == 'x')
		sub_count += _malloc3(values, 16, 'a');
	if (spec == 'X')
		sub_count += _malloc3(values, 16, 'A');
	if (spec == '%')
	{
		_putchar('%');
		sub_count++;
	}
	return (sub_count);
}
