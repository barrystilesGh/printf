#include "main.h"
#include <stdarg.h>
#include <stdarg.h>

/**
 * _printf - produces output according to format
 * @format: character string format
 * Return: the number of characters printed
*/
int _printf(const char *format, ...)
{
	int i, acs = 0, cur;
	char *str;

	va_list params;
	va_start(params, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%' && format[i - 1] != '%')
		{
			acs = 1;
			continue;
		}

		if (acs == 0)
		{
			_putchar(format[i]);
		}
		else
		{
			switch (format[i])
			{
			case 'c':
				cur = va_arg(params, int);
				_putchar(cur);
				break;

			case 's':
				str = va_arg(params, char *);
				_puts(str);
				break;

			case '%':
				_putchar('%');
				break;

			default:
				_putchar(format[i - 1]);
				_putchar(format[i]);
				break;
			}
			acs = 0;
		}
	}

	va_end(params);
	
	return (i);
}