#ifndef S21_SSCANF
#define S21_SSCANF

#include <stdarg.h>
#include <stdlib.h>

typedef struct {
    int width;
    int lenght;
} options;

int is_space(int ch);
int parse_format(const char *str, const char *format, va_list args);

#endif