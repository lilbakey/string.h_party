#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = s21_NULL;
  char *temp = (char *)str1;
  s21_size_t length = s21_strcspn(str1, str2);
  for (s21_size_t i = 0; i < length; i++) temp++;
  if (length) result = temp;

  return result;
}