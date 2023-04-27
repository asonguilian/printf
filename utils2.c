#include "main.h"

/**
 * print_hexadecimal - prints an unsigned integer in hexadecimal format (lowercase)
 * @args: va_list argument from which integer is taken
 * Return: the number of characters printed
 */
int print_hexadecimal(va_list *args)
{
    unsigned int n = va_arg(*args, unsigned int);
    unsigned int temp = n;
    int count = 0, i = 0, digits = 0;
    char *buffer;

    if (n == 0)
    {
        count += write(1, "0", 1);
        return (count);
    }
    while (temp != 0)
    {
        digits++;
        temp /= 16;
    }
    buffer = (char *)malloc((digits + 1) * sizeof(char));
    if (buffer == NULL)
        return (-1);
    i = digits - 1;
    while (n != 0)
    {
        int remainder = n % 16;
        if (remainder < 10)
            buffer[i--] = remainder + '0';
        else
            buffer[i--] = remainder - 10 + 'a';
        n /= 16;
    }
    buffer[digits] = '\0';
    count = write(1, buffer, digits);
    free(buffer);
    return (count);
}


/**
 * print_hexadecimal_uppercase - prints an unsigned integer in hexadecimal format (uppercase)
 * @args: va_list argument from which integer is taken
 * Return: the number of characters printed
 */
int print_hexadecimal_uppercase(va_list *args)
{
    unsigned int n = va_arg(*args, unsigned int);
    unsigned int temp = n;
    int count = 0, i = 0, digits = 0;
    char *buffer;

    if (n == 0)
    {
        count += write(1, "0", 1);
        return (count);
    }
    while (temp != 0)
    {
        digits++;
        temp /= 16;
    }
    buffer = (char *)malloc((digits + 1) * sizeof(char));
    if (buffer == NULL)
        return (-1);
    i = digits - 1;
    while (n != 0)
    {
        int remainder = n % 16;
        if (remainder < 10)
            buffer[i--] = remainder + '0';
        else
            buffer[i--] = remainder - 10 + 'A';
        n /= 16;
    }
    buffer[digits] = '\0';
    count = write(1, buffer, digits);
    free(buffer);
    return (count);
}

