#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

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
	printf("%d", count);
	return (count);
}

/**
 * specify - handles the specifiers c, s and %
 * @spec: format specifier?
 * @values: list of arguments
 *
 * Definition - handles format specifiers c, s and %
 * Return: count of printed characters
*/

int specify(char spec, va_list values)
{
	char *value_str;
	int j;
	int sub_count;

	sub_count = 0;

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
	if (spec == '%')
	{
		_putchar('%');
		sub_count++;
	}
	/*printf("%d", sub_count);*/
	return (sub_count);
}
