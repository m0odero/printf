#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * _printf - function that returns the number of characters printed.
 * @format: A list of type of arguments passed to the function.
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list ap;
	char *string;
	int num = 0;
	int i = 0;
	int n = 0;

	va_start(ap, format);
	while (format[i])
	{
		switch (format[i])
		{
			case 'b':
				n = printf("%u", convert(va_arg(ap, unsigned int), 2));
				break;
			case 'd':
				n = printf("%u", convert(va_arg(ap, unsigned int), 10));
				break;
			case 'c':
				n = printf("%c", (char) va_arg(ap, int));
				break;
			case 'i':
				n = printf("%d", va_arg(ap, int));
				break;
			case 's':
				string = va_arg(ap, char*);
				if (string != NULL)
				{
					n = printf("%s", string);
					break;
				}
				printf("(nil)");
				break;
		}
		num = num + n;
		if (format[(i + 1)] != '\0')
			num = num + printf(", ");
		i++;
	}
	va_end(ap);
	return (num + printf("\n"));
}

/**
 * convert - convert a number from base 10 to another number.
 * @ui: the number to be converted
 * @base: the base to which it should be converted
 * Return: the converted number
 */

unsigned int convert(unsigned int ui, int base)
{
	if (ui == 0)
	{
		return (0);
	}
	if (ui == 1)
	{
		return (1);                       /* optional */
	}
	return ((ui % base) + 10 * convert(ui / base, base));
}
