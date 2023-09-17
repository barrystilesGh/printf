#include "main.h"
/**
 * our_puts - prints a string to stdout
 * @str: the string to be printed
 * Return: number of byte
 */
int our_puts(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		our_putchar(str[i]);
		i++;
	}
	return (i);
}
