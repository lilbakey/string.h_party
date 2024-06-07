#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  if (delim == s21_NULL) return s21_NULL;

  char *result = s21_NULL;
  static char *string = s21_NULL;

  if (str) string = str;

  if (string) {
    // skip begin delimeters
    while (*string && !s21_strcspn(string, delim)) string++;

    if (*string != '\0') {
      result = string;

      while (*string && !s21_strchr(delim, *string)) string++;

      if (*string) {
        *string++ = '\0';
      } else
        string = s21_NULL;
    }
  }
  return result;
}
