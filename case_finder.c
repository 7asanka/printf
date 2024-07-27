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
			int j = 0;

			if (str == NULL)
				str = "(null)";
			while (str[j] != '\0')
			{
				write(1, &str[j], 1);
				count++;
				j++;
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
			char c = va_arg(args, int);

			write(1, "%", 1);
			write(1, &c, 1);
			count += 2;
			break;
	}
	return (count);
}
