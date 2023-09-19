#include <stdio.h>
#include "../main.h"

int main(void)
{
	_printf("%b, %c, %d, %i, %o, %r, %R, %x, %X, %hi", 304, 'L', 44, 0x12, 54,
	"try me now", "ABCDnopq...//88", 34, 34, 56);
	return (0);
}
