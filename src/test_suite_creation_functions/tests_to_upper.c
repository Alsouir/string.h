#include "../unit_tests.h"

START_TEST(s21_to_upper_test_1) {
  const char *str = "Hello";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, "HELLO");
  free(result);
}
END_TEST

START_TEST(s21_to_upper_test_2) {
  const char *str1 = "heLLo";
  char *result = s21_to_upper(str1);
  ck_assert_str_eq(result, "HELLO");
  free(result);
}
END_TEST

START_TEST(s21_to_upper_test_3) {
  const char *str = "1";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, "1");
  free(result);
}
END_TEST

START_TEST(s21_to_upper_test_4) {
  const char *str = "";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

Suite *test_to_upper(void) {
  Suite *s = suite_create("to_upper");
  TCase *tc = tcase_create("to_upper");

  tcase_add_test(tc, s21_to_upper_test_1);
  tcase_add_test(tc, s21_to_upper_test_2);
  tcase_add_test(tc, s21_to_upper_test_3);
  tcase_add_test(tc, s21_to_upper_test_4);

  suite_add_tcase(s, tc);
  return s;
}