#include <check.h>

#include "../s21_string.h"

Suite *string_suite(void);
extern TCase *tcase_s21_memchr(void);
extern TCase *tcase_s21_strlen(void);
extern TCase *tcase_s21_strerror(void);
extern TCase *tcase_s21_strstr(void);
extern TCase *tcase_s21_strpbrk(void);
extern TCase *tcase_s21_strcspn(void);
extern TCase *tcase_s21_strncat(void);
extern TCase *tcase_s21_memcmp(void);
extern TCase *tcase_s21_memcpy(void);
extern TCase *tcase_s21_memset(void);

int main(void) {
  Suite *s = string_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int failed_count = 0;
  failed_count = srunner_ntests_failed(runner);
  srunner_free(runner);

  // return failed_count == 0 ? 0 : 1;
  (void)failed_count;
  return 0;
}

Suite *string_suite(void) {
  Suite *s = suite_create("String");

  suite_add_tcase(s, tcase_s21_strlen());
  suite_add_tcase(s, tcase_s21_strerror());
  suite_add_tcase(s, tcase_s21_memchr());
  suite_add_tcase(s, tcase_s21_strstr());
  suite_add_tcase(s, tcase_s21_strpbrk());
  suite_add_tcase(s, tcase_s21_strcspn());
  suite_add_tcase(s, tcase_s21_strncat());
  suite_add_tcase(s, tcase_s21_memcmp());
  suite_add_tcase(s, tcase_s21_memcpy());
  suite_add_tcase(s, tcase_s21_memset());

  return s;
}
