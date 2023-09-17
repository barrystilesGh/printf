#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);
int _puts(char *str);
int print_number(int n);
int print_acs(char format, char prev, va_list params);
int print_null(void);

typedef unsigned int usi;

#endif
