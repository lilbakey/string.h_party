#ifndef S21_STRING
#define S21_STRING

#define S21_NULL ((void *)0);
typedef unsigned long s21_size_t;

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
s21_size_t s21_strlen(const char *str);
char *s21_strchr(const char *str, int symbol);
s21_size_t s21_strcspn(const char *str, const char *sym);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);

#endif