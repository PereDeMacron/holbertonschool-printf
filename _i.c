#include "main.h"

int _i(const char *format, ...)
{
    int printed_chars = 0;
    va_list args;
    const char *str;
    int num_len = 0;
    char buffer[20];
    char *p;

    va_start(args, format);

    for (str = format; str && *str != '\0'; str++)
    {
        if (*str == '%')
        {
            if (*(str + 1) == 'i')
            {
                int num = va_arg(args, int);
                int temp = num;

                if (num < 0)
                {
                    num_len++;
                    num *= -1;
                }

                while (temp)
                {
                    temp /= 10;
                    num_len++;
                }

                snprintf(buffer, sizeof(buffer), "%d", num);
                p = buffer;
                while (*p != '\0')
                {
                    _putchar(*p);
                    printed_chars++;
                    p++;
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
