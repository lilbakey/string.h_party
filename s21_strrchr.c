#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *result = s21_NULL;
  int counter = 0;
  s21_size_t length = strlen(str);
  for (s21_size_t i = 0; i < length; i++) {
    if (str[i] == (char)c) counter++;
  }
  char *temp = (char *)str;
  for (int j = 0; j < counter; j++) {
    result = strchr(++temp, c);
    temp = result;
  }
  return (char *)result;
}