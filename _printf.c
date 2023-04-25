#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _putchar - writes a character to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - prints a character
 * @args: arguments list
 *
 * Return: number of characters printed
 */
int print_char(va_list args)
{
	return (_putchar(va_arg(args, int)));
}

/**
 * print_string - prints a string
 * @args: arguments list
 *
 * Return: number of characters printed
 */
int print_string(va_list args)
{
	char *str;
	int i, len;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	for (len = 0; str[len] != '\0'; len++)
		;
	for (i = 0; i < len; i++)
		_putchar(str[i]);
	return (len);
}

/**
 * print_int - prints an integer
 * @args: arguments list
 *
 * Return: number of characters printed
 */
int print_int(va_list args)
{
	int n, div, len = 0;

	n = va_arg(args, int);
	if (n < 0)
	{
		len += _putchar('-');
		n = -n;
	}
	for (div = 1; n / div > 9; div *= 10)
		;
	for (; div >= 1; div /= 10)
	{
		len += _putchar(((n / div) % 10) + '0');
	}
	return (len);
}

/**
 * print_func_t - function pointer type for print functions
 * @args: arguments list
 *
 * Return: number of characters printed
 */
typedef int (*print_func_t)(va_list args);

/**
 * _printf - prints output according to a format.
 * @format: a string containing zero or more directives.
 *
 * Return: the number of characters printed
 * (excluding the null byte used to end
 * output to strings), or a negative value if an error occurred.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, len = 0;
	print_func_t print_func;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
			{
				_putchar('%');
				len++;
				continue;
			}
			switch (format[i])
				{
				case 'c':
					print_func = &print_char;
					break;
				case 's':
					print_func = &print_string;
					break;
				case 'i':
				case 'd':
					print_func = &print_int;
					break;
				default:
					_putchar('%');
					_putchar(format[i]);
					len += 2;
					continue;
				}
			len += print_func(args);
		}
		else
		{
			_putchar(format[i]);
			len++;
		}
	}

	va_end(args);
	return (len);
}
