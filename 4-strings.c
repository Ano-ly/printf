#include "main.h"
#include <stdlib.h>

/**
 * rev_string - prints a string in reverse
 * @num_list: the list to be parsed
 * Description - prints a string in reverse
 * Return: count of printed characters
 */

int rev_string(va_list num_list)
{
	int count;
	int n;
	char *buffer;

	n = 0;
	count = 0;

	buffer = va_arg(num_list, char *);
	if (buffer != NULL)
	{
		while (buffer[n] != '\0')
			n++;
		n--;
		while (n >= 0)
		{
			_putchar(buffer[n]);
			count++;
			n--;
		}
	}
	return (count);
}
