#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
/*#include <stdio.h>*/


/**
 * choose1 - determines which _malloc function deals with flag +
 * @spec_loc: index of specifier
 * @str: format string
 * @values: list of arguments
 * Definition - needed to determine specifier that comes after l
 * Return: count of printed characters
 * and determinant of presence of two-member specifier
*/

int choose1(int spec_loc, const char *str, va_list values)
{
	char spec;
	int sub4_count;

	sub4_count = -1;

	spec = str[spec_loc + 1];
	/*printf("SPEC: '%c'", spec);*/
	if (spec == 'd' || spec == 'i')
		sub4_count = _malloc12(values, 10);
	/*printf("Sub4_count: %d", sub4_count);*/
	return (sub4_count);

}

/**
 * choose2 - determines which _malloc function deals with flag #
 * @spec_loc: index of specifier
 * @str: format string
 * @values: list of arguments
 * Definition - needed to determine specifier that comes after l
 * Return: count of printed characters
 * and determinant of presence of two-member specifier
*/

int choose2(int spec_loc, const char *str, va_list values)
{
	char spec;
	int sub5_count;

	sub5_count = -1;

	spec = str[spec_loc + 1];
	/*printf("SPEC: '%c'", spec);*/
	if (spec == 'o')
		sub5_count = _malloc11(values, 8);
	/*printf("Sub5_count: %d", sub5_count);*/
	if (spec == 'x')
		sub5_count = _malloc13(values, 16, 'a');
	if (spec == 'X')
		sub5_count = _malloc13(values, 16, 'A');
	return (sub5_count);

}

/**
 * choose3 - determines which _malloc function deals with flag space
 * @spec_loc: index of specifier
 * @str: format string
 * @values: list of arguments
 * Definition - needed to determine specifier that comes after l
 * Return: count of printed characters
 * and determinant of presence of two-member specifier
*/

int choose3(int spec_loc, const char *str, va_list values)
{
	char spec;
	int sub6_count;

	sub6_count = -1;

	spec = str[spec_loc + 1];
	/*printf("SPEC: '%c'", spec);*/
	if (spec == 'd' || spec == 'i')
		sub6_count = _malloc14(values, 10);
	/*printf("Sub6_count: %d", sub6_count);*/
	return (sub6_count);

}
