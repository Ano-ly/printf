#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
/*#include <stdio.h>*/

/**
 * _malloc11 - allocates suitable memory space for 'octal string' with # flag
 * @num_list: list of arguments
 * @base: conversion base
 * Definition - determines how many bytes of memory should be
 * allocated, and performs the memory allocation.
 * Return: count of printed characters
*/

int _malloc11(va_list num_list, int base)
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
	if (base == 8)
		_putchar(48);

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
 * _malloc12 - allocates suitable memory space for 'ternary string' with
 * +flag
 * @num_list: list of arguments
 * @base: conversion base
 *
 * Definition - determines how many bytes of memory should be
 * allocated, and performs the memory allocation.
 * Return: count of printed characters
*/

int _malloc12(va_list num_list, int base)
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
	if (num_long > 0)
		_putchar('+');
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
 * _malloc14 - allocates suitable memory space for 'ternary string' with
 * space flag
 * @num_list: list of arguments
 * @base: conversion base
 *
 * Definition - determines how many bytes of memory should be
 * allocated, and performs the memory allocation.
 * Return: count of printed characters
*/

int _malloc14(va_list num_list, int base)
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
	if (num_long > 0)
		_putchar(' ');
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
  * _malloc13 - allocates suitable memory space for 'hexadecimal string'
  * with # flag
  * @num_list: list of arguments
  * @base: conversion base
  * @caps: determines whether hexadecimal is capitalised
  * Definition - determines how many bytes of memory should be
  * allocated, and performs the memory allocation.
  * Return: count of printed characters
  */

int _malloc13(va_list num_list, int base, char caps)
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
	if (base == 16)
		_putchar('0');
	if (caps == 'A')
		_putchar('X');
	else if (caps == 'a')
		_putchar('x');
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
