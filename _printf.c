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
 * print_int - prints an integer from a va_list argument
 * @args: va_list argument from which integer is read
 * Return: number of characters printed
 */
int print_int(va_list *args)
{
	int val = va_arg(*args, int);
	char buffer[20];/*max num of digits for 64 bits int +sign */
	int i = 0; /*index of next character to write to buffer*/
	int negative = 0; /* flag to denote sign of the integer*/
	int count = 0;

	if (val < 0)
	{
		negative = 1;
		if (val == INT_MIN)/*handle integr overflow*/
		{
			write(1, "-2147483648", 11);
			return (11);
		}
		val = -val;
	}
	/* check for integer overflow */
	if (val >= 1000000000 && (val > INT_MAX / 1000000000
				|| val * 1000000000 > INT_MAX
				- (val % 1000000000) * 2))
	{
		write(1, "OVERFLOW\n", 9);
		return (9);
	}
	/* if integer is within limits, convert to string in reverse order */
	do {
		buffer[i++] = val % 10 + '0';
		val /= 10;
	} while (val > 0);
	if (negative)/*append sign if integer is -ve*/
	{
		buffer[i++] = '-';
	}
	while (i > 0)/* write string in reverse order*/
	{
		write(1, &buffer[--i], 1);
		++count;
	}
	return (count);
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
				case 'd':
				case 'i':
					print_func = &print_int;
					break;
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
