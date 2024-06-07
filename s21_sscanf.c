#include "s21_sscanf.h"

int s21_sscanf(const char *str, const char *format, ...) {
    va_list args;
    va_start(args, format);
    int result = parse_format();
    va_end(args);
    return result;
}

int is_space(char ch) {
    int result = 0;
    if (*format == ' ' || *format == '\t' || *format == '\n' || *format == '\f' || *format == '\x0B' || *format == '\r') {
        result = 1;
    }
    return result;
}

int parse_format(const char *str, const char *format, va_list args) {
    int success_counter = 0;
    do {
        if (*format != '%' && (is_space(*format)) {
            while (is_space(*format)) {
                format++;
                while (is_space(*str)) str++;
            }
        } else {
            format++;
            int width, lenght = 0;
            if ((int)format > 47 && (int)format <= 58) {
                width = (int)format - 48;
            }
            success_counter += parse_specifier(format, width, &lenght, str, args);
        }
    } while (format);

    return success_counter;
}

int parse_specifier(const char *format, int width, int *lenght, const char *str, va_list args) {
    int result = 0;
    switch (*format) {
        case 'd':
            result = s21_atoi(*lenght, format, str, args);
            break;
        case 'c':
            break;
        case 'i':
            break;
        case 'e':
        case 'E':
        case 'f':
        case 'g':
        case 'G':
            break;
        case 'o':
            break;
        case 's':
            break;
        case 'u':
            break;
        case 'x':
        case 'X':
            break;
        case 'p':
            break;
        case 'n':
            break;
        case '%':
            break;
        case 'h':
            *lenght = 1;
        case 'l':
            *lenght = 2;
        case 'L':
            *lenght = 3;
    }
    return result;
}

int s21_atoi(int lenght, char *format, char *str, va_list args) {
    if (!lenght) var = va_arg(args, int);
    else if (lenght == 1) var = va_arg(args, short);
    else if (lenght == 2) var = va_arg(args, long);
    else if (lenght == 3) var = va_arg(args, long long);
    
    int *number_array = 0;
    int counter = 0;
    int result = 0;
    while (!(is_space(*str))) {
        counter++;
        realloc(number_array, sizeof(int) * counter);
        number_array[counter - 1] = (int)(*str) - 48;
    }
    
    int power = counter;
    for (int i = 0; i < counter; i++) {
        result += number_array[i] * power;
        power--;
    }
    free(number_array);
    var = result;
    return counter;
}