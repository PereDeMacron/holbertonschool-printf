#include <unistd.h>
#include <stdarg.h>

/**
 * s - Print a formatted string with string substitution.
 *
 * This function prints a formatted string with string substitution. It supports
 * replacing '%s' with a null-terminated string.
 *
 * @format: The formatted string to print.
 *
 * Return: The number of characters printed (excluding the null terminator).
 */
int string(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int printed_chars = 0;

    while (*format)
    {
        if (*format == 's')
        {
            char *str = va_arg(args, char *);
            int len = 0;
            while (str[len])
            {
                len++;
            }
            write(1, str, len);
            printed_chars += len;
        }
        else
        {
            write(1, format, 1);
            printed_chars++;
        }
        format++;
    }

    va_end(args);
    return (printed_chars);
}