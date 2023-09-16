#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int specify(char spec, va_list values);
int _putchar(char c);
int _malloc(va_list num_list);
int fill_buffer(char *buffer, int num, int n);
int print_rev_buffer(char *buffer, int n);

#endif
