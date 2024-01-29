#include "../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  for (s21_size_t i = 0; i < n; str1++, str2++, i++) {
    result = *str1 - *str2;
    if (*str1 != *str2 || !*str1 || !*str2) {
      break;
    }
  }
  return result;
}