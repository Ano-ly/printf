#include <stdio.h>
#include "../main.h"

int main(void)
{
	int count;

	count = _printf("%s, %u, %ld, %b, %c, %d, %i, %o, %r, %R, %x, %X, %hi",
	"me tt", 0, 304, 2, 'L', 44, 0x12, 54,
	"try me now", "ABCDnopq...//88", 34, 34, 56);
	printf("%d", count);
	return (0);
}
