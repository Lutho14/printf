#include "main.h"
#include <stdio.h>

/**
 * _printf - function that produces output according to a format
 * @format: character string
 * @c:
 * @s:
 * @%:
 * @...: arguments to be formated
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	for (const char *p = format; *p != '\0'; p++)
	{
		if (*p != '%')
		{
			putchar(*p);
			count++;
		}
		else
		{
			switch (*++p)
			{
				case 'c':
				{
					char c = va_arg(args, int);

					putchar(c);
					count++;
					break;
				}
				case 's':
				{
					const char *s = va_arg(args, const char *);

					while (*s != '\0')
					{
						putchar(*s);
						count++;
						s++;
					}
					break;
				}
				case '%':
					putchar('%');
					count++;
					break;
				default:
					putchar(*p);
					count++;
					break;
			}
		}
	}
	va_end(args);
	return (count);
}
