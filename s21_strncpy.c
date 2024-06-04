#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i;
  for (i = 0; i < n; i++) {
    dest[i] = src[i];
  }
  for (; i < n; i++) {
    dest[i + 1] = '\0';
  }

  return dest;
}