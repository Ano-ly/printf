#include <stdio.h>
#include "../main.h"
#include <limits.h>

int main(void)
{
	printf("%i + %i = %i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	/*_printf("%d == %i\n", 1024);*/
	/*_printf("%i - %i = %i\n", 1024, 2048, -1024);*/
	_printf("STDOUT ||%d||", INT_MAX);
	/*printf("%i", INT_MIN);*/
	/*_printf("result: %i:", 0);*/
	/*_printf("%i", 1024);*/
	/*printf("%d + %d = %d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));*/
	_printf("%d", 2147483648);
	return (0);
}
