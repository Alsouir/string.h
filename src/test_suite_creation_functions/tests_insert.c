#include "../unit_tests.h"

START_TEST(s21_insert_test_1) {
  const char *src = "heLLo";
  const char *str = "AAAAAAA";
  char *result = s21_insert(src, str, 3);
  ck_assert_str_eq(result, "heLAAAAAAALo");
  free(result);
}
END_TEST

START_TEST(s21_insert_test_2) {
  const char *src = "heLLo";
  const char *str = "";
  char *result = s21_insert(src, str, 3);
  ck_assert_str_eq(result, "heLLo");
  free(result);
}
END_TEST

START_TEST(s21_insert_test_3) {
  const char *src = "heLLo";
  const char *str = "    ";
  char *result = s21_insert(src, str, 3);
  ck_assert_str_eq(result, "heL    Lo");
  free(result);
}
END_TEST

START_TEST(s21_insert_test_4) {
  const char *src = "heLLo";
  // const char *str = "me";
  char *result = s21_insert(src, s21_NULL, 3);
  ck_assert_ptr_null(result);
  // free (result);
}
END_TEST

START_TEST(s21_insert_test_5) {
  // const char *src = "heLLo";
  const char *str = "me";
  char *result = s21_insert(s21_NULL, str, 3);
  ck_assert_ptr_null(result);
  // free (result);
}
END_TEST

Suite *test_insert(void) {
  Suite *s = suite_create("insert");
  TCase *tc = tcase_create("insert");

  tcase_add_test(tc, s21_insert_test_1);
  tcase_add_test(tc, s21_insert_test_2);
  tcase_add_test(tc, s21_insert_test_3);
  tcase_add_test(tc, s21_insert_test_4);
  tcase_add_test(tc, s21_insert_test_5);

  suite_add_tcase(s, tc);
  return s;
}