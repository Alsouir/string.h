#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t len_string1 = s21_strlen(src);
  s21_size_t len_string2 = s21_strlen(dest);
  for (s21_size_t i = 0; i < len_string1 && i < n; i++) {
    dest[i + len_string2] = src[i];
  }
  dest[len_string1 + len_string2] = '\0';
  return dest;
}