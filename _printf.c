#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - prints strings with format
 * @format: string with format
 *
 * Return: char printed count;
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	int count = 0;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count = case_finder(format[i], count, args);
		} else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;

	}
	va_end(args);
	return (count);
}
