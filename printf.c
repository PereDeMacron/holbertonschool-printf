#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int _putchar(char c)
{
    return write(1, &c, 1);
}

int _printf(const char *format, ...)
{
    va_list args;
    const char *str;
    int printed_chars = 0;
    char buffer[20];
    char *p = buffer;
    
    va_start(args, format);

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
                    snprintf(buffer, sizeof(buffer), "%d", value);
                    while (*p != '\0')
                    {
                        _putchar(*p);
                        printed_chars++;
                        p++;
                    }
                    break;
                }
                case 's':
                {
                    char *value = va_arg(args, char*);
                    char *p;
                    for (p = value; *p != '\0'; p++)
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

    return printed_chars;
}
