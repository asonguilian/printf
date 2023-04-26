#include "main.h"

/**
 * print_char - prints a single chaacter from a va_list argument
 * @args: va_list argument from which character to be printed is taken
 * Return: 1  (since only one character is printed)
 */
int print_char(va_list *args)
{
	char c = va_arg(*args, int);
	int count;

	count = write(1, &c, 1);
	return (count);
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

	if (s == NULL)
	{
		s = "(null)";
	}
	count = write(1, s, _strlen(s));
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

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			if (*format == '\0')
			{
				return (-1);
			}
			switch (*format)
			{
				case 'c':
					count += print_char(&args);
					break;
				case 's':
					count += print_string(&args);
					break;
				case '%':
					count += print_percent(&args);
					break;
				default:
					write(1, "%", 1), write(1, format, 1);
					count += 2;
			}
			++format;
		}
		else
		{
			write(1, format, 1), ++count, ++format;
		}
	}
	va_end(args);
	return (count);
}
