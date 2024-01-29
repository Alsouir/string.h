#include "../unit_tests.h"

START_TEST(strncmp_1) {
  char s1[15] = "Hello, world!";
  char s2[15] = "Hello, world!";
  size_t n = 1;
  ck_assert_int_eq(strncmp(s1, s2, n), s21_strncmp(s1, s2, n));
}
END_TEST

START_TEST(strncmp_2) {
  char s1[15] = "Hello, asdasd";
  char s2[15] = "Hello, world!";
  size_t n = 7;
  ck_assert_int_eq(strncmp(s1, s2, n), s21_strncmp(s1, s2, n));
}
END_TEST

START_TEST(strncmp_3) {
  char s1[15] = "Hello, asdasd";
  char s2[15] = "Hello, world!";
  size_t n = 15;
  ck_assert_int_eq(strncmp(s1, s2, n), s21_strncmp(s1, s2, n));
}
END_TEST

START_TEST(strncmp_4) {
  char s1[15] = "Hello, world!";
  char s2[15] = "hello, world!";
  size_t n = 15;
  ck_assert_int_eq(strncmp(s1, s2, n), s21_strncmp(s1, s2, n));
}
END_TEST

START_TEST(strncmp_5) {
  char s1[15] = "123";
  char s2[15] = "asd";
  size_t n = 0;
  ck_assert_int_eq(strncmp(s1, s2, n), s21_strncmp(s1, s2, n));
}
END_TEST

START_TEST(strncmp_6) {
  char s1[15] = "\0123";
  char s2[15] = "\0asd";
  size_t n = 0;
  ck_assert_int_eq(strncmp(s1, s2, n), s21_strncmp(s1, s2, n));
}
END_TEST

START_TEST(strncmp_7) {
  char s1[15] = "\0123";
  char s2[15] = "\0123";
  size_t n = 3;
  ck_assert_int_eq(strncmp(s1, s2, n), s21_strncmp(s1, s2, n));
}
END_TEST

START_TEST(strncmp_8) {
  char s1[15] = "\0123";
  char s2[15] = "\0asd";
  size_t n = 3;
  ck_assert_int_eq(strncmp(s1, s2, n), s21_strncmp(s1, s2, n));
}
END_TEST

START_TEST(strncmp_9) {
  char s1[] = "";
  char s2[] = "";
  size_t n = 10;
  ck_assert_int_eq(strncmp(s1, s2, n), s21_strncmp(s1, s2, n));
}
END_TEST

START_TEST(strncmp_10) {
  char s1[] = "";
  char s2[] = "a";
  size_t n = 1;
  ck_assert_int_eq(strncmp(s1, s2, n), s21_strncmp(s1, s2, n));
}
END_TEST

START_TEST(strncmp_11) {
  char s1[] = "a";
  char s2[] = "";
  size_t n = 1;
  ck_assert_int_eq(strncmp(s1, s2, n), s21_strncmp(s1, s2, n));
}
END_TEST

Suite *test_strncmp(void) {
  Suite *suite = suite_create("strncmp");
  // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
  TCase *tcase_core = tcase_create("strncmp");

  // Добавление теста в группу тестов.
  tcase_add_test(tcase_core, strncmp_1);
  tcase_add_test(tcase_core, strncmp_2);
  tcase_add_test(tcase_core, strncmp_3);
  tcase_add_test(tcase_core, strncmp_4);
  tcase_add_test(tcase_core, strncmp_5);
  tcase_add_test(tcase_core, strncmp_6);
  tcase_add_test(tcase_core, strncmp_7);
  tcase_add_test(tcase_core, strncmp_8);
  tcase_add_test(tcase_core, strncmp_9);
  tcase_add_test(tcase_core, strncmp_10);
  tcase_add_test(tcase_core, strncmp_11);

  // Добавление теста в тестовый набор.
  suite_add_tcase(suite, tcase_core);

  return suite;
}