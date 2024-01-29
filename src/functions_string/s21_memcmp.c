#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result;
  int workResult = 0;
  if (str1 != s21_NULL && str2 != s21_NULL && n > 0) {
    const unsigned char *s1 = (const unsigned char *)str1;
    const unsigned char *s2 = (const unsigned char *)str2;
    for (s21_size_t i = 0; i < n && workResult == 0; i++) {
      if (s1[i] != s2[i]) {
        result = s1[i] - s2[i];
        workResult = 1;
      } else {
        result = 0;
      }
    }
  } else
    result = 0;
  return result;
}