#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
/*#include <stdio.h>*/

/**
  * _malloc3 - allocates suitable memory space for 'binary string'
  * @num_list: list of arguments
  * @base: conversion base
  * @caps: determines whether hexadecimal is capitalised
  * Definition - determines how many bytes of memory should be
  * allocated, and performs the memory allocation.
  * Return: count of printed characters
  */

int _malloc3(va_list num_list, int base, char caps)
{
	int n;
	unsigned long int num;
	char *buffer;
	unsigned long int pow;
	int i;
	int count;

	n = 0;
	num = va_arg(num_list, unsigned int);
	/*printf("NUM: %ld", num);*/
	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	while (1)
	{
		pow = 1;
		for (i = 0; i < n; i++)
		{
			pow *= base;
			/*printf("pow: %ld", pow);*/
		}
		if (pow <= num)
			n++;
		else
			break;
	}
	buffer = malloc(sizeof(char) * n);
	if (buffer == NULL)
		return (0);
	count = fill_buffer_hexa(buffer, num, n, base, caps);
	return (count);
}

/**
  * fill_buffer_hexa - fills up previously allocated memory space
  * with binary, decimal, etc. digits
  * @buffer: memory space to be filled up
  * @num: number to be converted to binary
  * @n: size of memory space
  * @base: conversion base
  * @caps: determines capitalisation of hexadecimal
  *
  * Definition - converts num to binary number and fills buffer
  * Return: count of printed characters
  */

int fill_buffer_hexa(char *buffer, long int num, int n, int base, char caps)
{
	long int quotient;
	int rem;
	int i;
	int count;

	i = 0;
	quotient = 1;

	while (quotient != 0)
	{
		quotient = num / base;
		/*printf("Quotient: %ld", quotient);*/
		rem = num % base;
		/*printf("REm: %d", rem);*/
		if (rem > 9)
			buffer[i] = caps + (rem - 10);
		else
			buffer[i] = rem + '0';
		num = quotient;
		i++;
	}
	count = print_rev_buffer(buffer, n);
	/*printf("Fillbufferhexa count: %d", count);*/
	return (count);
}
