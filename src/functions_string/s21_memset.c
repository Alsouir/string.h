#include "../s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  char *result = s21_NULL;
  if (str != s21_NULL) {
    unsigned char *s = (unsigned char *)str;
    for (s21_size_t i = 0; i < n; i++) {
      s[i] = (unsigned char)c;
    }
    result = (char *)s;
  }
  return result;
}