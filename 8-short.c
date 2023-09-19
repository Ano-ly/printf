#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
/*#include <stdio.h>*/

/**
  * _malloc8 - allocates suitable memory space for 'short binary string'
  * @num_list: list of arguments
  * @base: conversion base
  * Definition - determines how many bytes of memory should be
  * allocated, and performs the memory allocation.
  * Return: count of printed characters
  */

int _malloc8(va_list num_list, int base)
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
	count = fill_buffer_short(buffer, num, n, base);
	return (count);
}

/**
  * _malloc9 - allocates suitable memory space for 'short binary string'
  * @num_list: list of arguments
  * @base: conversion base
  
  * Definition - determines how many bytes of memory should be
  * allocated, and performs the memory allocation.
  * Return: count of printed characters
  */

int _malloc9(va_list num_list, int base)
{
	int n;
	short int num;
	char *buffer;
	short int pow;
	int i;
	int count;

	n = 0;
	count = 0;
	/*printf("I'm here!");*/
	num = va_arg(num_list, int);
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
	count += fill_buffer_short(buffer, num, n, base);
	/*printf("Upper function count: %d\n", count);*/

	return (count);
}

/**
  * fill_buffer_short - fills up previously allocated memory space
  * with short binary, decimal, etc. digits
  * @buffer: memory space to be filled up
  * @num: number to be converted to binary
  * @n: size of memory space
  * @base: conversion base
  
  * Definition - converts num to binary number and fills buffer
  * Return: count of printed characters
  */

int fill_buffer_short(char *buffer, short int num, int n, int base)
{
	short int quotient;
	short int rem;
	short int i;
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
	return (count);
}
