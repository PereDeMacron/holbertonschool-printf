#include "main.h"
#include <string.h>

int s(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;
    va_start(args, format);

    while (*format)
    {
        if (*format == 's')
        {
            char *str = va_arg(args, char *);
            int len = strlen(str);
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
    return printed_chars;
}
