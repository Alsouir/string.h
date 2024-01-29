#include "../unit_tests.h"

START_TEST(s21_trim_test_1) {
  const char *src = "!!!heLLo world!!!";
  const char *str = "!";
  char *result = s21_trim(src, str);
  ck_assert_str_eq(result, "heLLo world");
  free(result);
}
END_TEST

START_TEST(s21_trim_test_2) {
  const char *src = "abcheLLo !abc";
  const char *str = "abc";
  char *result = s21_trim(src, str);
  ck_assert_str_eq(result, "heLLo !");
  free(result);
}
END_TEST

START_TEST(s21_trim_test_3) {
  const char *src = "!heLLo!";
  const char *str = "!";
  char *result = s21_trim(src, str);
  ck_assert_str_eq(result, "heLLo");
  free(result);
}
END_TEST

START_TEST(s21_trim_test_4) {
  const char *src = "heLLo";
  char *result = s21_trim(src, s21_NULL);
  ck_assert_str_eq(result, "heLLo");
  free(result);
}
END_TEST

START_TEST(s21_trim_test_5) {
  const char *str = "me";
  char *result = s21_trim(s21_NULL, str);
  ck_assert_ptr_null(result);
}
END_TEST

Suite *test_trim(void) {
  Suite *s = suite_create("trim");
  TCase *tc = tcase_create("trim");

  tcase_add_test(tc, s21_trim_test_1);
  tcase_add_test(tc, s21_trim_test_2);
  tcase_add_test(tc, s21_trim_test_3);
  tcase_add_test(tc, s21_trim_test_4);
  tcase_add_test(tc, s21_trim_test_5);

  suite_add_tcase(s, tc);
  return s;
}