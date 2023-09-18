#include "../main.h"
#include <stdio.h>

int main(void)
{
	int count;

	_printf("%b", 5);
	_printf("\n%i\n%u\n%o\n%b\n", 0, 0, 0, 0);
	_printf("Real printf - %X||%b||%i||%d||%x||%o||%u", 0, 0, 0, 0, 0,
	0, 0);
	_printf("\n%x||%X", 1234232, 1234232);
	count = _printf("%R", "ABCDEFGHIJKLMabcdefghijklm");
	printf("%d", count);
	return (0);
}
