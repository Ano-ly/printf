#include "main.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

/**
  * rot13 - encodes a string in ROT13
  * @num_list: list of arguments
  * Description - encodes string to ROT13 using arrays, for loops and if block
  * Return: count of printed numbers
  */

int rot13(va_list num_list)
{
	int i;
	int j;
	int l1;
	int count;
	char *str;
	char *arr1;
	char *arr2;

	count = 0;

	arr1 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	arr2 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	str = va_arg(num_list, char *);

	if (str != NULL)
	{
		l1 = _strlen(str);

		for (i = 0; i < l1; i++)
		{
			for (j = 0; j < 52; j++)
			{
				if ((int)str[i] == (int)arr1[j])
				{
					_putchar(arr2[j]);
					count++;
					break;
				}
			}
		}
	}
	return (count);
}

/**
  * _strlen - computes the length of a string
  * @str: string whose length is to be computed
  * Description - computes length of string
  * Return: integer, length of string
  */

int _strlen(char *str)
{
	int i;
	int lenn;

	i = 0;
	lenn = 0;

	while (str[i] != 0)
	{
		lenn++;
		i++;
	}
	return (lenn);
}
