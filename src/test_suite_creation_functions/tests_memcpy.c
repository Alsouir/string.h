#include "../unit_tests.h"

START_TEST(memcpy_1) {
  char *string = "hello world";
  char new_string[4];
  char new_string1[4];
  size_t n = 3;
  ck_assert_str_eq(memcpy(new_string, string, n),
                   s21_memcpy(new_string1, string, n));
}
END_TEST

START_TEST(memcpy_2) {
  char *string = "h\nello world";
  char new_string[4];
  char new_string1[4];
  size_t n = 3;
  ck_assert_str_eq(memcpy(new_string, string, n),
                   s21_memcpy(new_string1, string, n));
}
END_TEST

START_TEST(memcpy_3) {
  char *string = "hello world";
  char new_string[25];
  char new_string1[25];
  size_t n = 25;
  ck_assert_str_eq(memcpy(new_string, string, n),
                   s21_memcpy(new_string1, string, n));
}
END_TEST

START_TEST(memcpy_4) {
  char *string = "hello\0 world";
  char new_string[8];
  char new_string1[8];
  size_t n = 8;
  ck_assert_str_eq(memcpy(new_string, string, n),
                   s21_memcpy(new_string1, string, n));
}
END_TEST

START_TEST(memcpy_5) {
  char string[] = "hello world";
  char new_string[] = "123456789";
  char new_string1[] = "123456789";
  size_t n = 8;
  ck_assert_str_eq(memcpy(new_string, string, n),
                   s21_memcpy(new_string1, string, n));
}
END_TEST

START_TEST(memcpy_6) {
  char *string = "hell\0o world";
  char new_string[8];
  char new_string1[8];
  size_t n = 8;
  ck_assert_str_eq(memcpy(new_string, string, n),
                   s21_memcpy(new_string1, string, n));
}
END_TEST

START_TEST(memcpy_7) {
  char string[] = "asd";
  char new_string[] = "1234\056789";
  char new_string1[] = "1234\056789";
  size_t n = 3;
  ck_assert_str_eq(memcpy(new_string, string, n),
                   s21_memcpy(new_string1, string, n));
}
END_TEST

START_TEST(memcpy_8) {
  char *string = "";
  char *new_string = " ";
  char *new_string1 = " ";
  size_t n = 0;
  ck_assert_str_eq(memcpy(new_string, string, n),
                   s21_memcpy(new_string1, string, n));
}
END_TEST

START_TEST(memcpy_9) {
  char *string = " ";
  char *new_string = "";
  char *new_string1 = "";
  size_t n = 0;
  ck_assert_str_eq(memcpy(new_string, string, n),
                   s21_memcpy(new_string1, string, n));
}
END_TEST

START_TEST(memcpy_10) {
  char *string = "111";
  char new_string[6] = "222";
  char new_string1[6] = "222";
  size_t n = 3;
  ck_assert_str_eq(memcpy(new_string, string, n),
                   s21_memcpy(new_string1, string, n));
}
END_TEST

Suite *test_memcpy(void) {
  Suite *suite = suite_create("memcpy");
  // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
  TCase *tcase_core = tcase_create("memcpy");

  // Добавление теста в группу тестов.
  tcase_add_test(tcase_core, memcpy_1);
  tcase_add_test(tcase_core, memcpy_2);
  tcase_add_test(tcase_core, memcpy_3);
  tcase_add_test(tcase_core, memcpy_4);
  tcase_add_test(tcase_core, memcpy_5);
  tcase_add_test(tcase_core, memcpy_6);
  tcase_add_test(tcase_core, memcpy_7);
  tcase_add_test(tcase_core, memcpy_8);
  tcase_add_test(tcase_core, memcpy_9);
  tcase_add_test(tcase_core, memcpy_10);

  // Добавление теста в тестовый набор.
  suite_add_tcase(suite, tcase_core);

  return suite;
}