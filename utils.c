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
	char t;

	for (i = 0, j = _strlen(s) - 1; i < j; i++, j--)
	{
		t = s[i];
		s[i] = s[j];
		s[j] = t;
	}

	return s;
}