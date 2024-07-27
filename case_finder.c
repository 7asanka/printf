#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
/**
 * case_finder - finds mod case for _printf
 * @ch: character for the case
 * @args: argument list
 * @count: count to increase for function printf
 *
 * Return: count
 */
int case_finder(const char ch, int count, va_list args)
{
	if (ch == 'c')
	{
		char c = va_arg(args, int);

		write(1, &c, 1);
		count++;
	} else if (ch == 's')
	{
		char *str = va_arg(args, char*);

		if (str == NULL)
			str = "(null)";
		while (*str)
		{
			write(1, str, 1);
			count++;
			str++;
		}
	} else if (ch == '%')
	{
		write(1, "%", 1);
		count++;
	} else if (ch == 'i' || ch == 'd')
	{
		int num = va_arg(args, int);
		char buf[12];
		int len = snprintf(buf, 12, "%d", num);

		write(1, buf, len);
		count += len;
	} else
	{
		write(1, "%", 1);
		write(1, &ch, 1);
		count += 2;
	}
	return (count);
}
