#include "../unit_tests.h"

START_TEST(s21_strstr_test_1) {
  const char *str1 = "Hello";
  const char *str2 = "el";
  ck_assert_str_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test_2) {
  const char *str1 = "Hello";
  const char *str2 = "";
  ck_assert_str_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test_3) {
  const char *str1 = "Hello";
  const char *str2 = "Hello";
  ck_assert_str_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test_4) {
  const char *str1 = "";
  const char *str2 = "Hello";
  ck_assert_ptr_null(s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test_5) {
  const char *str1 = "Hello";
  const char *str2 = "";
  ck_assert_str_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

Suite *test_strstr(void) {
  Suite *suite = suite_create("strstr");
  // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
  TCase *tcase_core = tcase_create("strstr");

  // Добавление теста в группу тестов.
  tcase_add_test(tcase_core, s21_strstr_test_1);
  tcase_add_test(tcase_core, s21_strstr_test_2);
  tcase_add_test(tcase_core, s21_strstr_test_3);
  tcase_add_test(tcase_core, s21_strstr_test_4);
  tcase_add_test(tcase_core, s21_strstr_test_5);

  // Добавление теста в тестовый набор.
  suite_add_tcase(suite, tcase_core);

  return suite;
}