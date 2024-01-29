#include "../unit_tests.h"

START_TEST(s21_strncpy_test_1) {
  char str1[10];
  const char *str2 = "Hello";
  ck_assert_str_eq(s21_strncpy(str1, str2, 3), strncpy(str1, str2, 3));
}
END_TEST

START_TEST(s21_strncpy_test_2) {
  char str1[20];
  const char *str2 = "Hello\0World";
  ck_assert_str_eq(s21_strncpy(str1, str2, 10), strncpy(str1, str2, 10));
}
END_TEST

START_TEST(s21_strncpy_test_3) {
  char str1[5];
  const char *str2 = "Hello";
  ck_assert_str_eq(s21_strncpy(str1, str2, 5), strncpy(str1, str2, 5));
}
END_TEST

START_TEST(s21_strncpy_test_4) {
  char str1[] = "WWWWW";
  const char *str2 = "Hello";
  ck_assert_str_eq(s21_strncpy(str1, str2, 5), strncpy(str1, str2, 5));
}
END_TEST

START_TEST(s21_strncpy_test_5) {
  const char *str = " world";
  ck_assert_ptr_null(s21_strncpy(NULL, str, 1));
}
END_TEST

Suite *test_strncpy(void) {
  Suite *suite = suite_create("strncpy");
  // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
  TCase *tcase_core = tcase_create("strncpy");

  // Добавление теста в группу тестов.
  tcase_add_test(tcase_core, s21_strncpy_test_1);
  tcase_add_test(tcase_core, s21_strncpy_test_2);
  tcase_add_test(tcase_core, s21_strncpy_test_3);
  tcase_add_test(tcase_core, s21_strncpy_test_4);
  tcase_add_test(tcase_core, s21_strncpy_test_5);

  // Добавление теста в тестовый набор.
  suite_add_tcase(suite, tcase_core);

  return suite;
}