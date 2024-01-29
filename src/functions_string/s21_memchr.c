#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  char *result = s21_NULL;
  if (str != s21_NULL) {
    s21_size_t i = 0;
    while (i < n) {
      if (((char *)str)[i] == c) {
        result = &((char *)str)[i];
        break;
      }
      i++;
    }
  }
  return result;
}