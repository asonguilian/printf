#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/*
*declares a type definiton for function pointers
* that take va_list argument,
* returns an integer
*/
typedef int (*print_func_t)(va_list *);

int print_char(va_list *args);
int print_string(va_list *args);
int print_percent(va_list *args);
int _printf(const char *format, ...);


int _strlen(char *);
#endif
