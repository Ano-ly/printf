#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int specify(char spec, va_list values);
int _putchar(char c);
int _malloc(va_list num_list, int base);
int _malloc2(va_list num_list, int base);
int fill_buffer(char *buffer, int num, int n, int base);
int print_rev_buffer(char *buffer, int n);

#endif
