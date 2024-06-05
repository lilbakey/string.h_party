#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *result = s21_NULL;
  while (n > 0) {
    const unsigned char *ch = (const unsigned char *)str;
    if (*ch == c) {
      result = (void *)ch;
      break;
    }
    n--;
    str++;
  }
  return result;
}