#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_char - prints a single charater
 * @c: the character to printed.
 * @count: Pointer to the count of character
 */

void print_char(char c, int *count)
{
	putchar(c);
	(*count)++;
}

/**
 * print_string - prints a string
 * @s: the string to printed
 * @count: pointer to be count of charecters
 */

void print_string(char *s, int *count)
{
	while (*s)
	{
		putchar(*s);
		s++;
		(*count)++;
	}
}

/**
 * _printf - function that produces output according to a format
 * @format: character string
 * c:
 * s:
 * %:
 * @...: arguments to be formated
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	char *p;

	va_start(args, format);

	if (char *p = format; *p != '\0'; p++)
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
