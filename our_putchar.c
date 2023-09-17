#include "main.h"
#include <unistd.h>

/**
 * our_putchar - writes the character c to the stdout
 * @c: the character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int our_putchar(char c)
{
	return (write(1, &c, 1));
}
