#include "../unit_tests.h"

START_TEST(strcspn_1) {
  char s1[15] = "Hello, world!";
  char s2[15] = "";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_2) {
  char s1[15] = "Hello, asdasd";
  char s2[15] = "asd";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_3) {
  char s1[15] = "Hello, asdasd";
  char s2[15] = "\0";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_4) {
  char s1[15] = "Hello, world!";
  char s2[15] = "123";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_5) {
  char s1[15] = "123";
  char s2[15] = "asd";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_6) {
  char s1[15] = "\0123";
  char s2[15] = "\0asd";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_7) {
  char s1[15] = "\0123";
  char s2[15] = "\0123";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_8) {
  char s1[15] = "\0123asd";
  char s2[15] = "\0asd";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_9) {
  char s1[] = "";
  char s2[] = "";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_10) {
  char s1[] = "";
  char s2[] = "a";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_11) {
  char s1[] = "a";
  char s2[] = "";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

Suite *test_strcspn(void) {
  Suite *suite = suite_create("strcspn");
  // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
  TCase *tcase_core = tcase_create("strcspn");

  // Добавление теста в группу тестов.
  tcase_add_test(tcase_core, strcspn_1);
  tcase_add_test(tcase_core, strcspn_2);
  tcase_add_test(tcase_core, strcspn_3);
  tcase_add_test(tcase_core, strcspn_4);
  tcase_add_test(tcase_core, strcspn_5);
  tcase_add_test(tcase_core, strcspn_6);
  tcase_add_test(tcase_core, strcspn_7);
  tcase_add_test(tcase_core, strcspn_8);
  tcase_add_test(tcase_core, strcspn_9);
  tcase_add_test(tcase_core, strcspn_10);
  tcase_add_test(tcase_core, strcspn_11);

  // Добавление теста в тестовый набор.
  suite_add_tcase(suite, tcase_core);

  return suite;
}