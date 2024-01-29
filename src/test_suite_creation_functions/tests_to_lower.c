#include "../unit_tests.h"

START_TEST(s21_to_lower_test_1) {
  const char *str = "HELLO";
  char *result = s21_to_lower(str);
  ck_assert_str_eq(result, "hello");
  free(result);
}
END_TEST

START_TEST(s21_to_lower_test_2) {
  const char *str1 = "heLLo";
  char *result = s21_to_lower(str1);
  ck_assert_str_eq(result, "hello");
  free(result);
}
END_TEST

START_TEST(s21_to_lower_test_3) {
  const char *str = "1";
  char *result = s21_to_lower(str);
  ck_assert_str_eq(result, "1");
  free(result);
}
END_TEST

START_TEST(s21_to_lower_test_4) {
  const char *str = "";
  char *result = s21_to_lower(str);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

Suite *test_to_lower(void) {
  Suite *s = suite_create("to_lower");
  TCase *tc = tcase_create("to_lower");

  tcase_add_test(tc, s21_to_lower_test_1);
  tcase_add_test(tc, s21_to_lower_test_2);
  tcase_add_test(tc, s21_to_lower_test_3);
  tcase_add_test(tc, s21_to_lower_test_4);

  suite_add_tcase(s, tc);
  return s;
}