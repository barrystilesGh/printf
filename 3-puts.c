#include "main.h"

/**
 * _puts - prints a string to stdout
 * @str: the string to be printed
 */
void _puts(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
