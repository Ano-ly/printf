#include "../main.h"
#include <stdio.h>

int main(void)
{
	_printf("%b", 5);
	_printf("\n%i\n%u\n%o\n%b\n", 0, 0, 0, 0);
	_printf("Real printf - %X||%b||%i||%d||%x||%o||%u", 0, 0, 0, 0, 0,
	0, 0);
	return (0);
}
