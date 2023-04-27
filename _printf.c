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
 * print_integer - prints an integer from va_list argument
 * @args: va_list argument from which integer is taken
 * Return: the number of characters printed
 */
int print_integer(va_list *args)
{
    int n = va_arg(*args, int);
    int count = 0, negative = 0, i = 0, digits = 0;
    long int temp, value;
    char *buffer;

    if (n == 0)
    {
        count += write(1, "0", 1);
        return (count);
    }
    if (n == INT_MIN)
    {
        buffer = "-2147483648";
        count = write(1, buffer, 11);
        return (count);
    }
    value = n;
    if (n < 0)
    {
        negative = 1;
        n = -n;
        value = -value;
    }
    temp = value;
    while (temp != 0)
    {
        digits++;
        temp /= 10;
    }
    if (negative)
        digits++;
    buffer = (char *)malloc((digits + 1) * sizeof(char));
    if (buffer == NULL)
        return (-1);
    i = digits - 1;
    while (value != 0)
    {
        buffer[i--] = (value % 10) + '0';
        value /= 10;
    }
    if (negative)
        buffer[i] = '-';
    buffer[digits] = '\0';
    count = write(1, buffer, digits);
    free(buffer);
    return (count);
}


/**
 * _printf - produces output according to a format
 * @format: the format string containing the conversion specifiers
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;

    va_start(args, format);
    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'c')
                count += print_char(&args);
            else if (format[i] == 's')
                count += print_string(&args);
            else if (format[i] == '%')
                count += print_percent(&args);
            else if (format[i] == 'd' || format[i] == 'i')
                count += print_integer(&args);
			else if (format[i] == 'b')
				count += print_binary(&args);
            else if (format[i] == 'u')
                count += print_unsigned_integer(&args);
            else if (format[i] == 'o')
                count += print_octal(&args);
            else if (format[i] == 'x')
                count += print_hexadecimal(&args);
            else if (format[i] == 'X')
                count += print_hexadecimal_uppercase(&args);
            else
            {
                write(1, "%", 1);
                write(1, &format[i], 1);
                count += 2;
            }
        }
        else
        {
            write(1, &format[i], 1);
            count++;
        }
        i++;
    }
    va_end(args);
    return (count);
}