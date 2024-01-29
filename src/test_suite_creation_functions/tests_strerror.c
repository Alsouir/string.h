#include "../unit_tests.h"

START_TEST(s21_strerror_test_1) {
  ck_assert_str_eq(s21_strerror(3), strerror(3));
}
END_TEST

START_TEST(s21_strerror_test_2) {
  ck_assert_str_eq(s21_strerror(100), strerror(100));
}
END_TEST

START_TEST(s21_strerror_test_3) {
  ck_assert_str_eq(s21_strerror(3000), strerror(3000));
}
END_TEST

Suite *test_strerror(void) {
  Suite *suite = suite_create("strerror");
  // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
  TCase *tcase_core = tcase_create("strerror");

  // Добавление теста в группу тестов.
  tcase_add_test(tcase_core, s21_strerror_test_1);
  tcase_add_test(tcase_core, s21_strerror_test_2);
  tcase_add_test(tcase_core, s21_strerror_test_3);

  // Добавление теста в тестовый набор.
  suite_add_tcase(suite, tcase_core);

  return suite;
}