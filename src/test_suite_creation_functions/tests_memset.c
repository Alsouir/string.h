#include "../unit_tests.h"

START_TEST(s21_memset_test_1) {
  char str1[] = "Hello\0World";
  char str2[] = "Hello\0World";
  ck_assert_str_eq(s21_memset(str1, '$', 5), memset(str2, '$', 5));
}
END_TEST

START_TEST(s21_memset_test_2) {
  char str1[] = "Hello";
  char str2[] = "Hello";
  ck_assert_str_eq(s21_memset(str1, 93, 5), memset(str2, 93, 5));
}
END_TEST

START_TEST(s21_memset_test_3) {
  char str1[] = "Hello";
  char str2[] = "Hello";
  ck_assert_str_eq(s21_memset(str1, 'X', 4), memset(str2, 'X', 4));
}
END_TEST

START_TEST(s21_memset_test_4) {
  char str1[] = "Hello";
  char str2[] = "Hello";
  ck_assert_str_eq(s21_memset(str1, '\0', 2), memset(str2, '\0', 2));
}
END_TEST

START_TEST(s21_memset_test_5) { ck_assert_ptr_null(s21_memset(NULL, '!', 5)); }
END_TEST

Suite *test_memset(void) {
  Suite *suite = suite_create("memset");
  // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
  TCase *tcase_core = tcase_create("memset");

  // Добавление теста в группу тестов.
  tcase_add_test(tcase_core, s21_memset_test_1);
  tcase_add_test(tcase_core, s21_memset_test_2);
  tcase_add_test(tcase_core, s21_memset_test_3);
  tcase_add_test(tcase_core, s21_memset_test_4);
  tcase_add_test(tcase_core, s21_memset_test_5);

  // Добавление теста в тестовый набор.
  suite_add_tcase(suite, tcase_core);

  return suite;
}