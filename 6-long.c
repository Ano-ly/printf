#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * _malloc6 - allocates suitable memory space for 'long binary string'
 * @num_list: list of arguments
 * @base: conversion base
 * Definition - determines how many bytes of memory should be
 * allocated, and performs the memory allocation.
 * Return: count of printed characters
*/

int _malloc6(va_list num_list, int base)
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
	count = fill_buffer_long(buffer, num, n, base);
	return (count);
}

/**
 * _malloc7 - allocates suitable memory space for 'long binary string'
 * @num_list: list of arguments
 * @base: conversion base
 *
 * Definition - determines how many bytes of memory should be
 * allocated, and performs the memory allocation.
 * Return: count of printed characters
*/

int _malloc7(va_list num_list, int base)
{
	int n;
	long int num;
	char *buffer;
	long int pow;
	int i;
	int count;

	n = 0;
	count = 0;
	/*printf("I'm here!");*/
	num = va_arg(num_list, long int);
	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
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
			pow *= base;
		if (pow <= num)
			n++;
		else
			break;
	}
	/*printf("buffer length: %d ", n);*/
	buffer = malloc(sizeof(char) * n);
	if (buffer == NULL)
		return (0);
	count += fill_buffer_long(buffer, num, n, base);
	/*printf("Upper function count: %d\n", count);*/

	return (count);
}

/**
 * fill_buffer_long - fills up previously allocated memory space
 * with long binary, decimal, etc. digits
 * @buffer: memory space to be filled up
 * @num: number to be converted to binary
 * @n: size of memory space
 * @base: conversion base
 *
 * Definition - converts num to binary number and fills buffer
 * Return: count of printed characters
*/

int fill_buffer_long(char *buffer, long int num, int n, int base)
{
	long int quotient;
	long int rem;
	long int i;
	int count;

	i = 0;
	quotient = 1;

	while (quotient != 0)
	{
		/*printf("num: %li",num);*/
		quotient = num / base;
		rem = num % base;
		/*printf("rem: %ld", rem);*/
		buffer[i] = rem + '0';
		num = quotient;
		i++;
	}
	count = print_rev_buffer(buffer, n);
	/*printf("Fill buffer long: %d", count);*/
	return (count);
}

