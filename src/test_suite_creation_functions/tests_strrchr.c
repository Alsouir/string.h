#include "../unit_tests.h"

START_TEST(strrchr_1) {
  char s1[] = "Hello, world!";
  int c = 'l';
  ck_assert_pstr_eq(strrchr(s1, c), s21_strrchr(s1, c));
}
END_TEST

START_TEST(strrchr_2) {
  char *s1 = "Hello, asdasd";
  int c = 'h';
  ck_assert_pstr_eq(strrchr(s1, c), s21_strrchr(s1, c));
}
END_TEST

START_TEST(strrchr_3) {
  char *s1 = "Hello\n\n\n\n, asdasd";
  int c = '\t';
  ck_assert_pstr_eq(strrchr(s1, c), s21_strrchr(s1, c));
}
END_TEST

START_TEST(strrchr_4) {
  char *s1 = "Hello\n\n\n\n, asdasd21332189";
  int c = 'n';
  ck_assert_pstr_eq(strrchr(s1, c), s21_strrchr(s1, c));
}
END_TEST

START_TEST(strrchr_5) {
  char *s1 = "Hello\n\n\n\n, asdasd21332189\0";
  int c = '\0';
  ck_assert_pstr_eq(strrchr(s1, c), s21_strrchr(s1, c));
}
END_TEST

START_TEST(strrchr_6) {
  char *s1 = "Hell\0o\n\n\n\n, asdasd21332189\0";
  int c = '\n';
  ck_assert_pstr_eq(strrchr(s1, c), s21_strrchr(s1, c));
}
END_TEST

START_TEST(strrchr_7) {
  char *s1 = "Hello, asdasd";
  int c = 'H';
  ck_assert_pstr_eq(strrchr(s1, c), s21_strrchr(s1, c));
}
END_TEST

START_TEST(strrchr_8) {
  char *s1 = "Hello\n\n\n\n, asdasd21332189\t\t";
  int c = 'z';
  ck_assert_pstr_eq(strrchr(s1, c), s21_strrchr(s1, c));
}
END_TEST

START_TEST(strrchr_9) {
  char *s1 = "";
  int c = 'H';
  ck_assert_pstr_eq(strrchr(s1, c), s21_strrchr(s1, c));
}
END_TEST

START_TEST(strrchr_10) {
  char *s1 = "    . ";
  int c = ' ';
  ck_assert_pstr_eq(strrchr(s1, c), s21_strrchr(s1, c));
}
END_TEST

START_TEST(strrchr_11) {
  char *s1 = "\n\n\n\n\t\t";
  int c = ' ';
  ck_assert_pstr_eq(strrchr(s1, c), s21_strrchr(s1, c));
}
END_TEST

START_TEST(strrchr_12) {
  char *s1 = "\\n\\n\\n\\n\\t\\t";
  int c = '\n';
  ck_assert_pstr_eq(strrchr(s1, c), s21_strrchr(s1, c));
}
END_TEST

START_TEST(strrchr_13) {
  char *s1 = "\0\\n\\n\\n\\n\\t\\tn";
  int c = 'n';
  ck_assert_pstr_eq(strrchr(s1, c), s21_strrchr(s1, c));
}
END_TEST

START_TEST(strrchr_14) {
  char *s1 = "\0\0\\n\\n\\n\\n\\t\\tn";
  int c = '\0';
  ck_assert_pstr_eq(strrchr(s1, c), s21_strrchr(s1, c));
}
END_TEST

Suite *test_strrchr(void) {
  Suite *suite = suite_create("strrchr");
  // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
  TCase *tcase_core = tcase_create("strrchr");

  // Добавление теста в группу тестов.
  tcase_add_test(tcase_core, strrchr_1);
  tcase_add_test(tcase_core, strrchr_2);
  tcase_add_test(tcase_core, strrchr_3);
  tcase_add_test(tcase_core, strrchr_4);
  tcase_add_test(tcase_core, strrchr_5);
  tcase_add_test(tcase_core, strrchr_6);
  tcase_add_test(tcase_core, strrchr_7);
  tcase_add_test(tcase_core, strrchr_8);
  tcase_add_test(tcase_core, strrchr_9);
  tcase_add_test(tcase_core, strrchr_10);
  tcase_add_test(tcase_core, strrchr_11);
  tcase_add_test(tcase_core, strrchr_12);
  tcase_add_test(tcase_core, strrchr_13);
  tcase_add_test(tcase_core, strrchr_14);

  // Добавление теста в тестовый набор.
  suite_add_tcase(suite, tcase_core);

  return suite;
}