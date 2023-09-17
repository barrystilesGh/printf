#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * _puts - prints a string to stdout
 * @str: the string to be printed
 * Return: the number of characters printed
 */
int _puts(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

/**
 * print_null - print '(null)'
 * Return: 6 always
 */
int print_null(void)
{
	_putchar('(');
	_putchar('n');
	_putchar('u');
	_putchar('l');
	_putchar('l');
	_putchar(')');
	return (6);
}

/**
 * print_acs - prints the value of an
 * access specifier
 * @format: the type of specifier
 * @prev: the previous char
 * @params: the arguments list
 * Return: the number of chars printed
 */
int print_acs(char format, char prev, va_list params)
{
	char cur, *str;
	int count = 0;

	switch (format)
	{
	case 'c':
		cur = va_arg(params, int);
		_putchar(cur);
		count++;
		break;
	case 's':
		str = va_arg(params, char *);
		if (str == NULL)
			count += print_null();
		else
			count += _puts(str);
		break;
	case 'd':
	case 'i':
		cur = va_arg(params, int);
		count += print_number(cur);
		break;
	case '%':
		_putchar('%');
		count++;
		break;
	default:
		_putchar(prev);
		_putchar(format);
		count += 2;
		break;
	}
	return (count);
}


/**
 * print_number - prints any integer
 * @n: number to be printed
 * Return: the number of chars printed
 */
int print_number(int n)
{
	int count = 0, divisor, temp, digit;

	if (n == 0)
	{
		_putchar('0');
		count++;
	}
	else
	{
		if (n < 0)
		{
			_putchar('-');
			count++;
			n = -n;
		}

		divisor = 1;
		temp = n;

		while (temp > 9)
		{
			divisor *= 10;
			temp /= 10;
		}

		while (divisor > 0)
		{
			digit = n / divisor;
			_putchar('0' + digit);
			count++;
			n -= digit * divisor;
			divisor /= 10;
		}
	}

	return (count);
}
