#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>



int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_int(va_list args);
int _printf(const char *format, ...);

#endif
