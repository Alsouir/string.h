#include "../unit_tests.h"

START_TEST(strncat_1) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "Hello, world!";
  size_t n = 1;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_2) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "\0";
  size_t n = 1;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_3) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "\n\0\\d\f\\g\7";
  size_t n = 3;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_4) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "";
  size_t n = 0;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_5) {
  char s1[30] = "";
  char s2[30] = "";
  char s3[] = "Hello, world!";
  size_t n = 13;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_6) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] = "O la la. qwe asd zxc.";
  size_t n = 6;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_7) {
  char s1[30] = "";
  char s2[30] = "";
  char s3[] = "Hello, world!";
  size_t n = 3;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_8) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] = "o la la.";
  size_t n = 2;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_9) {
  char s1[100] = "";
  char s2[100] = "";
  char s3[] = "";
  size_t n = 10;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_10) {
  char s1[100] = "Hello\0, world!";
  char s2[100] = "Hello\0, world!";
  char s3[] = "O la\0 la.";
  size_t n = 15;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_11) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] = "\0";
  size_t n = 1;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_12) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] = "\0";
  size_t n = 0;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_13) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] = "\0\0\0\0";
  size_t n = 4;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_14) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] = "";
  size_t n = 2;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_15) {
  char s1[100] = "Hello, world!\0\0\0";
  char s2[100] = "Hello, world!\0\0\0";
  char s3[] = "O la la.";
  size_t n = 0;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

Suite *test_strncat(void) {
  Suite *suite = suite_create("strncat");
  // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
  TCase *tcase_core = tcase_create("strncat");

  // Добавление теста в группу тестов.
  tcase_add_test(tcase_core, strncat_1);
  tcase_add_test(tcase_core, strncat_2);
  tcase_add_test(tcase_core, strncat_3);
  tcase_add_test(tcase_core, strncat_4);
  tcase_add_test(tcase_core, strncat_5);
  tcase_add_test(tcase_core, strncat_6);
  tcase_add_test(tcase_core, strncat_7);
  tcase_add_test(tcase_core, strncat_8);
  tcase_add_test(tcase_core, strncat_9);
  tcase_add_test(tcase_core, strncat_10);
  tcase_add_test(tcase_core, strncat_11);
  tcase_add_test(tcase_core, strncat_12);
  tcase_add_test(tcase_core, strncat_13);
  tcase_add_test(tcase_core, strncat_14);
  tcase_add_test(tcase_core, strncat_15);

  // Добавление теста в тестовый набор.
  suite_add_tcase(suite, tcase_core);

  return suite;
}