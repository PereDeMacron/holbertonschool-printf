#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int i (const char *format, ...)
{
	int printed_chars = 0;
	va_list args;
	const char *str;

	va_start(args, format);

	for (str = format; str && *str != '\0'; str++)
	{
		if (*str == '%')
		{
			if (*(str + 1) == 'i')
			{
				int num = va_arg(args, int);
				int num_len = 1;
				int temp = num;

				if (num < 0)
				{
					num_len++;
					num *= -1;
				}
				while (temp /= 10)
				num_len++;

				if (num < 0)
				{
					printed_chars += _putchar('+');
					num *= -1;
				}
				while (num_len--)
				{
					int divisor = 1;
					int digit;
					for (int i = 0; i < num_len; i++)
					divisor *= 10;
					digit = num / divisor;
					num %= divisor;
					printed_chars += _putchar('0' + digit);
				}
				str++;
			}
			else
			{
				_putchar(*str);
				printed_chars++;
			}
		}
		else
		{
			_putchar(*str);
			printed_chars++;
		}
	}

	va_end(args);

	return printed_chars;
}
