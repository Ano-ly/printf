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
	unsigned long int pow;
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
	count = fill_buffer(buffer, num, n, base);
	/*printf("Binary count: %d", count);*/
	return (count);
}

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
	long int pow;
	int i;
	int count;
	long int num_long;

	n = 0;
	count = 0;
	num = va_arg(num_list, int);
	num_long = num;
	/*printf("/NUm: %d/", num);*/
	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	if (num_long < 0)
	{
		_putchar('-');
		num_long *= -1;
		count++;
	}
	while (1)
	{
		pow = 1;
		for (i = 0; i < n; i++)
			pow *= base;
		if (pow <= num_long)
			n++;
		else
			break;
	}
	buffer = malloc(sizeof(char) * n);
	if (buffer == NULL)
		return (0);
	count += fill_buffer(buffer, num_long, n, base);
	/*printf("/Upper function with minus count: %d\n/", count);*/

	return (count);
}

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

int fill_buffer(char *buffer, long int num, int n, int base)
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
		/*printf("/Quotient: %d/", quotient);*/
		rem = num % base;
		/*printf("/remainder: %d/", rem);*/
		buffer[i] = rem + '0';
		num = quotient;
		i++;
	}
	count = print_rev_buffer(buffer, n);
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
	free(buffer);
	/*printf("/sub2_count: %d\n/", sub2_count);*/
	return (sub2_count);
}
