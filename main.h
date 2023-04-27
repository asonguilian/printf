#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

/*
*declares a type definiton for function pointers
* that take va_list argument,
* returns an integer
*/
/*typedef int (*print_func_t)(va_list *);*/

int print_char(va_list *args);
int print_string(va_list *args);
int print_percent(va_list *args __attribute__((unused)));
int print_integer(va_list *args);
int _printf(const char *format, ...);


int _strlen(char *);
char *_strrev(char *s);
int print_binary(va_list *args);
#endif
