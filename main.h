#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct _struct - contains count of printed chars, and validator for
 * extra modifiers
 * @count: number of printed chars
 * @flag_true: extra modifiers validator
 * Description - is returnes by specify function
*/

typedef struct _struct
{
	int count;
	int flag_true;
} _struct;

int _printf(const char *format, ...);
_struct specify(const char *str, int spec_loc, char spec, va_list values);
int specify_sub(char spec, va_list values);
int _putchar(char c);
int _malloc(va_list num_list, int base);
int _malloc2(va_list num_list, int base);
int fill_buffer(char *buffer, long int num, int n, int base);
int print_rev_buffer(char *buffer, int n);

int _malloc3(va_list num_list, int base, char caps);
int fill_buffer_hexa(char *buffer, long int num, int n, int base, char caps);

int rev_string(va_list num_list);
int rot13(va_list num_list);
int _strlen(char *str);

int _malloc6(va_list num_list, int base);
int _malloc7(va_list num_list, int base);
int fill_buffer_l_hexa(char *buffer, long int num, int n, int base, char caps);
int fill_buffer_long(char *buffer, long int num, int n, int base);
int _malloc5(va_list num_list, int base, char caps);
int longfunction(int spec_loc, const char *str, va_list values);

int _malloc8(va_list num_list, int base);
int _malloc9(va_list num_list, int base);
int fill_buffer_s_hexa(char *buffer, short int num, int n, int base,
char caps);
int fill_buffer_short(char *buffer, short int num, int n, int base);
int shortfunction(int spec_loc, const char *str, va_list values);
int _malloc10(va_list num_list, int base, char caps);

void print_null(void);

#endif
