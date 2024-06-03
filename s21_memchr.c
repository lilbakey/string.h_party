#include "s21_string.h"

void *s21_memchr(const void *arr, int ch, s21_size_t n) {
  void *result = S21_NULL;
  while (n > 0) {
    const unsigned char *arr_ch = (const unsigned char *)arr;
    if (*arr_ch == ch) {
      result = (void *)arr_ch;
      break;
    }
    n--;
  }
  return result;
}