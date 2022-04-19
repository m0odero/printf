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
	int i, n, num = 0;

	va_start(ap, format);
	while (format[i])
	{
		switch (format[i])
		{
			case 'c':
				n = printf("%c", (char) va_arg(ap, int));
				break;
			case 'i':
				n = printf("%d", va_arg(ap, int));
				break;
			case 'f':
				n = printf("%f", (float) va_arg(ap, double));
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
		if ((format[i] == 'c' || format[i] == 'i' || format[i] == 'f' ||
					format[i] == 's') && format[(i + 1)] != '\0')
		{
			n = printf(", ");
			num = num + n;
		}
		i++;
	}
	va_end(ap);
	num = num + printf("\n");
	return (num);
}

