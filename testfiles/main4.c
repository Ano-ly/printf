#include <stdio.h>
#include "../main.h"
#include <limits.h>

int main(void)
{
	int count;

	/*_printf("%i - %i = %i\n", 1024, 2048, -1024);*/
	count = _printf("%i", INT_MAX);
	printf("Count: %i", count);
	/*_printf("%x", UINT_MAX);*/
	/*_printf("result: %i:", 0);*/
	/*_printf("%i", 1024);*/
	/*printf("%d + %d = %d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));*/
	/*_printf("%d", 2147482623);*/
	return (0);
}
