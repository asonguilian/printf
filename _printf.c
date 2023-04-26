#include "main.h"

/**
 * print_char - prints a single character from a va_list argument
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
 * print_integer - prints an integer from a va_list argument
 * @args: va_list argument from which integer is taken
 * Return: the number of characters printed
 */
int print_integer(va_list *args)
{
    int n = va_arg(*args, int);
    int count = 0, negative, i;
    char *s;
    char buffer[12]; /* max number of digits in a 32-bit integer + sign */

    if (n == 0)
    {
        count += write(1, "0", 1);
        return (count);
    }

    negative = n < 0;
    if (negative)
    {
        n = -n;
        buffer[0] = '-';
        count++;
    }

    i = 0;
    while (n > 0)
    {
        buffer[i] = (n % 10) + '0';
        n /= 10;
        i++;
    }
    if (negative) {
        buffer[i] = '\0';
    } else {
        i--;
        buffer[i] = '\0';
    }
    s = _strrev(buffer);
    count += write(1, s, _strlen(s));
    free(s);

    return (count);
}

/**
 * _printf - produces output according to a format
 * @format: character string that contains directive for printing
 * Return: number of characters printed excluding the null byte terminator
 */

int _printf(const char *format, ...)
{
    int count = 0; /*count characters printed*/
    va_list args;

    va_start(args, format);
    if (format == NULL)
        return (-1);
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
                case 'd':
                case 'i':
                    count += print_integer(&args);
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
