#include "s21_sscanf.h"

int s21_sscanf(const char *str, const char *format, ...) {
    va_list args;
    va_start(args);

    return 0;
}

int is_space(int ch) {
    int result = 0;
    if (ch == ' '  || ch == '\t') {
        result = 1;
    }
    return result;
}