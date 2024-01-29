#include "../unit_tests.h"

START_TEST(s21_strchr_test_1) {
  char str1[] = "Hello";
  char str2[] = "Hello";
  ck_assert_str_eq(s21_strchr(str1, 'e'), strchr(str2, 'e'));
}
END_TEST

START_TEST(s21_strchr_test_2) {
  char str1[] = "Hello";
  ck_assert_ptr_null(s21_strchr(str1, 'x'));
}
END_TEST

START_TEST(s21_strchr_test_3) {
  char str1[] = "Hello";
  char str2[] = "Hello";
  ck_assert_str_eq(s21_strchr(str1, '\0'), strchr(str2, '\0'));
}
END_TEST

START_TEST(s21_strchr_test_4) { ck_assert_ptr_null(s21_strchr(NULL, 'a')); }
END_TEST

Suite *test_strchr(void) {
  Suite *suite = suite_create("strchr");
  // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
  TCase *tcase_core = tcase_create("strchr");

  // Добавление теста в группу тестов.
  tcase_add_test(tcase_core, s21_strchr_test_1);
  tcase_add_test(tcase_core, s21_strchr_test_2);
  tcase_add_test(tcase_core, s21_strchr_test_3);
  tcase_add_test(tcase_core, s21_strchr_test_4);

  // Добавление теста в тестовый набор.
  suite_add_tcase(suite, tcase_core);

  return suite;
}