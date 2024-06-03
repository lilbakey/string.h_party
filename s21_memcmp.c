#include "s21_string.h"

int s21_memcmp(const void *arr1, const void *arr2, s21_size_t n) {
  int result = 0;
  while (n > 0 && !result) {
    int ch1 = *((char *)arr1++);
    int ch2 = *((char *)arr2++);
    if (ch1 != ch2) result = ch1 - ch2;
    n--;
  }
  return result;
}