#include "main.h"
#include <stdarg.h>
/**
 * _printf - produces output according to format
 * @format: character string format
 * Return: the number of characters printed
*/
int _printf(const char *format, ...)
{
	int i, cur, acs = 0;

	va_list params;

	if (!format || (format[0] == '%' && format[1] == '\0'))
	{
		return (-1);
	}

	va_start(params, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			our_putchar(format[i]);
		}
		else if (format[i] == '%' && format[i + 1] == 'c')
		{
			our_putchar(va_arg(params, int));
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			cur = our_puts(va_arg(params, char*));
			i++;
			acs += (cur - 1);
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			our_putchar('%');
		}
		acs++;
	}
	va_end(params);
	return (acs);
}
