#include "../unit_tests.h"

START_TEST(s21_sprintf_test_1_s) {
  char s21_str[100], str[100];
  char format[] = "test %s";
  char factor[] = "Hello!!! HAHAHA";
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_2_s) {
  char s21_str[100], str[100];
  char format[] = "test %-20s";
  char factor[] = "Hello!!! HAHAHA";
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_3_s) {
  char s21_str[100], str[100];
  char format[] = "%#2s";
  char factor[] = "Hello!!! HAHAHA";
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_4_s) {
  char s21_str[100], str[100];
  char format[] = "%-20.5s";
  char factor[] = "Hello!!! HAHAHA";
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_5_s) {
  char s21_str[100], str[100];
  char format[] = "%20.8s";
  char factor[] = "Hello!!! HAHAHA";
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_6_s) {
  char s21_str[100], str[100];
  char format[] = "%20.8s";
  char *factor = NULL;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_7_s) {
  char s21_str[100], str[100];
  char format[] = "%ls";
  wchar_t factor[] = L"DGGbvfg#34";
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_8_s) {
  char s21_str[100], str[100];
  char format[] = "%20.s";
  char factor[] = "Hello!!! HAHAHA";
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_9_s) {
  char s21_str[100], str[100];
  char format[] = "%+10.15s";
  char factor[] = "Hello!!! HAHAHA";
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_10_s) {
  char s21_str[100], str[100];
  char format[] = "% 10s";
  char factor[] = "Hello!!! HAHAHA";
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_11_s) {
  char s21_str[100], str[100];
  char format[] = "%05.7s";
  char factor[] = "Hello!!! HAHAHA";
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_1_o) {
  char s21_str[100], str[100];
  char format[] = "%-15.9o";
  int factor = 18935;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_2_o) {
  char s21_str[100], str[100];
  char format[] = "test %#o";
  int factor = 18935;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_3_o) {
  char s21_str[100], str[100];
  char format[] = "test %lo";
  int factor = 18935;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_4_o) {
  char s21_str[100], str[100];
  char format[] = "test %10o";
  int factor = 18935;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_5_o) {
  char s21_str[100], str[100];
  char format[] = "test %+3.4o";
  int factor = 18935;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_6_o) {
  char s21_str[100], str[100];
  char format[] = "test %-.10o";
  int factor = 18935;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_7_o) {
  char s21_str[100], str[100];
  char format[] = "test %010o";
  int factor = 18935;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_1_x) {
  char s21_str[100], str[100];
  char format[] = "%-15.9x";
  int factor = 18935;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_2_x) {
  char s21_str[100], str[100];
  char format[] = "%#x";
  int factor = 18935;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_1X) {
  char s21_str[100], str[100];
  char format[] = "%-15.9X";
  int factor = 18935;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_2X) {
  char s21_str[100], str[100];
  char format[] = "test %#X";
  int factor = 18935;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_1_u) {
  char s21_str[100], str[100];
  char format[] = "%-15.9u";
  int factor = 18935;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_2_u) {
  char s21_str[100], str[100];
  char format[] = "%010u";
  int factor = 18935;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_1_c) {
  char s21_str[100], str[100];
  char format[] = "%+10.5c";
  char factor = 'd';
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_2_c) {
  char s21_str[100], str[100];
  char format[] = "%-20c";
  int factor = 89;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_3_c) {
  char s21_str[100], str[100];
  char format[] = "%-0lc";
  unsigned long int factor = 18;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_1_di) {
  char s21_str[100], str[100];
  char format[] = "%d";
  int factor = 150;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_2_di) {
  char s21_str[100], str[100];
  char format[] = "%10d";
  int factor = -150;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_3_di) {
  char s21_str[100], str[100];
  char format[] = "%-.10d";
  int factor = 150;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_4_di) {
  char s21_str[100], str[100];
  char format[] = "%+10.6d";
  int factor = 150;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_5_di) {
  char s21_str[100], str[100];
  char format[] = "% d";
  int factor = 150;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_6_di) {
  char s21_str[100], str[100];
  char format[] = "%+10d";
  int factor = 150;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_7_di) {
  char s21_str[100], str[100];
  char format[] = "%05d";
  int factor = 150;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_8_di) {
  char s21_str[100], str[100];
  char format[] = "%-05d";
  int factor = 150;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_9_di) {
  char s21_str[100], str[100];
  char format[] = "%+d";
  int factor = 150;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_10_di) {
  char s21_str[100], str[100];
  char format[] = "%-9.30d";
  int factor = 150;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_11_di) {
  char s21_str[100], str[100];
  char format[] = "%ld";
  long int factor = 3088675747373646;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_12_di) {
  char s21_str[100], str[100];
  char format[] = "%hd";
  short int factor = -120;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_13_di) {
  char s21_str[100], str[100];
  char format[] = "%+.5d";
  int factor = 150;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_14_di) {
  char s21_str[100], str[100];
  char format[] = "%#0.d";
  int factor = 150;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_15_di) {
  char s21_str[100], str[100];
  char format[] = "% 10.2d";
  int factor = 150;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_16_di) {
  char s21_str[170], str[170];
  char format[] = "%*d";
  int factor1 = 150;
  int factor2 = 150;
  int s21_result = s21_sprintf(s21_str, format, factor1, factor2);
  int result = sprintf(str, format, factor1, factor2);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_17_di) {
  char str1[300];
  char str2[300];
  char *str3 = "%ld Test %ld Test %hd GOD %hd tt %d tt %d";
  long int val = LONG_MAX;
  long val2 = LONG_MIN;
  short int val3 = SHRT_MAX;
  short val4 = SHRT_MIN;
  int val5 = INT_MAX;
  int val6 = INT_MIN;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5, val6),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5, val6));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_1_f) {
  char s21_str[100], str[100];
  char format[] = "%f";
  double factor = 150.2144414151484;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_2_f) {
  char s21_str[100], str[100];
  char format[] = "% f";
  double factor = 150.2144414151484;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_3_f) {
  char s21_str[100], str[100];
  char format[] = "%25f";
  double factor = 150.2144414151484;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_4_f) {
  char s21_str[100], str[100];
  char format[] = "%.5f";
  double factor = 150.2144414151484;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_5_f) {
  char s21_str[100], str[100];
  char format[] = "%-025f";
  double factor = 150.2144414151484;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_6_f) {
  char s21_str[100], str[100];
  char format[] = "%+-25f";
  double factor = 150.2144414151484;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_7_f) {
  char s21_str[100], str[100];
  char format[] = "%.Lf";
  long double factor = -76.756589367;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_8_f) {
  char s21_str[100], str[100];
  char format[] = "%+-#.f";
  double factor = -76.756589367;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_9_f) {
  char s21_str[100], str[100];
  char format[] = "%+ 18.20f";
  double factor = -76.756589367;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_10_f) {
  char s21_str[100], str[100];
  char format[] = "%+ 18.10f";
  double factor = 365289.34628654873789362746834;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_11_f) {
  char s21_str[100], str[100];
  char format[] = "%+- 40.6f";
  double factor = 365289.346;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_12_f) {
  char s21_str[100], str[100];
  char format[] = "% +-.6Lf";
  long double factor = 000000000000000.00000000000;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_13_f) {
  char s21_str[100], str[100];
  char format[] = "% +-15.6Lf";
  long double factor = -989554542155.;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_14_f) {
  char s21_str[100], str[100];
  char format[] = "%+-10.15f";
  double factor = -0.545121578438997811;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_15_f) {
  char s21_str[100], str[100];
  char format[] = "%.3f";
  double factor = 999.999;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_16_f) {
  char s21_str[100], str[100];
  char format[] = "%8.3f";
  double factor = 999.999;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

// START_TEST(s21_sprintf_test_17_f)
// {
//     char s21_str[100], str[100];
//     char format[] = "%8.3f";
//     double factor = 999.999;
//     int s21_result = s21_sprintf(s21_str, format, factor);
//     int result = sprintf(str, format, factor);
//     ck_assert_str_eq(s21_str, str );
//     ck_assert_int_eq(s21_result, result);
// }
// END_TEST

START_TEST(s21_sprintf_test_1_percent) {
  char s21_str[100], str[100];
  char *format = "This is persent %%";
  int s21_result = s21_sprintf(s21_str, format);
  int result = sprintf(str, format, s21_NULL);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_2_percent) {
  char s21_str[100], str[100];
  char *format = "This is persent %%%%sssss";
  int s21_result = s21_sprintf(s21_str, format);
  int result = sprintf(str, format, s21_NULL);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_1_p) {
  char s21_str[100], str[100];
  char format[] = "%p";
  char factor[] = "144";
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_2_p) {
  char s21_str[100], str[100];
  char format[] = "%-0.4p";
  char factor[] = "144";
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_3_p) {
  char s21_str[100], str[100];
  char format[] = "%3.0p";
  char factor[] = "144";
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_4_p) {
  char s21_str[100], str[100];
  char format[] = "%#+-p";
  char factor[] = "144";
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_5_p) {
  char s21_str[100], str[100];
  char format[] = "% 10.10p";
  char factor[] = "144";
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_1_ge) {
  char s21_str[100], str[100];
  char format[] = "%g";
  double factor = 14;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_2_ge) {
  char s21_str[100], str[100];
  char format[] = "%Le";
  long double factor = 152154652565613.56545451215;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_3_ge) {
  char s21_str[100], str[100];
  char format[] = "%020e";
  double factor = 15215413.56545451215;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_4_ge) {
  char s21_str[100], str[100];
  char format[] = "%-.5e";
  double factor = 152113.56545451215;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_5_ge) {
  char s21_str[100], str[100];
  char format[] = "%+-12.5e";
  double factor = 15215462.56545451215;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_6_ge) {
  char s21_str[100], str[100];
  char format[] = "% 5.e";
  double factor = -15215.56545451215;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_7_ge) {
  char s21_str[100], str[100];
  char format[] = "% 5.e";
  double factor = -15215465213.56545451215;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_8_ge) {
  char s21_str[100], str[100];
  char format[] = "% 18.9e";
  double factor = -57251397732103429.56589367;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_9_ge) {
  char s21_str[100], str[100];
  char format[] = "%+-0.9e";
  double factor = -57251397732103429.56589367;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_10_ge) {
  char s21_str[100], str[100];
  char format[] = "% 018.9Le";
  long double factor = -57251397732103429.56589367;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_11_ge) {
  char s21_str[100], str[100];
  char format[] = "%g";
  double factor = 0.000000009;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_12_ge) {
  char s21_str[100], str[100];
  char format[] = "%.3g";
  double factor = 0.000000009999;
  int s21_result = s21_sprintf(s21_str, format, factor);
  int result = sprintf(str, format, factor);
  ck_assert_str_eq(s21_str, str);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_test_13_ge) {
  char str1[400], str2[400];
  char *str3 = "%.6Lg!\n%.Lg!";
  long double num = 9999.999999;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_14_ge) {
  char str1[400], str2[400];
  char *str3 = "%6.3Lg";
  long double num = 9.999;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_1_n) {
  char str1[100];
  char str2[100];
  char *str3 = "Test %o T%nest %o%n";
  int val = 012;
  int val2 = 017;
  int valn1 = 0, valn2 = 0, valn3 = 0, valn4 = 0;
  ck_assert_int_eq(sprintf(str1, str3, val, &valn1, val2, &valn3),
                   s21_sprintf(str2, str3, val, &valn2, val2, &valn4));
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(valn1, valn2);
  ck_assert_int_eq(valn3, valn4);
}
END_TEST

START_TEST(s21_sprintf_test_2_n) {
  char str1[100];
  char str2[100];
  char *str3 = "Test %o T%hnest %o%ln";
  int val = 012;
  int val2 = 017;
  short int valn1 = 0, valn2 = 0;
  long int valn3 = 0, valn4 = 0;
  ck_assert_int_eq(sprintf(str1, str3, val, &valn1, val2, &valn3),
                   s21_sprintf(str2, str3, val, &valn2, val2, &valn4));
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(valn1, valn2);
  ck_assert_int_eq(valn3, valn4);
}
END_TEST

Suite *test_sprintf(void) {
  Suite *suite = suite_create("sprintf");
  // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
  TCase *testcase = tcase_create("sprintf");

  // Добавление теста в группу тестов.
  tcase_add_test(testcase, s21_sprintf_test_1_s);
  tcase_add_test(testcase, s21_sprintf_test_2_s);
  tcase_add_test(testcase, s21_sprintf_test_3_s);
  tcase_add_test(testcase, s21_sprintf_test_4_s);
  tcase_add_test(testcase, s21_sprintf_test_5_s);
  tcase_add_test(testcase, s21_sprintf_test_6_s);
  tcase_add_test(testcase, s21_sprintf_test_7_s);
  tcase_add_test(testcase, s21_sprintf_test_8_s);
  tcase_add_test(testcase, s21_sprintf_test_9_s);
  tcase_add_test(testcase, s21_sprintf_test_10_s);
  tcase_add_test(testcase, s21_sprintf_test_11_s);

  tcase_add_test(testcase, s21_sprintf_test_1_o);
  tcase_add_test(testcase, s21_sprintf_test_2_o);
  tcase_add_test(testcase, s21_sprintf_test_3_o);
  tcase_add_test(testcase, s21_sprintf_test_4_o);
  tcase_add_test(testcase, s21_sprintf_test_5_o);
  tcase_add_test(testcase, s21_sprintf_test_6_o);
  tcase_add_test(testcase, s21_sprintf_test_7_o);

  tcase_add_test(testcase, s21_sprintf_test_1_x);
  tcase_add_test(testcase, s21_sprintf_test_2_x);

  tcase_add_test(testcase, s21_sprintf_test_1X);
  tcase_add_test(testcase, s21_sprintf_test_2X);

  tcase_add_test(testcase, s21_sprintf_test_1_u);
  tcase_add_test(testcase, s21_sprintf_test_2_u);

  tcase_add_test(testcase, s21_sprintf_test_1_c);
  tcase_add_test(testcase, s21_sprintf_test_2_c);
  tcase_add_test(testcase, s21_sprintf_test_3_c);

  tcase_add_test(testcase, s21_sprintf_test_1_di);
  tcase_add_test(testcase, s21_sprintf_test_2_di);
  tcase_add_test(testcase, s21_sprintf_test_3_di);
  tcase_add_test(testcase, s21_sprintf_test_4_di);
  tcase_add_test(testcase, s21_sprintf_test_5_di);
  tcase_add_test(testcase, s21_sprintf_test_6_di);
  tcase_add_test(testcase, s21_sprintf_test_7_di);
  tcase_add_test(testcase, s21_sprintf_test_8_di);
  tcase_add_test(testcase, s21_sprintf_test_9_di);
  tcase_add_test(testcase, s21_sprintf_test_10_di);
  tcase_add_test(testcase, s21_sprintf_test_11_di);
  tcase_add_test(testcase, s21_sprintf_test_12_di);
  tcase_add_test(testcase, s21_sprintf_test_13_di);
  tcase_add_test(testcase, s21_sprintf_test_14_di);
  tcase_add_test(testcase, s21_sprintf_test_15_di);
  tcase_add_test(testcase, s21_sprintf_test_16_di);
  tcase_add_test(testcase, s21_sprintf_test_17_di);

  tcase_add_test(testcase, s21_sprintf_test_1_f);
  tcase_add_test(testcase, s21_sprintf_test_2_f);
  tcase_add_test(testcase, s21_sprintf_test_3_f);
  tcase_add_test(testcase, s21_sprintf_test_4_f);
  tcase_add_test(testcase, s21_sprintf_test_5_f);
  tcase_add_test(testcase, s21_sprintf_test_6_f);
  tcase_add_test(testcase, s21_sprintf_test_7_f);
  tcase_add_test(testcase, s21_sprintf_test_8_f);
  tcase_add_test(testcase, s21_sprintf_test_9_f);
  tcase_add_test(testcase, s21_sprintf_test_10_f);
  tcase_add_test(testcase, s21_sprintf_test_11_f);
  tcase_add_test(testcase, s21_sprintf_test_12_f);
  tcase_add_test(testcase, s21_sprintf_test_13_f);
  tcase_add_test(testcase, s21_sprintf_test_14_f);
  tcase_add_test(testcase, s21_sprintf_test_15_f);
  tcase_add_test(testcase, s21_sprintf_test_16_f);

  tcase_add_test(testcase, s21_sprintf_test_1_percent);
  tcase_add_test(testcase, s21_sprintf_test_2_percent);

  tcase_add_test(testcase, s21_sprintf_test_1_p);
  tcase_add_test(testcase, s21_sprintf_test_2_p);
  tcase_add_test(testcase, s21_sprintf_test_3_p);
  tcase_add_test(testcase, s21_sprintf_test_4_p);
  tcase_add_test(testcase, s21_sprintf_test_5_p);

  tcase_add_test(testcase, s21_sprintf_test_1_ge);
  tcase_add_test(testcase, s21_sprintf_test_2_ge);
  tcase_add_test(testcase, s21_sprintf_test_3_ge);
  tcase_add_test(testcase, s21_sprintf_test_4_ge);
  tcase_add_test(testcase, s21_sprintf_test_5_ge);
  tcase_add_test(testcase, s21_sprintf_test_6_ge);
  tcase_add_test(testcase, s21_sprintf_test_7_ge);
  tcase_add_test(testcase, s21_sprintf_test_8_ge);
  tcase_add_test(testcase, s21_sprintf_test_9_ge);
  tcase_add_test(testcase, s21_sprintf_test_10_ge);
  tcase_add_test(testcase, s21_sprintf_test_11_ge);
  tcase_add_test(testcase, s21_sprintf_test_12_ge);
  tcase_add_test(testcase, s21_sprintf_test_13_ge);
  tcase_add_test(testcase, s21_sprintf_test_14_ge);

  tcase_add_test(testcase, s21_sprintf_test_1_n);
  tcase_add_test(testcase, s21_sprintf_test_2_n);

  // Добавление теста в тестовый набор.
  suite_add_tcase(suite, testcase);

  return suite;
}
