#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
/*#include <stdio.h>*/


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
	_struct res_struct;

	count = 0;
	i = 0;

	va_start(values, format);
	if (format == NULL)
		return (-1);
	while (format[i] != '\0')
	{
		cursor = format[i];

		if (cursor != '%')
		{
			_putchar(cursor);
			cursor++;
			count++;
			/*printf("Non-scount: %d\n", count);*/
		}
		else
		{
			spec = format[i + 1];
			res_struct = specify(format, i + 1, spec, values);
			if (res_struct.count == -1)
				return (-1);
			count += res_struct.count;
			i++;
			if (res_struct.flag_true != 0)
				i++;
		}
		i++;
	}

	va_end(values);
	return (count);
}

/**
  * specify - handles the specifiers c, s, %, d, and i
  * @spec: format specifier
  * @values: list of arguments
  * @str: format string
  * @spec_loc: index of format specifier
  *
  * Definition - handles format specifiers c, s, %, d, and i
  * Return: structure count of printed characters and flag_true
  */

_struct specify(const char *str, int spec_loc, char spec, va_list values)
{
	char *value_str;
	int j;
	int sub_count = 0;
	int flag = 0;
	struct _struct _specify;

	_specify.count = -1;
	_specify.flag_true = 0;

	if (spec == 's')
	{
		value_str = va_arg(values, char *);
		if (value_str == NULL)
			return (_specify);
		j = 0;
		while (value_str[j] != '\0')
		{
			_putchar(value_str[j]);
			sub_count++;
			j++;
		}

	}
	else if (str[spec_loc] == 'l')
	{
		flag = longfunction(spec_loc, str, values);
		if (flag != 0)
			sub_count = flag;
	}
	else if (str[spec_loc] == 'h')
	{
		flag = shortfunction(spec_loc, str, values);
		sub_count = flag;
	}
	else if (spec != 's' && spec != 'l' && spec != 'h')
		sub_count = specify_sub(str, spec_loc, spec, values);
	_specify.count = sub_count;
	_specify.flag_true = flag;
	return (_specify);
}

/**
 * specify_sub - completes specify function
 * @spec: format specifier
 * @values: list of arguments
 * Description - completes function specify
 * Return: count of printed character
*/

int specify_sub(const char *str, int spec_loc, char spec, va_list values)
{
	int flag;
	int sub_count = 0;

	flag = 0;

	if (spec == '+')
	{
		flag = choose1(spec_loc, str, values);
                sub_count = flag;
	}
	if (spec == ' ')
	{
		flag = choose3(spec_loc, str, values);
                sub_count = flag;
	}
	if (spec == '#')
	{
		flag = choose2(spec_loc, str, values);
                sub_count = flag;
	}
	if (spec == 'c')
	{
		_putchar(va_arg(values, int));
		sub_count = 1;
	}
	if (spec == 'b')
		sub_count = _malloc(values, 2);
	if (spec == 'd' || spec == 'i')
		sub_count = _malloc2(values, 10);
	if (spec == 'u')
		sub_count = _malloc(values, 10);
	if (spec == 'o')
		sub_count = _malloc(values, 8);
	if (spec == 'x')
		sub_count = _malloc3(values, 16, 'a');
	if (spec == 'X')
		sub_count = _malloc3(values, 16, 'A');
	if (spec == 'r')
		sub_count = rev_string(values);
	if (spec == 'R')
		sub_count = rot13(values);
	if (spec == '%')
	{
		_putchar('%');
		sub_count = 1;
	}
	/*printf("Sub count: %d", sub_count);*/
	return (sub_count);
}
