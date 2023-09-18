#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
/*#include <stdio.h>*/

/**
 * _malloc - allocates suitable memory space for 'binary string'
 * @num_list: list of arguments
 * @base: conversion base
 * Definition - determines how many bytes of memory should be
 * allocated, and performs the memory allocation.
 * Return: count of printed characters
*/

int _malloc(va_list num_list, int base)
{
	int n;
	unsigned int num;
	char *buffer;
	unsigned int pow;
	int i;
	int count;

	n = 0;
	num = va_arg(num_list, unsigned int);

	while (1)
	{
		pow = 1;
		for (i = 0; i < n; i++)
		{
			pow *= base;
		}
		if (pow <= num)
			n++;
		else
			break;
	}
	buffer = malloc(sizeof(char) * n);
	/*printf("%d", n + 1);*/
	count = fill_buffer(buffer, num, n, base);
	return (count);
}
/*New function for handling %d starts here:*/

/**
 * _malloc2 - allocates suitable memory space for 'binary string'
 * @num_list: list of arguments
 * @base: conversion base
 *
 * Definition - determines how many bytes of memory should be
 * allocated, and performs the memory allocation.
 * Return: count of printed characters
*/

int _malloc2(va_list num_list, int base)
{
	int n;
	int num;
	char *buffer;
	int pow;
	int i;
	int count;

	n = 0;
	count = 0;
	num = va_arg(num_list, int);

	if (num < 0)
	{
		_putchar('-');
		num = -num;
		count++;
	}

	while (1)
	{
		pow = 1;
		for (i = 0; i < n; i++)
		{
			pow *= base;
		}
		if (pow <= num)
			n++;
		else
			break;
	}
	buffer = malloc(sizeof(char) * n);
	/*printf("%d", n + 1);*/
	count += fill_buffer(buffer, num, n, base);
	return (count);
}

/* New function ends here. */

/* Note that the definitions of functions _malloc and */
/* fill_buffer now have new parameter, ''base'*/


/**
 * fill_buffer - fills up previously allocated memory space
 * with binary, decimal, etc. digits
 * @buffer: memory space to be filled up
 * @num: number to be converted to binary
 * @n: size of memory space
 * @base: conversion base
 *
 * Definition - converts num to binary number and fills buffer
 * Return: count of printed characters
*/

int fill_buffer(char *buffer, int num, int n, int base)
{
	int quotient;
	int rem;
	int i;
	int count;

	i = 0;
	quotient = 1;

	while (quotient != 0)
	{
		quotient = num / base;
		rem = num % base;
		buffer[i] = rem + '0';
		num = quotient;
		i++;
	}
	/*printf("%d", n);*/
	count = print_rev_buffer(buffer, n);
	/*printf("COunt: %d", count);*/
	return (count);
}

/**
 * print_rev_buffer - prints a reversed string
 * @buffer: previously allocated memory space
 * @n: buffer size
 *
 * Definition - prints reversed string; needed to print binary
 * digits in the right order
 * Return: number of characters printed
*/

int print_rev_buffer(char *buffer, int n)
{
	int i;
	int sub2_count;

	sub2_count = 0;

	i = n - 1;
	while (i >= 0)
	{
		_putchar(buffer[i]);
		i--;
		sub2_count++;
	}
	/*printf("last funct sub2count: %d", sub2_count);*/
	free(buffer);
	return (sub2_count);
}
