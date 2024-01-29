#include "../unit_tests.h"

START_TEST(s21_memcmp_test_1) {
  char str1[] = "Hello";
  char str2[] = "Hello";
  ck_assert_int_eq(s21_memcmp(str1, str2, 5), memcmp(str1, str2, 5));
}
END_TEST

START_TEST(s21_memcmp_test_2) {
  char str1[] = "Hello";
  char str2[] = "olHle";
  ck_assert_int_eq(s21_memcmp(str1, str2, 5) > 0, memcmp(str1, str2, 5) > 0);
}
END_TEST

START_TEST(s21_memcmp_test_3) {
  char str1[] = "Hello, World";
  char str2[] = "Hello";
  ck_assert_int_eq(s21_memcmp(str1, str2, 12) > 0, memcmp(str1, str2, 12) > 0);
}
END_TEST

START_TEST(s21_memcmp_test_4) {
  char str1[] = "Hello";
  char str2[] = "Hello, World";
  ck_assert_int_eq(s21_memcmp(str1, str2, 5), memcmp(str1, str2, 5));
}
END_TEST

START_TEST(s21_memcmp_test_5) {
  char str1[] = "Hello";
  char str2[] = "Hello, World";
  ck_assert_int_eq(s21_memcmp(str1, str2, 10) < 0, memcmp(str1, str2, 10) < 0);
}
END_TEST

START_TEST(s21_memcmp_test_6) {
  char str1[] = "";
  char str2[] = "";
  ck_assert_int_eq(s21_memcmp(str1, str2, 1), memcmp(str1, str2, 1));
}
END_TEST

Suite *test_memcmp(void) {
  Suite *suite = suite_create("memcmp");
  // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
  TCase *tcase_core = tcase_create("memcmp");

  // Добавление теста в группу тестов.
  tcase_add_test(tcase_core, s21_memcmp_test_1);
  tcase_add_test(tcase_core, s21_memcmp_test_2);
  tcase_add_test(tcase_core, s21_memcmp_test_3);
  tcase_add_test(tcase_core, s21_memcmp_test_4);
  tcase_add_test(tcase_core, s21_memcmp_test_5);
  tcase_add_test(tcase_core, s21_memcmp_test_6);

  // Добавление теста в тестовый набор.
  suite_add_tcase(suite, tcase_core);

  return suite;
}