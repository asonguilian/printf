#include "main.h"

/**
 * print_char - prints a single chaacter from a va_list argument
 * @args: va_list argument from which character to be printed is taken
 * Return: 1  (since only one character is printed)
 */
int print_char(va_list *args)
{
	char c = va_arg(*args, int);

	write(1, &c, 1);
	return (1);
}
/**
 * print_string - prints a string from a va_list argument
 * @args: va_list argument from which string is taken
 * Return: the number of characters printed
 */
int print_string(va_list *args)
{
	char *s = va_arg(*args, char *);
	int count = 0;

	while (*s)
	{
		write(1, s, 1);
		++s;
		++count;
	}
	return (count);
}
/**
 * print_percent - prints the character %
 * @args: va_list argument which is unused in this function
 * Return: 1 (since only one character is printed)
 */
int print_percent(va_list *args __attribute__((unused)))
{
	char c = '%';

	write(1, &c, 1);
	return (1);
}

/**
 * _printf - produces output according to a foramt
 * @format: character string that contains directive for printing
 * Return: number of characters printed excluding the null bute terminator
 */

int _printf(const char *format, ...)
{
	int count = 0; /*count characters printed*/
	va_list args;
	print_func_t print_func;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			switch (*format)
			{
				case 'c':
					print_func = &print_char;
					break;
				case 's':
					print_func = &print_string;
					break;
				case '%':
					print_func = &print_percent;
					break;
				default:
					write(1, "%", 1);
					write(1, format, 1);
					count += 2;
					++format;
					continue;
			}
			++format;
			count += print_func(&args);
		}
		else
		{
			write(1, format, 1);
			++count;
			++format;
		}
	}
	va_end(args);
	return (count);
}
