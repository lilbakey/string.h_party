#include "s21_string.h"

s21_size_t s21_strcspn(const char *str, const char *sym) {
  int length = 0;
  int i = 0;
  char symbol_sym = sym[i];
  while (symbol_sym != '\0') {
    int j = 0;
    char symbol_str = str[j];
    while (symbol_str != '\0') {
      if (symbol_str == symbol_sym) {
        if (length == 0) length = j;
        if (length > 0 && j < length) length = j;
      }
      symbol_str = str[j++];
    }
    symbol_sym = sym[i++];
  }
  return length - 1;
}
