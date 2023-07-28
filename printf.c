#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - Write a character to the standard output (file descriptor 1).
 *
 * @c: The character to be written.
 *
 * Return: On success, 1 is returned. On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - Print formatted output with variable arguments.
 *
 * This function prints formatted output with variable arguments. It supports
 * replacing '%d' or '%i' with an integer value, '%s' with a null-terminated string,
 * '%c' with a character, and '%%' with a literal '%'.
 *
 * @format: The formatted string to print.
 *
 * Return: The number of characters printed (excluding the null terminator).
 */

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	const char *str;
	int printed_chars = 0;

	for (str = format; str && *str != '\0'; str++)
	{
		if (*str == '%')
		{
			switch (*(str + 1))
			{
				case 'd':
				case 'i':
				{
					int value = va_arg(args, int);
					char buffer[20];
					snprintf(buffer, sizeof(buffer), "%d", value);
					for (char *p = buffer; *p != '\0'; p++)
					{
						_putchar(*p);
						printed_chars++;
					}
					break;
				}
				case 's':
				{
					char *value = va_arg(args, char*);
					for (char *p = value; *p != '\0'; p++)
					{
						_putchar(*p);
						printed_chars++;
					}
					break;
				}
				case 'c':
				{
					char value = (char)va_arg(args, int);
					_putchar(value);
					printed_chars++;
					break;
				}
				case '%':
					_putchar('%');
					printed_chars++;
					break;
				default:
					break;
			}
			str++;
		}
		else
		{
			_putchar(*str);
			printed_chars++;
		}
	}

	va_end(args);

	return (printed_chars);
}
