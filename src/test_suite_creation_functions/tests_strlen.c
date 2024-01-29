#include "../unit_tests.h"

START_TEST(strlen_1) {
  char s1[] = "Hello, world!";
  ck_assert_int_eq(strlen(s1), s21_strlen(s1));
}
END_TEST

START_TEST(strlen_2) {
  char *s1 = "Hello, asdasd";
  ck_assert_int_eq(strlen(s1), s21_strlen(s1));
}
END_TEST

START_TEST(strlen_3) {
  char *s1 = "Hello\n\n\n\n, asdasd";
  ck_assert_int_eq(strlen(s1), s21_strlen(s1));
}
END_TEST

START_TEST(strlen_4) {
  char *s1 = "Hello\n\n\n\n, asdasd21332189";
  ck_assert_int_eq(strlen(s1), s21_strlen(s1));
}
END_TEST

START_TEST(strlen_5) {
  char *s1 = "Hello\n\n\n\n, asdasd21332189\0";
  ck_assert_int_eq(strlen(s1), s21_strlen(s1));
}
END_TEST

START_TEST(strlen_6) {
  char *s1 = "Hell\0o\n\n\n\n, asdasd21332189\0";
  ck_assert_int_eq(strlen(s1), s21_strlen(s1));
}
END_TEST

START_TEST(strlen_7) {
  char *s1 = "Hello\n\n\n\n, asdasd21332189\0\0";
  ck_assert_int_eq(strlen(s1), s21_strlen(s1));
}
END_TEST

START_TEST(strlen_8) {
  char *s1 = "Hello\n\n\n\n, asdasd21332189\t\t";
  ck_assert_int_eq(strlen(s1), s21_strlen(s1));
}
END_TEST

START_TEST(strlen_9) {
  char *s1 = "";
  ck_assert_int_eq(strlen(s1), s21_strlen(s1));
}
END_TEST

START_TEST(strlen_10) {
  char *s1 = "    . ";
  ck_assert_int_eq(strlen(s1), s21_strlen(s1));
}
END_TEST

START_TEST(strlen_11) {
  char *s1 = "\n\n\n\n\t\t";
  ck_assert_int_eq(strlen(s1), s21_strlen(s1));
}
END_TEST

START_TEST(strlen_12) {
  char *s1 = "\\n\\n\\n\\n\\t\\t";
  ck_assert_int_eq(strlen(s1), s21_strlen(s1));
}
END_TEST

Suite *test_strlen(void) {
  Suite *suite = suite_create("strlen");
  // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
  TCase *tcase_core = tcase_create("strlen");

  // Добавление теста в группу тестов.
  tcase_add_test(tcase_core, strlen_1);
  tcase_add_test(tcase_core, strlen_2);
  tcase_add_test(tcase_core, strlen_3);
  tcase_add_test(tcase_core, strlen_4);
  tcase_add_test(tcase_core, strlen_5);
  tcase_add_test(tcase_core, strlen_6);
  tcase_add_test(tcase_core, strlen_7);
  tcase_add_test(tcase_core, strlen_8);
  tcase_add_test(tcase_core, strlen_9);
  tcase_add_test(tcase_core, strlen_10);
  tcase_add_test(tcase_core, strlen_11);
  tcase_add_test(tcase_core, strlen_12);

  // Добавление теста в тестовый набор.
  suite_add_tcase(suite, tcase_core);

  return suite;
}