#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
/*#include <stdio.h>*/

/**
 * _malloc10 - allocates suitable memory space for 'short hexadecimal
 * string number'
 * @num_list: list of arguments
 * @base: conversion base
 * @caps: determines whether hexadecimal is capitalised
 * Definition - determines how many bytes of memory should be
 * allocated, and performs the memory allocation.
 * Return: count of printed characters
*/

int _malloc10(va_list num_list, int base, char caps)
{
	int n;
	unsigned short int num;
	char *buffer;
	unsigned short int pow;
	int i;
	int count;

	n = 0;
	num = va_arg(num_list, unsigned int);
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
	count = fill_buffer_s_hexa(buffer, num, n, base, caps);
	return (count);
}

/**
  * fill_buffer_s_hexa - fills up previously allocated memory space for short
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

int fill_buffer_s_hexa(char *buffer, short int num, int n, int base, char caps)
{
	short int quotient;
	short int rem;
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
 * shortfunction - determines which _malloc function deals with specifier
 * @spec_loc: index of specifier
 * @str: format string
 * @values: list of arguments
 * Definition - needed to determine specifier that comes after l
 * Return: count of printed characters
 * and determinant of presence of two-member specifier
*/

int shortfunction(int spec_loc, const char *str, va_list values)

{
	char spec;
	int sub3_count;

	sub3_count = 0;

	spec = str[spec_loc + 1];
	/*printf("SPEC: '%c'", spec);*/
	if (spec == 'd' || spec == 'i')
		sub3_count = _malloc9(values, 10);
	if (spec == 'u')
		sub3_count = _malloc8(values, 10);
	if (spec == 'o')
		sub3_count = _malloc8(values, 8);
	if (spec == 'x')
		sub3_count = _malloc10(values, 16, 'a');
	if (spec == 'X')
		sub3_count = _malloc10(values, 16, 'A');
	/*printf("Sub3_count: %d", sub3_count);*/
	return (sub3_count);

}
