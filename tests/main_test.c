#include <check.h>

#include "../s21_string.h"

Suite *string_suite(void);
extern TCase *tcase_s21_strlen(void);

int main(void) {

  

  Suite *s = string_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int failed_count = 0;
  failed_count = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed_count == 0 ? 0 : 1;
}



Suite *string_suite(void) {
  Suite *s = suite_create("String");

  suite_add_tcase(s, tcase_s21_strlen());

  return s;
}
