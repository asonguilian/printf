#include "main.h"

/**
  * _strlen -returns length of the string
  * @s: input string
  * Return: length of the string
  */

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _strrev - reverses a string in place
 * @s: string to reverse
 * Return: pointer to the reversed string
 */
char *_strrev(char *s)
{
	int i, j;
	char temp;

	for (i = 0, j = _strlen(s) - 1; i < j; i++, j--)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}

	return (s);
}


/**
  * print_binary -prints an unsigned integer in binary format
  * @args: va_list argument from which unsigned integr is taken
  * Return: the number of characters printed
  */
int print_binary(va_list *args)
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
		temp >>= 1;
	}
	buffer = (char *)malloc((digits + 1) * sizeof(char));
	if (buffer == NULL)
		return (-1);
	i = digits - 1;
	while (n != 0)
	{
		buffer[i--] = (n & 1) + '0';
		n >>= 1;
	}
	buffer[digits] = '\0';
	count = write(1, buffer, digits);
	free(buffer);
	return (count);
}


/**
 * print_unsigned_integer - prints an unsigned integer from va_list argument
 * @args: va_list argument from which integer is taken
 * Return: the number of characters printed
 */
int print_unsigned_integer(va_list *args)
{
    unsigned int n = va_arg(*args, unsigned int);
    int count = 0, i = 0, digits = 0;
    unsigned long int temp, value;
    char *buffer;

    if (n == 0)
    {
        count += write(1, "0", 1);
        return (count);
    }
    value = n;
    temp = value;
    while (temp != 0)
    {
        digits++;
        temp /= 10;
    }
    buffer = (char *)malloc((digits + 1) * sizeof(char));
    if (buffer == NULL)
        return (-1);
    i = digits - 1;
    while (value != 0)
    {
        buffer[i--] = (value % 10) + '0';
        value /= 10;
    }
    buffer[digits] = '\0';
    count = write(1, buffer, digits);
    free(buffer);
    return (count);
}

/**
 * print_octal - prints an unsigned integer in octal format
 * @args: va_list argument from which integer is taken
 * Return: the number of characters printed
 */
int print_octal(va_list *args)
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
        temp /= 8;
    }
    buffer = (char *)malloc((digits + 1) * sizeof(char));
    if (buffer == NULL)
        return (-1);
    i = digits - 1;
    while (n != 0)
    {
        buffer[i--] = (n % 8) + '0';
        n /= 8;
    }
    buffer[digits] = '\0';
    count = write(1, buffer, digits);
    free(buffer);
    return (count);
}
