#include "../main.h"
#include <stdio.h>

int main(void)
{
	int count;
	int count2;

	_printf("%b", 5);
	count2 = _printf("\n%b\n%b\n%o\n%b\n", 0, 3, 0, 0);
	printf("COunt: %d||", count2);
	_printf("Real printf - %X||%b||%i||%d||%x||%o||%u", 0, 0, 0, 0, 0,
	0, 0);
	_printf("\n%x||%X", 1234232, 1234232);
	count = _printf("%R", "AB.CDE.FGH,IJKL;;;Mab::cdefghijklm");
	printf("%d", count);
	count = _printf("\n\ni te%%%%sting:\nI am %i|| %i|| %ld|| %d\n",-0x1f,
	123456781, 1800048885111000000, -12);

	printf("%d", count);
	printf("%li", 180004851110);
	return (0);
}
