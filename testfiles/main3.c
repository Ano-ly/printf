#include <stdio.h>
#include "../main.h"

int main(void)
{
	int count;

	char *str = "I never promised you a ray of light, but I really hoped\
	that, for once, we could actually fly together. If only you knew me as\
	much as I knew you. Then you would know that, truly, this life is not\
	exactly that easy to live in.";
	/*count = printf("%s, %u, %ld, %b, %c, %d, %i, %o, %r, %R, %x, %X,
	 * %hi",*/
	/*"me tt", 0, 304, 2, 'L', 44, 0x12, 54,*/
	/*"try me now", "ABCDnopq...//88", 34, 34, 56);*/
	/*printf("%s||%d", NULL, count);*/

	count = _printf("Let's print a simple sentence.\n");
	printf("\nCOUNT: %d\n", count);
	count = _printf("%c", 'S');
	printf("\nCOUNT: %d\n", count);
	count = _printf("A char inside a sentence: %c. Did it work?\n", 'F');
	printf("\nCOUNT: %d\n", count);
	count = _printf("Let'see if the cast is correctly done: %c. Did it work?\n", 48);
	printf("\nCOUNT: %d\n", count);
	count = _printf("%s", "This sentence is retrieved from va_args!\n");
	printf("\nCOUNT: %d\n", count);
	count = _printf("Complete the sentence: You %s nothing, Jon Snow.\n", "know");
	printf("\nCOUNT: %d\n", count);
	count = printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
	printf("\nCOUNT: %d\n", count);
	count = printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');
	printf("\nCOUNT: %d\n", count);
	count = _printf("%%");
	printf("\nCOUNT: %d\n", count);
	count = _printf("Should print a single percent sign: %%\n");
	printf("\nCOUNT: %d\n", count);
	count = _printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
	printf("\nCOUNT: %d\n", count);
	count = _printf("css%ccs%scscscs", 'T', "Test");
	printf("\nCOUNT: %d\n", count);
	count = _printf(str);
	printf("\nCOUNT: %d\n", count);
	count = _printf("man gcc:\n%s", str);
	printf("\nCOUNT: %d\n", count);
	count = _printf(NULL);
	printf("\nCOUNT: %d\n", count);
	count = _printf("%c", '\0');
	printf("\nCOUNT: %d\n", count);
	count = _printf("%");
	printf("\nCOUNT: %d\n", count);
	count = _printf("%!\n");
	printf("\nCOUNT: %d\n", count);
	count = _printf("%K\n");
	printf("\nCOUNT: %d\n", count);

	return (0);
}
