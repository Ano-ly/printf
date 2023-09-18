#include "../main.h"
#include <stdio.h>

int main(void)
{
	_printf("%b", 5);
	_printf("\n%i\n%u\n%o", -0x56, 999999, 20 );
	_printf("Real printf - %o", 034);
	return (0);
}
