#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  int len = 0;
  while (*str != '\0') {
    len++;
    str++;
  }
  return len;
}
