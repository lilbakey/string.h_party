#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = s21_NULL;
  s21_size_t length = s21_strlen(needle);
  while (*haystack) {
    if (!memcmp(haystack++, needle, length)) {
      result = (char *)(haystack - 1);
      break;
    }
  }
  return result;
}