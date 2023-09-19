#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
/*#include <stdio.h>*/

/**
 * _malloc5 - allocates suitable memory space for 'long hexadecimal
 * string number'
 * @num_list: list of arguments
 * @base: conversion base
 * @caps: determines whether hexadecimal is capitalised
 * Definition - determines how many bytes of memory should be
 * allocated, and performs the memory allocation.
 * Return: count of printed characters
*/

int _malloc5(va_list num_list, int base, char caps)
{
	int n;
	unsigned long int num;
	char *buffer;
	unsigned long int pow;
	int i;
	int count;

	n = 0;
	num = va_arg(num_list, unsigned long int);
	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	while (1)
	{
		pow = 1;
		for (i = 0; i < n; i++)
			pow *= base;
		if (pow <= num)
			n++;
		else
			break;
	}
	buffer = malloc(sizeof(char) * n);
	if (buffer == NULL)
		return (0);
	count = fill_buffer_l_hexa(buffer, num, n, base, caps);
	return (count);
}

/**
  * fill_buffer_l_hexa - fills up previously allocated memory space for long
  * int with hexadecimal digits
  * @buffer: memory space to be filled up
  * @num: number to be converted to binary
  * @n: size of memory space
  * @base: conversion base
  * @caps: determines capitalisation of hexadecimal
  *
  * Definition - converts num to binary number and fills buffer
  * Return: count of printed characters
  */

int fill_buffer_l_hexa(char *buffer, long int num, int n, int base, char caps)
{
	long int quotient;
	long int rem;
	int i;
	int count;

	i = 0;
	quotient = 1;

	while (quotient != 0)
	{
		quotient = num / base;
		rem = num % base;
		if (rem > 9)
			buffer[i] = caps + (rem - 10);
		else
			buffer[i] = rem + '0';
		num = quotient;
		i++;
	}
	count = print_rev_buffer(buffer, n);
	return (count);
}

/**
 * longfunction - determines which _malloc function deals with specifier
 * @spec_loc: index of specifier
 * @str: format string
 * @values: list of arguments
 * Definition - needed to determine specifier that comes after l
 * Return: count of printed characters
 * and determinant of presence of two-member specifier
*/

int longfunction(int spec_loc, const char *str, va_list values)
{
	char spec;
	int sub3_count;

	sub3_count = 0;

	spec = str[spec_loc + 1];
	/*printf("SPEC: '%c'", spec);*/
	if (spec == 'd' || spec == 'i')
		sub3_count = _malloc7(values, 10);
	if (spec == 'u')
		sub3_count = _malloc6(values, 10);
	if (spec == 'o')
		sub3_count = _malloc6(values, 8);
	if (spec == 'x')
		sub3_count = _malloc5(values, 16, 'a');
	if (spec == 'X')
		sub3_count = _malloc5(values, 16, 'A');
	/*printf("Sub3_count: %d", sub3_count);*/
	return (sub3_count);

}
