#include "main.h"
#include <unistd.h>
#include <stdarg.h>
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
	switch (ch)
	{
		case 'c':
		{
			char c = va_arg(args, int);

			write(1, &c, 1);
			count++;
			break;
		}
		case 's':
		{
			char *str = va_arg(args, char*);

			if (str == NULL)
				str = "(null)";
			while (*str != '\0')
			{
				write(1, &str, 1);
				str++;
				count++;
			}
			break;
		}
		case '%':
		{
			write(1, "%", 1);
			count++;
			break;
		}
		default:
		{
			char c = va_arg(args, int);

			write(1, "%", 1);
			write(1, &c, 1);
			count += 2;
			break;
		}
	}
	return (count);
}
