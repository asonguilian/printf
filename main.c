#include "main.h"
#include <stdio.h>

/**
  * main -entry point
  *
  * Return: 0
  */

int main(void)
{
	int len, len2;
	char xter = '!';
	char str[17] = "Asongtia Guilian";

	len = _printf("Let's try to printf a simple sentence\n");
	len2 = printf("Let's try to printf a simple sentence\n");
	printf("len=%d\t len2=%d\n\n", len, len2);
	len = _printf("Print a character %c in a string.\n", xter);
	len2 = printf("Print a character %c in a string.\n", xter);
	printf("len=%d\t len2=%d\n\n", len, len2);
	len = _printf("%c\n", xter);
	len2 = printf("%c\n", xter);
	printf("len=%d\t len2=%d\n\n", len, len2);
	len = _printf("Let's print the modulo sign %%\n");
	len2 = printf("Let's print the modulo sign %%\n");
	printf("len=%d\t len2=%d\n\n", len, len2);
	len = _printf("%% is just bae\n");
	len2 = printf("%% is just bae\n");
	printf("len=%d\t len2=%d\n\n", len, len2);
	len = _printf("%%\n");
	len2 = printf("%%\n");
	printf("len=%d\t len2=%d\n\n", len, len2);
	len = _printf("My name is %s\n", str);
	len2 = printf("My name is %s\n", str);
	printf("len=%d\t len2=%d\n\n", len, len2);
	len = _printf("Name:%s%c\n", str, xter);
	len2 = printf("Name:%s%c\n", str, xter);
	printf("len=%d\t len2=%d\n\n", len, len2);

	return (0);
}

