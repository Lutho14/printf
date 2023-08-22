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
 * handle_unknown - handle unknown
 * @spc: prints the spc
 * @%: printed
 *
 * Return: 2
 */
int handel_unknown(char *spc)
{
	char c;

	if (*spc == ' ')
		return (-1);

	putchar((c): '%');
	putchar((c): spc);

	return (2);
}

/**
 * _printf - function that produces output according to a format
 * @format: character string
 * c:
 * s:
 * %:
 * @...: arguments to be formated
 *
 * Return: the number of characters printed, NULL
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == '\0')
			{
				break;
			}
			if (*format == 'c')
			{
				char c = (char)va_arg(args, int);

				print_char(c, &count);
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);

				print_string(s, &count);
			}
			else
			{
				print_char(*format, &count);
			}
		}
		else
		{
			print_char(*format, &count);
		}
		format++;
	}
	va_end(args);
	return (count);
}
